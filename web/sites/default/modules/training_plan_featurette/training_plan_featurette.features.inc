<?php
/**
 * @file
 * training_plan_featurette.features.inc
 */

/**
 * Implements hook_node_info().
 */
function training_plan_featurette_node_info() {
  $items = array(
    'training_plan' => array(
      'name' => t('Training Plan'),
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
