<?php
/**
 * @file
 * blog_content_type.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function blog_content_type_default_cer() {
  $items = array();
  $items['node:blog:field_related_ads*node:ad:field_related_blog'] = entity_import('cer', '{
    "identifier" : "node:blog:field_related_ads*node:ad:field_related_blog",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:blog:field_related_ads" } ] },
    "cer_right" : { "und" : [ { "path" : "node:ad:field_related_blog" } ] },
    "rdf_mapping" : []
  }');
  $items['node:blog:field_related_blog*node:blog:field_related_blog'] = entity_import('cer', '{
    "identifier" : "node:blog:field_related_blog*node:blog:field_related_blog",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:blog:field_related_blog" } ] },
    "cer_right" : { "und" : [ { "path" : "node:blog:field_related_blog" } ] },
    "rdf_mapping" : []
  }');
  $items['node:blog:field_related_surveys*node:survey:field_related_blog'] = entity_import('cer', '{
    "identifier" : "node:blog:field_related_surveys*node:survey:field_related_blog",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:blog:field_related_surveys" } ] },
    "cer_right" : { "und" : [ { "path" : "node:survey:field_related_blog" } ] },
    "rdf_mapping" : []
  }');
  $items['node:blog:field_related_videos*node:video:field_related_blog'] = entity_import('cer', '{
    "identifier" : "node:blog:field_related_videos*node:video:field_related_blog",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:blog:field_related_videos" } ] },
    "cer_right" : { "und" : [ { "path" : "node:video:field_related_blog" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function blog_content_type_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Blog Entry'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
