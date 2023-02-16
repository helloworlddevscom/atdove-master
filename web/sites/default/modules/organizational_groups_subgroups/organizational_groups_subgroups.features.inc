<?php
/**
 * @file
 * organizational_groups_subgroups.features.inc
 */

/**
 * Implements hook_node_info().
 */
function organizational_groups_subgroups_node_info() {
  $items = array(
    'organizational_groups' => array(
      'name' => t('Organizational Groups'),
      'base' => 'node_content',
      'description' => t('Subgroups for Oraganizations'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
