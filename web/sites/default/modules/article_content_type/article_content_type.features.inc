<?php
/**
 * @file
 * article_content_type.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function article_content_type_default_cer() {
  $items = array();
  $items['node:article:field_related_articles*node:article:field_related_articles'] = entity_import('cer', '{
    "identifier" : "node:article:field_related_articles*node:article:field_related_articles",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:article:field_related_articles" } ] },
    "cer_right" : { "und" : [ { "path" : "node:article:field_related_articles" } ] },
    "rdf_mapping" : []
  }');
  $items['node:article:field_related_blog*node:blog:field_related_articles'] = entity_import('cer', '{
    "identifier" : "node:article:field_related_blog*node:blog:field_related_articles",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:article:field_related_blog" } ] },
    "cer_right" : { "und" : [ { "path" : "node:blog:field_related_articles" } ] },
    "rdf_mapping" : []
  }');
  $items['node:article:field_related_quiz*node:quiz:field_related_articles'] = entity_import('cer', '{
    "identifier" : "node:article:field_related_quiz*node:quiz:field_related_articles",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:article:field_related_quiz" } ] },
    "cer_right" : { "und" : [ { "path" : "node:quiz:field_related_articles" } ] },
    "rdf_mapping" : []
  }');
  $items['node:article:field_related_surveys*node:survey:field_related_articles'] = entity_import('cer', '{
    "identifier" : "node:article:field_related_surveys*node:survey:field_related_articles",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:article:field_related_surveys" } ] },
    "cer_right" : { "und" : [ { "path" : "node:survey:field_related_articles" } ] },
    "rdf_mapping" : []
  }');
  $items['node:article:field_related_videos*node:video:field_related_articles'] = entity_import('cer', '{
    "identifier" : "node:article:field_related_videos*node:video:field_related_articles",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:article:field_related_videos" } ] },
    "cer_right" : { "und" : [ { "path" : "node:video:field_related_articles" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function article_content_type_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
