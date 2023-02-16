<?php
/**
 * @file
 * reimport_taxonomy.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function reimport_taxonomy_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'articles_taxonomy_only-related_tags-explode';
  $feeds_tamper->importer = 'articles_taxonomy_only';
  $feeds_tamper->source = 'related_tags';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['articles_taxonomy_only-related_tags-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'blogs_taxonomy_only-related_tags-explode';
  $feeds_tamper->importer = 'blogs_taxonomy_only';
  $feeds_tamper->source = 'related_tags';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['blogs_taxonomy_only-related_tags-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'videos_taxonomy_only-related_tags-explode';
  $feeds_tamper->importer = 'videos_taxonomy_only';
  $feeds_tamper->source = 'related_tags';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['videos_taxonomy_only-related_tags-explode'] = $feeds_tamper;

  return $export;
}
