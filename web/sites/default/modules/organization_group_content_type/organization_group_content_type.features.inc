<?php
/**
 * @file
 * organization_group_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function organization_group_content_type_node_info() {
  $items = array(
    'organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Update Team Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
