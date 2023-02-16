<?php
/**
 * @file
 * landing_page_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function landing_page_content_type_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('little landing pages for campaigns'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
