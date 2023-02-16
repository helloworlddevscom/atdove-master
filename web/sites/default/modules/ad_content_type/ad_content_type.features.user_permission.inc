<?php
/**
 * @file
 * ad_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ad_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ad content'.
  $permissions['create ad content'] = array(
    'name' => 'create ad content',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ad content'.
  $permissions['delete any ad content'] = array(
    'name' => 'delete any ad content',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ad content'.
  $permissions['delete own ad content'] = array(
    'name' => 'delete own ad content',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ad content'.
  $permissions['edit any ad content'] = array(
    'name' => 'edit any ad content',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ad content'.
  $permissions['edit own ad content'] = array(
    'name' => 'edit own ad content',
    'roles' => array(
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
