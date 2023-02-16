<?php
/**
 * @file
 * paragraph_bundles_and_field_bases.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function paragraph_bundles_and_field_bases_paragraphs_info() {
  $items = array(
    'image_with_text' => array(
      'name' => 'Image With Text',
      'bundle' => 'image_with_text',
      'locked' => '1',
    ),
    'paragraphs_blocks' => array(
      'name' => 'Blocks',
      'bundle' => 'paragraphs_blocks',
      'locked' => '1',
    ),
    'paragraphs_bullets' => array(
      'name' => 'Bullets',
      'bundle' => 'paragraphs_bullets',
      'locked' => '1',
    ),
    'paragraphs_html' => array(
      'name' => 'HTML',
      'bundle' => 'paragraphs_html',
      'locked' => '1',
    ),
    'partners' => array(
      'name' => 'Partners',
      'bundle' => 'partners',
      'locked' => '1',
    ),
    'testimonial_reference' => array(
      'name' => 'Testimonial Reference',
      'bundle' => 'testimonial_reference',
      'locked' => '1',
    ),
  );
  return $items;
}
