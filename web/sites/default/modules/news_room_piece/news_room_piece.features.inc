<?php
/**
 * @file
 * news_room_piece.features.inc
 */

/**
 * Implements hook_node_info().
 */
function news_room_piece_node_info() {
  $items = array(
    'news_room' => array(
      'name' => t('News Room'),
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
