<?php
/**
 * @file
 * subsciption_pages_featurette.features.inc
 */

/**
 * Implements hook_node_info().
 */
function subsciption_pages_featurette_node_info() {
  $items = array(
    'subscription' => array(
      'name' => t('Subscription'),
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
