<?php
/**
 * @file
 * faq_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function faq_content_type_taxonomy_default_vocabularies() {
  return array(
    'help_categories' => array(
      'name' => 'Help Categories',
      'machine_name' => 'help_categories',
      'description' => 'Tags for help topics',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
