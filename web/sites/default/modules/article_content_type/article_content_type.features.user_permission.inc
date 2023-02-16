<?php
/**
 * @file
 * article_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function article_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer private files download permission'.
  $permissions['administer private files download permission'] = array(
    'name' => 'administer private files download permission',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'private_files_download_permission',
  );

  // Exported permission: 'bypass private files download permission'.
  $permissions['bypass private files download permission'] = array(
    'name' => 'bypass private files download permission',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'private_files_download_permission',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
