<?php
/**
 * @file
 * video_content_type.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function video_content_type_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:summary]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'article:publisher' => array(
        'value' => 'https://www.facebook.com/atdoveorg',
      ),
      'article:published_time' => array(
        'value' => '[node:created:custom:c]',
      ),
      'article:modified_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'video:duration' => array(
        'value' => '[node:field_duration]',
      ),
    ),
  );

  return $config;
}
