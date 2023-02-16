<?php
/**
 * Implements hook_html_head_alter().
 * We are overwriting the default meta character type tag with HTML5 version.
 */
function atdove_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

/**
 * Implements hook_page_alter().
 */
function atdove_page_alter(&$page) {
  // If user is anonymous and current path is home page,
  // redirect to AtDove marketing WordPress site.
  if (user_is_anonymous() && drupal_is_front_page()) {
    //drupal_goto('https://go.atdove.org/');
  }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function atdove_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $heading = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // Uncomment to add current page to breadcrumb
	// $breadcrumb[] = drupal_get_title();
    return '<nav class="breadcrumb">' . $heading . implode(' » ', $breadcrumb) . '</nav>';
  }
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function atdove_menu_local_tasks(&$variables) {
  Global $user;
  // don't show local tasks menu for most user facing pages
  if (!in_array('administrator', array_values($user->roles))
      && !in_array('Content Admin', array_values($user->roles))
      && !in_array('Billing Admin', array_values($user->roles))) {
    if (arg(0) !== 'people' && arg(1) !== 'login' && arg(0) !== 'help-center') {
      unset($variables['primary']);
    }
  }
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

/**
 * Override or insert variables into the node template.
 */
function atdove_preprocess_node(&$variables, &$vars) {
  // prevent view of certain content types
  $node = $variables['node'];
  switch ($node->type) {
    case 'assignment':
    case 'training_plan':
      unset($_GET['destination']);
      drupal_goto('node/' . $node->nid . '/edit', array(), 301);
      break;
    case 'quiz':
      unset($variables['content']['links']['statistics']['#links']['statistics_counter']['title']);
  }

  $variables['submitted'] = t('Published by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['date']));
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
  //add view count data
  $stats = statistics_get($variables['nid']);
  $variables['viewcount'] = $stats['totalcount'];

    if (isset($variables['view_mode'])) {
        $variables['theme_hook_suggestions'][] = 'node__'. $variables['node']->type . '__' . $variables['view_mode'];
    }

  //If this is shareable content, add the addthis javascript.
  if( in_array( $variables['type'], array("article","blog","video") ) ) {
    drupal_add_js('https://s7.addthis.com/js/300/addthis_widget.js#pubid=ra-57311c57e24d0e04', 'external','footer');
  }
}

/**
 * Preprocess variables for region.tpl.php
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
function atdove_preprocess_region(&$variables, $hook) {
  // Use a bare template for the content region.
  if ($variables['region'] == 'content') {
    $variables['theme_hook_suggestions'][] = 'region__bare';
  }
}

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function atdove_preprocess_block(&$variables, $hook) {
  // Use a bare template for the page's main content.
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'][] = 'block__bare';
  }
  if (!empty($variables['block'])) {
    $variables['theme_hook_suggestions'][] = 'block__' . $variables['block']->module . '__' . strtr($variables['block']->delta, '-', '_');
  }
  $variables['title_attributes_array']['class'][] = 'block-title';
}

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function atdove_process_block(&$variables, $hook) {
  // Drupal 7 should use a $title variable instead of $block->subject.
  if (!empty($variables['block'])) {
    $variables['title'] = $variables['block']->subject;
  }
}

/**
 * Changes the search form to use the "search" input element of HTML5.
 */
function atdove_preprocess_search_block_form(&$vars) {
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

//////////////////////////////////////////////////////////

function atdove_preprocess_page(&$vars, $hook) {
    Global $user;
    if (function_exists('dl_assignments_user_has_incomplete_assignments')) {$vars['assignmentNotification'] = dl_assignments_user_has_incomplete_assignments($user->uid);}
    if (function_exists('dl_billing_management_is_billing_page')) {$vars['isBillingPage'] = dl_billing_management_is_billing_page(drupal_get_path_alias());}
    //Allows .tpl overrides by content types.
    if (isset($vars['node']->type)) {
        $vars['theme_hook_suggestions'][] = 'page__'. $vars['node']->type;
    }

    //This is so we can print the user video node object in page.tpl
    $vars['VAR_NAME'] = '';
    if (($node = menu_get_object()) && $node->type == 'video') {
      $view = node_view($node);
      //different videos for different roles
      //If user has a current subscription.

      if (in_array('Subscriber', array_values($user->roles))) {
        $vars['accessible_video'] = drupal_render($view['field_wistia_iframe_logged_in_ac']);
      }
      //If they are logged in
      elseif(in_array('authenticated user', array_values($user->roles))){
        $vars['accessible_video'] = drupal_render($view['field_wistia_iframe_logged_in_no']);
        $vars['poster_fix'] = drupal_render($view['field_wistia_iframe_logged_in_ac']); // used in page.tpl to render poster
      }
      //Otherwise Anon
      else{
        $vars['accessible_video'] = drupal_render($view['field_wistia_iframe_logged_in_no']);
        $vars['poster_fix'] = drupal_render($view['field_wistia_iframe_logged_in_ac']); // used in page.tpl to render poster
      }
    }

    if (($node = menu_get_object()) && $node->type) {
      //add view count data
      $stats = statistics_get($vars['node']->nid);
      $vars['viewcount'] = $stats['totalcount'];
      $vars['Page_Main_Image'] = drupal_render($view['field_blog_image']);
    }

    // add redirects for legacy content types
    $alias_parts = explode('/', drupal_get_path_alias());
    if (count($alias_parts) > 1) {
      switch ($alias_parts[0]) {
        case 'articles':
          unset($_GET['destination']);
          drupal_goto('article/' . end($alias_parts), array(), 301);
          break;
        case 'blog':
          if (count($alias_parts) > 2) {
            unset($_GET['destination']);
            drupal_goto('blog/' . end($alias_parts), array(), 301);
          }
          break;
        case 'videos':
          unset($_GET['destination']);
          drupal_goto('video/' . end($alias_parts), array(), 301);
          break;
        case 'help':
          unset($_GET['destination']);
          drupal_goto('help-topic/' . end($alias_parts), array(), 301);
          break;
        case 'user':
          if (end($alias_parts) == 'register') {
            unset($_GET['destination']);
            drupal_goto('future-billing', array(), 301);
          }
          break;
        case 'my-organization':
          $group_admin = organization_control_is_any_admin($user->uid);
          $valid_user = in_array('administrator', array_values($user->roles)) || $group_admin;
          if (!$valid_user && $alias_parts[1] == 'organization' && $alias_parts[2] == 'manage') {
            unset($_GET['destination']);
            drupal_goto('/', array(), 301);
          }
      }
    }
    else {
      switch ($alias_parts[0]) {
        case 'article':
          unset($_GET['destination']);
          drupal_goto('all', array('query' => array('type_1[0]' => 'article')), 301);
          break;
        case 'video':
          unset($_GET['destination']);
          drupal_goto('all', array('query' => array('type_1[0]' => 'video')), 301);
          break;
      }
    }

    //Show theme hook suggestions on page
    //echo '<pre>'; var_dump($vars['theme_hook_suggestions']); echo '</pre>';
    //echo '<pre>'; var_dump($vars); echo '</pre>';

}

//////////////////////////////////////////////////////////

function atdove_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    //$form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
    //$form['actions']['submit']['#value'] = t('GO!'); // Change the text on the submit button
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme('atdove') . '/images/magnifying-glass.png');
    $form['search_block_form']['#attributes'] = array('placeholder' => t('Search'));
  }
  elseif ($form_id == 'user_login') {
    //$form['#prefix'] = "<h2 class='login-welcome'>Scrub In</h2>";
    $form['name']['#title'] = "E-Mail Address";
    $form['name']['#description'] = "";
    $form['pass']['#description'] = "The password is case sensitive. Click <a href='/user/password'>here</a> to request a new password or <a href='/contact-us'>contact us</a> for assistance.";
    $form['#attributes']['class'] = 'login-form';
  }
  elseif ($form_id == 'organization_node_form') {
    $form['atdove_message']['#markup'] = "<br><p>Think of your team profile as a business listing and benefit from our search engine optimization (SEO). This page is visible to the public. Our SEO is highly developed and benefits from a google grant. Consumers searching for vets in your area or specific conditions of their pets can find you through our site. Upload your logo, web address and other business information and give your clients the added value of a staff kept current with training atdove.org.​</p>";
    $form['atdove_message']['#weight'] = -100;
    global $user;
    if (!in_array('administrator', array_values($user->roles))) {
      $form['field_notes']['#access'] = 0;
      $form['field_allow_import_team_manageme']['#access'] = 0;
      $form['field_openid_client_id']['#access'] = 0;
      $form['field_allow_employeeid']['#access'] = 0;
      $form['field_clinic_url']['#access'] = 0;
      $form['field_sponsor_name']['#access'] = 0;
      $form['body']['und'][0]['#title'] = t('About Us');
      $form['body']['#title_display'] = 'invisible';
    }
  }
  elseif($form_id == 'commerce_cardonfile_card_form'){
    $form['header']['#markup'] = "<h1>Update Billing Information</h1>";
    $form['commerce_customer_profile']['field_buyer_title']['#access'] = 0;
    $form['commerce_customer_profile']['field_heard_about_us_from']['und']['#required'] = false;
    $form['commerce_customer_profile']['field_heard_about_us_from']['#access'] = 0;
    $form['commerce_customer_profile']['field_phone']['#access'] = 0;
    $form['body']['#markup'] = "<br><!-- (c) 2005, 2016. Authorize.Net is a registered trademark of CyberSource Corporation --> <div class=\"AuthorizeNetSeal\"> <script type=\"text/javascript\" language=\"javascript\">var ANS_customer_id=\"3ddda44a-5e5a-4906-badb-ad7b843af6a0\";</script> <script type=\"text/javascript\" language=\"javascript\" src=\"//verify.authorize.net/anetseal/seal.js\" ></script> <a href=\"http://www.authorize.net/\" id=\"AuthorizeNetText\" target=\"_blank\">Merchant Services</a> </div>";
  }
}

//////////////////////////////////////////////////////////

//function atdove() {
//    $items = array();
//        // create custom user-login.tpl.php
//        $items['user_login'] = array(
//            'render element' => 'form',
//            'path' => drupal_get_path('theme', 'atdove'),
//            'template' => 'user-login',
//            'preprocess functions' => array(
//            'atdove_preprocess_user_login'
//        ),
//    );
//    return $items;
//}

/*
 * This adds a class to authenicated users that queue different UI features based on role
 */
function atdove_preprocess_html(&$vars) {
  if (user_is_logged_in() && module_exists('organization_control')) {
    global $user;
    $subscriberRoleCheck = organization_control_user_has_role('Subscriber', $user);
    if ($subscriberRoleCheck && organization_control_is_any_admin($user->uid)) {
      $vars['classes_array'][] = "activeAdmin";
    }
    //confirm subscription
    elseif ($subscriberRoleCheck) {
      $vars['classes_array'][] = "activeMember";
    }
    else {
      $vars['classes_array'][] = "inactive";
    }
  }
  else {
    $vars['classes_array'][] = "nonMember";
  }

  $alias_parts = explode('/', drupal_get_path_alias());
  if (count($alias_parts) > 1) {
    switch ($alias_parts[0]) {
      case 'checkout':
        if (end($alias_parts) == 'complete') {
          Global $user;
          $order = commerce_order_load($alias_parts[1]);
          $org = organization_control_orgID($user);
          $org_name = organization_control_orgName($org);
          $prod = organization_control_subscription_info($user);
          $cost = $order->commerce_order_total['und'][0]['amount'];
          $vars['ga_order'] = $order->order_id;
          $vars['ga_org'] = $org;
          $vars['ga_org_name'] = $org_name;
          $vars['ga_prod_name'] = $prod['field_total_seats_value'];
          $vars['ga_prod_cost'] = $cost / 100;
        }
    }
  }


  // $body_classes = array($vars['classes_array']);
//   if ($vars['user']) {
//     foreach($vars['user']->roles as $key => $role){
//       $role_class = 'role-' . str_replace(' ', '-', $role);
//       $vars['attributes_array']['class'][] = $role_class;
//     }
//   }
}

function atdove_username_alter(&$name, $account) {
  if (isset($account->uid)) {
    $user = user_load($account->uid);
    if (isset($user->uid)) {
      $name = '';
    }
    if (isset($user->field_first_name['und'][0])) {
      $name .= $user->field_first_name['und'][0]['value'] . ' ';
    }
    if (isset($user->field_last_name['und'][0])) {
      $name .= $user->field_last_name['und'][0]['value'];
    }
    if (strlen($name) < 1) {
      $name = $user->name;
    }
  }
}

function atdove_quiz_question_navigation_form($variables) { // changing the order of the form elements on last quiz question.
  $form = $variables['form'];
  if (!isset($form['#last'])) {
    return drupal_render_children($form);
  }
  else {
    $submit = drupal_render($form['submit']) . drupal_render($form['op']);
    $to_return = '<p class="last-question-message">' . t('This is the last question. Press Finish to deliver your answers') . '</p>';
    $to_return .= drupal_render_children($form);
    $to_return .= $submit;
    return $to_return;
  }
}

/**
* Implements theme_menu_link().
* Adds user image and classes to user-menu
*/
function atdove_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  global $user;
  $user = user_load($user->uid);
  $user_name = '';
  if (isset($user->field_first_name['und'][0]['value'])) {
    $user_name = $user->field_first_name['und'][0]['value'] . ' ' . $user->field_last_name['und'][0]['value'];
  }
  $output = l(decode_entities($element['#title']), $element['#href'], $element['#localized_options']);
  $image_classes = '';

  if (isset($element['#title']) && (decode_entities($element['#title']) == $user_name || decode_entities($element['#title']) == $user->name)) {
    $element['#localized_options']['html'] = 1;

    if (isset($user->picture->uri)) { // trapping notices for users with no picture
      $image = theme_image_style(
        array(
          'style_name' => 'medium',
          'path' => $user->picture->uri,
          'attributes' => array(
            'class' => 'avatar'
          ),
          'width' => NULL,
          'height' => NULL,
        )
      );
      $image_classes = '<div class="user-menu-user-image">' . $image . '</div>';
    }
  }

  return $image_classes . '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Pull node vars to display in search results
 *
 */
function atdove_preprocess_search_result(&$vars, $hook) {
  $node = $vars['result']['node'];
  if(isset($node->field_image['und'][0]['uri'])){
    if (file_exists($node->field_image['und'][0]['uri'])) {
      $content_img = theme('image_style', array(
        'style_name' => 'thumbnail',
        'path' => $node->field_image['und'][0]['uri'],
        'getsize' => TRUE,
        'attributes' => array('class' => 'search-thumb')));
    }
    else {
      $content_img = "&nbsp;";
    }
  }
  else {
    $content_img = "&nbsp;";
  }
  $vars['content_img'] = $content_img;
  $vars['content_node_type'] = $node->type;
}
