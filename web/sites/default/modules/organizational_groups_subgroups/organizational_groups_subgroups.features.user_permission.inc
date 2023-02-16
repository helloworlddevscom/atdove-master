<?php
/**
 * @file
 * organizational_groups_subgroups.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function organizational_groups_subgroups_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create organizational_groups content'.
  $permissions['create organizational_groups content'] = array(
    'name' => 'create organizational_groups content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any organizational_groups content'.
  $permissions['delete any organizational_groups content'] = array(
    'name' => 'delete any organizational_groups content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own organizational_groups content'.
  $permissions['delete own organizational_groups content'] = array(
    'name' => 'delete own organizational_groups content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any organizational_groups content'.
  $permissions['edit any organizational_groups content'] = array(
    'name' => 'edit any organizational_groups content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own organizational_groups content'.
  $permissions['edit own organizational_groups content'] = array(
    'name' => 'edit own organizational_groups content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
