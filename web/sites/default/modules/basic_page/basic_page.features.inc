<?php
/**
 * @file
 * basic_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function basic_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function basic_page_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: page
  $schemaorg['node']['page'] = array(
    'rdftype' => array(
      0 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_paragraphs' => array(
      'predicates' => array(),
    ),
  );

  // Exported RDF mapping: paragraphs_blocks
  $schemaorg['paragraphs_item']['paragraphs_blocks'] = array(
    'field_paragraphs_block' => array(
      'predicates' => array(),
    ),
  );

  // Exported RDF mapping: paragraphs_bullets
  $schemaorg['paragraphs_item']['paragraphs_bullets'] = array(
    'field_paragraphs_header' => array(
      'predicates' => array(),
    ),
    'field_paragraphs_bullet' => array(
      'predicates' => array(),
    ),
  );

  // Exported RDF mapping: paragraphs_html
  $schemaorg['paragraphs_item']['paragraphs_html'] = array(
    'field_paragraphs_html' => array(
      'predicates' => array(),
    ),
  );

  return $schemaorg;
}
