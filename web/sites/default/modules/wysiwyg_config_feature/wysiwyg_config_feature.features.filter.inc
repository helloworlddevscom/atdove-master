<?php
/**
 * @file
 * wysiwyg_config_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function wysiwyg_config_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML - Content Editor.
  $formats['filtered_html_content_editor'] = array(
    'format' => 'filtered_html_content_editor',
    'name' => 'Filtered HTML - Content Editor',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -6,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML - No WYSWYG.
  $formats['full_html_no_wyswyg'] = array(
    'format' => 'full_html_no_wyswyg',
    'name' => 'Full HTML - No WYSWYG',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(),
  );

  return $formats;
}
