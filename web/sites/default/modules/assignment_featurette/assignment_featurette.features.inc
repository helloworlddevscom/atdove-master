<?php
/**
 * @file
 * assignment_featurette.features.inc
 */

/**
 * Implements hook_views_api().
 */
function assignment_featurette_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function assignment_featurette_node_info() {
  $items = array(
    'assignment' => array(
      'name' => t('Assignment'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
