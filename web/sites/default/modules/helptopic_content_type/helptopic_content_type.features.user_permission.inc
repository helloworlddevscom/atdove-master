<?php
/**
 * @file
 * helptopic_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function helptopic_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create help_topic content'.
  $permissions['create help_topic content'] = array(
    'name' => 'create help_topic content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any help_topic content'.
  $permissions['delete any help_topic content'] = array(
    'name' => 'delete any help_topic content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own help_topic content'.
  $permissions['delete own help_topic content'] = array(
    'name' => 'delete own help_topic content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any help_topic content'.
  $permissions['edit any help_topic content'] = array(
    'name' => 'edit any help_topic content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own help_topic content'.
  $permissions['edit own help_topic content'] = array(
    'name' => 'edit own help_topic content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
