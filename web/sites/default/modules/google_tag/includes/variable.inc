<?php

/**
 * @file
 * Contains the variable definitions.
 *
 * @author Jim Berry ("solotandem", http://drupal.org/user/240748)
 */

/**
 * Implements hook_variable_group_info().
 */
function _google_tag_variable_group_info() {
  $groups['google_tag'] = array(
    'title' => t('Google Tag Manager'),
    'description' => t('Allows your website analytics to be managed using Google Tag Manager.'),
    'access' => 'administer google tag manager',
    'path' => array('admin/config/system/google_tag'),
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info($options) {
  // Gather data.
  $groups = array('general', 'advanced', 'path', 'role', 'status', 'settings', 'internal');
  $common = array(
    'group' => 'google_tag',
    'localize' => TRUE,
    'multidomain' => TRUE,
  );

  // Build variables.
  $variables = array();
  foreach ($groups as $group) {
    $function = "_google_tag_variable_info_$group";
    $variables += $function($options);
  }
  foreach ($variables as $key => $variable) {
    $variables[$key] += $common;
  }
  if (!empty($options['use_prefix'])) {
    // Deal with schema 7200 version change.
    $retro = array();
    foreach ($variables as $key => $variable) {
      $retro["google_tag_$key"] = $variable;
    }
    $variables = $retro;
  }

  return $variables;
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_general($options) {
  // Gather data.
  $args = array('@path' => 'https://tagmanager.google.com/');
  $description = t('The ID assigned by Google Tag Manager (GTM) for this website container. To get a container ID, <a href="@path">sign up for GTM</a> and create a container for your website.', $args, $options);

  // Build variables.
  $variables['container_id'] = array(
    'type' => 'string',
    'title' => t('Container ID', array(), $options),
    'description' => $description,
    'default' => '',
    'validate callback' => '_google_tag_validate_container_id',
    'element' => array(
      '#attributes' => array('placeholder' => array('GTM-xxxxxx')),
      '#size' => 12,
      '#maxlength' => 15,
      '#required' => TRUE,
    ),
  );

  $variables['weight'] = array(
    'type' => 'select',
    'type' => 'weight',
    'title' => t('Weight', array(), $options),
    'default' => 1,
  );

  return $variables;
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_path($options) {
  $args = array(
    '%node' => '/node',
    '%user-wildcard' => '/user/*',
    '%front' => '<front>',
  );
  $description = t('Enter one relative path per line using the "*" character as a wildcard. Example paths are: "%node" for the node page, "%user-wildcard" for each individual user, and "%front" for the front page.', $args, $options);
  $default = GOOGLE_TAG_PATHS;
  $rows = 10;

  $toggle = 'path_toggle';
  $list = 'path_list';
  $plural = 'paths';
  $adjective = 'listed';
  $config = compact(array('toggle', 'list', 'plural', 'adjective', 'description', 'default', 'rows'));
  return _google_tag_variable_info_generic($config, $options);
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_role($options) {
  global $language;

  // Set language code to default to prevent role names from being translated.
  // Use role name in default language as array key as this matches the values
  // attached to global user object (used when evaluating role condition). Set
  // display value to translated role name.
  // @todo This points out core would benefit from a $translate parameter to
  // user_roles() to indicate whether to translate the role names. This would be
  // used on the role and permission listing pages to consistently translate all
  // roles not just the anonymous and authenticated roles.
  $language_keep = $language->language;
  $language->language = 'en';
  $options = user_roles();
  $language->language = $language_keep;
  foreach ($options as $rid => $role) {
    // Set display value to translated role name.
    $options[$role] = t($role);
    unset($options[$rid]);
  }

  $toggle = 'role_toggle';
  $list = 'role_list';
  $plural = 'roles';
  $config = compact(array('toggle', 'list', 'plural', 'options'));
  return _google_tag_variable_info_generic($config, $options);
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_status($options) {
  $args = array('@path' => 'http://en.wikipedia.org/wiki/List_of_HTTP_status_codes');
  $description = t('Enter one response status per line. For more information, refer to the <a href="@path">list of HTTP status codes</a>.', $args, $options);
  $default = GOOGLE_TAG_STATUSES;
  $rows = 5;

  $toggle = 'status_toggle';
  $list = 'status_list';
  $plural = 'statuses';
  $adjective = 'listed';
  $config = compact(array('toggle', 'list', 'plural', 'adjective', 'description', 'default', 'rows'));
  return _google_tag_variable_info_generic($config, $options);
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_realm($options) {
  // @todo Does google_tag_condition_filter() obviate this gate check?
  if (!module_exists('variable_realm') || !module_exists('variable_store')) {
    return array();
  }

  $options = array();
  $realms = variable_realm_list();
  foreach ($realms as $realm_name => $realm_title) {
    $keys = variable_realm_keys($realm_name);
    foreach ($keys as $key_name => $key_title) {
      $options["$realm_name:$key_name"] = "$realm_name:$key_name";
    }
  }
  $toggle = 'realm_toggle';
  $list = 'realm_list';
  $plural = 'keys';
  $config = compact(array('toggle', 'list', 'plural', 'options'));
  return _google_tag_variable_info_generic($config, $options);
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_domain($options) {
  // @todo Does google_tag_condition_filter() obviate this gate check?
  if (!module_exists('domain')) {
    return array();
  }

  $options = array();
  foreach (domain_domains() as $key => $value) {
    $options[$value['machine_name']] = $value['sitename'];
  }
  $toggle = 'domain_toggle';
  $list = 'domain_list';
  $plural = 'domains';
  $config = compact(array('toggle', 'list', 'plural', 'options'));
  return _google_tag_variable_info_generic($config, $options);
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_language($options) {
  // @todo Does google_tag_condition_filter() obviate this gate check?
  if (!module_exists('locale')) {
    return array();
  }

  $toggle = 'language_toggle';
  $list = 'language_list';
  $plural = 'languages';
  $options = locale_language_list();
  $config = compact(array('toggle', 'list', 'plural', 'options'));
  return _google_tag_variable_info_generic($config, $options);
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_generic($config, $options) {
  // Gather data.
  $config += array('adjective' => 'selected', 'element' => 'options');
  extract($config);
  $args = array(
    '@adjective' => $adjective,
    '@uc_adjective' => ucfirst($adjective),
    '@plural' => $plural,
  );

  // Build variables.
  $variables[$toggle] = array(
    'type' => 'select',
    'title' => special_t('Insert snippet for specific @plural', $args, $options),
    'options' => array(
      GOOGLE_TAG_EXCLUDE_LISTED => special_t('All @plural except the @adjective @plural', $args, $options),
      GOOGLE_TAG_INCLUDE_LISTED => special_t('Only the @adjective @plural', $args, $options),
    ),
    'default' => GOOGLE_TAG_EXCLUDE_LISTED,
  );

  if ($adjective == 'selected') {
    $variables[$list] = array(
      'type' => 'options',
      'title' => special_t('@uc_adjective @plural', $args, $options),
      'default' => array(),
      'options' => $options,
    );
  }
  else {
    $variables[$list] = array(
      'type' => 'text',
      'title' => special_t('@uc_adjective @plural', $args, $options),
      'description' => $description,
      'default' => $default,
      'validate callback' => '_google_tag_validate_text',
      'element' => array(
        '#rows' => $rows,
      ),
    );
  }

  return $variables;
}

/**
 * Returns a translated string after placeholder substitution.
 *
 * @param string $string
 *   The string to manipulate.
 *
 * @return string
 *   The translated string.
 */
function special_t($string, $args) {
  return t(strtr($string, $args));
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_advanced($options) {
  // Gather data.
  $args = array('@path' => 'https://developers.google.com/tag-manager/devguide#security');
  $description = t('The types of tags, triggers, and variables <strong>allowed</strong> on a page. Enter one class per line. For more information, refer to the <a href="@path">developer documentation</a>.', $args, $options);

  $args = array('@path' => 'https://www.drupal.org/project/datalayer');
  $markup = t('If the default data layer name is used, then enable the <a href="@path">data layer</a> module to manage the insertion of tags, triggers, and variables in one place. If a different module is used for this purpose, there may be some contamination and override of values from this and the other module.', $args, $options);

  $args = array('@path' => 'https://tagmanager.google.com/#/admin');
  $description2 = t('The environment ID to use with this website container. To get an environment ID, <a href="@path">select Environments</a>, create an environment, then click the "Get Snippet" action. The environment ID and token will be in the snippet.', $args, $options);

  // Build variables.
  $disabled = !module_exists('datalayer');

  $variables['data_layer'] = array(
    'type' => 'string',
    'title' => t('Data layer', array(), $options),
    'description' => t('The name of the data layer. Default value is "dataLayer". In most cases, use the default.', array(), $options),
    'default' => 'dataLayer',
    'validate callback' => '_google_tag_validate_data_layer',
    'element' => array(
      '#attributes' => array('placeholder' => array('dataLayer')),
      '#required' => TRUE,
      '#prefix' => $disabled ? '<span>' . $markup . '</span>' : '',
    ),
  );

  $variables['include_classes'] = array(
    'type' => 'boolean',
    'title' => t('Add classes to the data layer', array(), $options),
    'description' => t('If checked, then the listed classes will be added to the data layer.', array(), $options),
    'default' => 0,
    'validate callback' => '_google_tag_validate_listed_classes',
  );

  $variables['whitelist_classes'] = array(
    'type' => 'text',
    'title' => t('White-listed classes', array(), $options),
    'description' => $description,
    'default' => GOOGLE_TAG_WHITELIST_CLASSES,
    'validate callback' => '_google_tag_validate_text',
    'element' => array(
      '#rows' => 5,
      '#states' => _google_tag_variable_states('include_classes'),
    ),
  );

  $variables['blacklist_classes'] = array(
    'type' => 'text',
    'title' => t('Black-listed classes', array(), $options),
    'description' => t('The types of tags, triggers, and variables <strong>forbidden</strong> on a page. Enter one class per line.', array(), $options),
    'default' => GOOGLE_TAG_BLACKLIST_CLASSES,
    'validate callback' => '_google_tag_validate_text',
    'element' => array(
      '#rows' => 5,
      '#states' => _google_tag_variable_states('include_classes'),
    ),
  );

  $variables['include_environment'] = array(
    'type' => 'boolean',
    'title' => t('Include an environment', array(), $options),
    'description' => t('If checked, then the applicable snippets will include the environment items below. Enable <strong>only for development</strong> purposes.', array(), $options),
    'default' => 0,
  );

  $variables['environment_id'] = array(
    'type' => 'string',
    'title' => t('Environment ID', array(), $options),
    'description' => $description2,
    'default' => '',
    'validate callback' => '_google_tag_validate_environment_id',
    'element' => array(
      '#attributes' => array('placeholder' => array('env-x')),
      '#size' => 10,
      '#maxlength' => 7,
      '#states' => _google_tag_variable_states('include_environment'),
    ),
  );

  $variables['environment_token'] = array(
    'type' => 'string',
    'title' => t('Environment token', array(), $options),
    'description' => t('The authentication token for this environment.', array(), $options),
    'default' => '',
    'element' => array(
      '#attributes' => array('placeholder' => array('xxxxxxxxxxxxxxxxxxxxxx')),
      '#size' => 20,
      '#maxlength' => 25,
      '#states' => _google_tag_variable_states('include_environment'),
    ),
  );

  return $variables;
}

/**
 * Implements hook_variable_info().
 */
function _google_tag_variable_info_settings($options) {
  // Build variables.
  $variables['uri'] = array(
    'type' => 'string',
    'title' => t('Snippet parent URI'),
    'description' => t('The parent URI for saving snippet files. Snippet files will be saved to "[uri]/google_tag". Enter a plain stream wrapper with a single trailing slash like "public:/".', array(), $options),
    'default' => 'public:/',
    'validate callback' => '_google_tag_validate_uri',
    'element' => array(
      '#attributes' => array('placeholder' => array('public:/')),
      '#required' => TRUE,
    ),
  );

  $variables['compact_snippet'] = array(
    'type' => 'boolean',
    'title' => t('Compact the JavaScript snippet', array(), $options),
    'description' => t('If checked, then the JavaScript snippet will be compacted to remove unnecessary whitespace. This is <strong>recommended on production sites</strong>. Leave unchecked to output a snippet that can be examined using a JavaScript debugger in the browser.', array(), $options),
    'default' => 1,
  );

  $variables['include_file'] = array(
    'type' => 'boolean',
    'title' => t('Include the snippet as a file', array(), $options),
    'description' => t('If checked, then each JavaScript snippet will be included as a file. This is <strong>recommended</strong>. Leave unchecked to inline each snippet into the page. This only applies to data layer and script snippets.', array(), $options),
    'default' => 1,
  );

  $variables['rebuild_snippets'] = array(
    'type' => 'boolean',
    'title' => t('Recreate snippets on cache rebuild'),
    'description' => t('If checked, then the JavaScript snippet files will be created during a cache rebuild. This is <strong>recommended on production sites</strong>.', array(), $options),
    'default' => 1,
  );

  $variables['flush_snippets'] = array(
    'type' => 'boolean',
    'title' => t('Flush snippet directory on cache rebuild'),
    'description' => t('If checked, then the snippet directory will be deleted and recreated during a cache rebuild. If not checked, then manual intervention may be required to tidy up the snippet directory (e.g. remove snippet files for a deleted container).', array(), $options),
    'default' => 0,
  );

  $variables['debug_output'] = array(
    'type' => 'boolean',
    'title' => t('Show debug output', array(), $options),
    'description' => t('If checked, then the result of each snippet insertion condition will be shown in the message area. Enable <strong>only for development</strong> purposes.', array(), $options),
    'default' => 0,
  );

  return $variables;
}

/**
 * Implements hook_variable_info().
 * @deprecated
 */
function _google_tag_variable_info_internal($options) {
  // Gather data.
  $args = array('@path' => 'admin/config/system/variable/realm/language/configure');
  $markup = t('<strong>NOTE</strong>: If using the dataLayer module to insert these values and variable realms are in effect, then <a href="@path">check this item to be realm-specific</a>.', $args, $options);

  // Build variables.
  $visible = module_exists('datalayer') && module_exists('variable_realm');

  $variables['data_layer_classes'] = array(
    'type' => 'properties',
    'title' => t('Data layer classes', array(), $options),
    'description' => t('The associative array of data layer classes. <strong>NOTE: If using the dataLayer module to insert these values and variable realms are in effect, then check this item.</strong>', array(), $options),
    'default' => array(),
    'element' => array(
      // '#prefix' => $visible ? '<span>' . $markup . '</span>' : '',
      '#attributes' => array('class' => array('element-invisible')),
    ),
  );

  return $variables;
}

/**
 * Returns states array for a form element.
 *
 * @param string $variable
 *   The name of the form element.
 *
 * @return array
 *   The states array.
 */
function _google_tag_variable_states($variable) {
  return array(
    'required' => array(
      ':input[name="' . $variable . '"]' => array('checked' => TRUE),
    ),
    'invisible' => array(
      ':input[name="' . $variable . '"]' => array('checked' => FALSE),
    ),
  );
}

/**
 * Element validation handler for google_tag_container_id.
 *
 * @todo This may suffice for all the elements as only the container_id has an
 *   error message. Error messages could be done for other elements by calling
 *   form_set_error('element[name]', $message).
 */
function _google_tag_validate_container_id($variable, $options, $element, $form, &$form_state) {
  // Use this routine as the variable realm form has nested values.
  $value = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  // Trim the text value.
  $value = trim($value);
  // Replace all types of dashes (n-dash, m-dash, minus) with a normal dash.
  $value = str_replace(array('???', '???', '???'), '-', $value);
  // Replace the text value.
  drupal_array_set_nested_value($form_state['values'], $element['#parents'], $value);

  if (!preg_match('/^GTM-\w{4,}$/', $value)) {
    // @todo Is there a more specific regular expression that applies?
    // @todo Is there a way to "test the connection" to determine a valid ID for
    // a container? It may be valid but not the correct one for the website.
    return t('A valid container ID is case sensitive and formatted like GTM-xxxxxx.');
  }
}

/**
 * Element validation handler for google_tag_environment_id.
 */
function _google_tag_validate_environment_id($variable, $options, $element, $form, &$form_state) {
  // @todo This will not prevent checking 'include_environment' on an individual
  // variable edit form and never setting the 'environment_id'.
  $parents = $element['#parents'];
  array_pop($parents);
  $parents[] = 'include_environment';
  $include_environment = drupal_array_get_nested_value($form_state['values'], $parents);

  $value = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  $value = trim($value);
  $value = str_replace(array('???', '???', '???'), '-', $value);
  drupal_array_set_nested_value($form_state['values'], $element['#parents'], $value);

  if ($include_environment && !preg_match('/^env-\d{1,}$/', $value)) {
    return t('A valid environment ID is case sensitive and formatted like env-x.');
  }
}

/**
 * Element validation handler for google_tag_data_layer.
 */
function _google_tag_validate_data_layer($variable, $options, $element, $form, &$form_state) {
  $value = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  $value = trim($value);
  drupal_array_set_nested_value($form_state['values'], $element['#parents'], $value);
  return _google_tag_data_layer_verify($value);
}

/**
 * Element validation handler for google_tag_listed_classes.
 */
function _google_tag_validate_listed_classes($variable, $options, $element, $form, &$form_state) {
  if (!drupal_array_get_nested_value($form_state['values'], $element['#parents'])) {
    return;
  }

  $keys = array('whitelist_classes', 'blacklist_classes');
  $variables = isset($form['#variable_edit_form']) ? $form['#variable_edit_form'] : array();
  $items = array_diff($keys, $variables);
  if (!empty($items)) {
    // Need both variables on form to validate.
    form_set_error('include_classes', t('To validate listed classes, include the whitelist and blacklist variables in the realm variables.'));
    return;
  }

  $empty = TRUE;
  foreach ($keys as $key) {
    array_pop($element['#parents']);
    $element['#parents'][] = $key;
    $classes = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
    google_tag_text_clean($classes);
    $empty &= empty($classes);
  }
  if ($empty) {
    form_set_error('include_classes', t('Enter listed classes in at least one field, or uncheck the box.'));
    form_set_error('whitelist_classes', '');
    form_set_error('blacklist_classes', '');
  }
}

/**
 * Element validation handler for text values.
 */
function _google_tag_validate_text($variable, $options, $element, $form, &$form_state) {
  $value = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  google_tag_text_clean($value);
  drupal_array_set_nested_value($form_state['values'], $element['#parents'], $value);
}
