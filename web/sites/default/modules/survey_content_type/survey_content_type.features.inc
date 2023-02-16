<?php
/**
 * @file
 * survey_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function survey_content_type_node_info() {
  $items = array(
    'survey' => array(
      'name' => t('Survey'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Survey'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
