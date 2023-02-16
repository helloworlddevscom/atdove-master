<?php
/**
 * @file
 * news_room_piece.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function news_room_piece_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_article_link'.
  $field_bases['field_article_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_article_link',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 800,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_news_room_file'.
  $field_bases['field_news_room_file'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_news_room_file',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
