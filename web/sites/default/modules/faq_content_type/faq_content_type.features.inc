<?php
/**
 * @file
 * faq_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function faq_content_type_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('FAQs'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
