<?php
/**
 * @file
 * helptopic_content_type.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function helptopic_content_type_default_cer() {
  $items = array();
  $items['node:help_topic:field_related_help_topics*node:help_topic:field_related_help_topics'] = entity_import('cer', '{
    "identifier" : "node:help_topic:field_related_help_topics*node:help_topic:field_related_help_topics",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:help_topic:field_related_help_topics" } ] },
    "cer_right" : { "und" : [ { "path" : "node:help_topic:field_related_help_topics" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function helptopic_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function helptopic_content_type_node_info() {
  $items = array(
    'help_topic' => array(
      'name' => t('Help Topic'),
      'base' => 'node_content',
      'description' => t('Help Topics'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
