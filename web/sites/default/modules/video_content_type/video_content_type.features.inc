<?php
/**
 * @file
 * video_content_type.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function video_content_type_default_cer() {
  $items = array();
  $items['node:video:field_related_ads*node:ad:field_related_videos'] = entity_import('cer', '{
    "identifier" : "node:video:field_related_ads*node:ad:field_related_videos",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:video:field_related_ads" } ] },
    "cer_right" : { "und" : [ { "path" : "node:ad:field_related_videos" } ] },
    "rdf_mapping" : []
  }');
  $items['node:video:field_related_quiz*node:quiz:field_related_videos'] = entity_import('cer', '{
    "identifier" : "node:video:field_related_quiz*node:quiz:field_related_videos",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:video:field_related_quiz" } ] },
    "cer_right" : { "und" : [ { "path" : "node:quiz:field_related_videos" } ] },
    "rdf_mapping" : []
  }');
  $items['node:video:field_related_surveys*node:survey:field_related_videos'] = entity_import('cer', '{
    "identifier" : "node:video:field_related_surveys*node:survey:field_related_videos",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:video:field_related_surveys" } ] },
    "cer_right" : { "und" : [ { "path" : "node:survey:field_related_videos" } ] },
    "rdf_mapping" : []
  }');
  $items['node:video:field_related_videos*node:video:field_related_videos'] = entity_import('cer', '{
    "identifier" : "node:video:field_related_videos*node:video:field_related_videos",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:video:field_related_videos" } ] },
    "cer_right" : { "und" : [ { "path" : "node:video:field_related_videos" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function video_content_type_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Videos'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
