<?php
/**
 * @file
 * assignment_featurette.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function assignment_featurette_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create assignment content'.
  $permissions['create assignment content'] = array(
    'name' => 'create assignment content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any assignment content'.
  $permissions['delete any assignment content'] = array(
    'name' => 'delete any assignment content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own assignment content'.
  $permissions['delete own assignment content'] = array(
    'name' => 'delete own assignment content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any assignment content'.
  $permissions['edit any assignment content'] = array(
    'name' => 'edit any assignment content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own assignment content'.
  $permissions['edit own assignment content'] = array(
    'name' => 'edit own assignment content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
