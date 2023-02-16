<?php
/**
 * @file
 * benefits_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function benefits_page_node_info() {
  $items = array(
    'benefits_page' => array(
      'name' => t('Benefits Page'),
      'base' => 'node_content',
      'description' => t('These two pages are used for the user funnel pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
