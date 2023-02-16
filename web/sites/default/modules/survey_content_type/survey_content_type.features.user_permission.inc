<?php
/**
 * @file
 * survey_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function survey_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create survey content'.
  $permissions['create survey content'] = array(
    'name' => 'create survey content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any survey content'.
  $permissions['delete any survey content'] = array(
    'name' => 'delete any survey content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own survey content'.
  $permissions['delete own survey content'] = array(
    'name' => 'delete own survey content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any survey content'.
  $permissions['edit any survey content'] = array(
    'name' => 'edit any survey content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own survey content'.
  $permissions['edit own survey content'] = array(
    'name' => 'edit own survey content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
