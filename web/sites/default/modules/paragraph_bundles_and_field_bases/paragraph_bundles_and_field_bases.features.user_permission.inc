<?php
/**
 * @file
 * paragraph_bundles_and_field_bases.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function paragraph_bundles_and_field_bases_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer paragraphs bundles'.
  $permissions['administer paragraphs bundles'] = array(
    'name' => 'administer paragraphs bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'paragraphs',
  );

  return $permissions;
}
