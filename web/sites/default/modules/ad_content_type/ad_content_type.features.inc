<?php
/**
 * @file
 * ad_content_type.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function ad_content_type_default_cer() {
  $items = array();
  $items['node:ad:field_related_articles*node:article:field_related_ads'] = entity_import('cer', '{
    "identifier" : "node:ad:field_related_articles*node:article:field_related_ads",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:ad:field_related_articles" } ] },
    "cer_right" : { "und" : [ { "path" : "node:article:field_related_ads" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function ad_content_type_node_info() {
  $items = array(
    'ad' => array(
      'name' => t('Ad'),
      'base' => 'node_content',
      'description' => t('Ad Banners'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
