<?php
/**
 * @file
 * announcement_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function announcement_content_type_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'base' => 'node_content',
      'description' => t('Announcements'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
