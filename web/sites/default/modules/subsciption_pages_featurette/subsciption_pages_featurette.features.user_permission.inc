<?php
/**
 * @file
 * subsciption_pages_featurette.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subsciption_pages_featurette_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create subscription content'.
  $permissions['create subscription content'] = array(
    'name' => 'create subscription content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any subscription content'.
  $permissions['delete any subscription content'] = array(
    'name' => 'delete any subscription content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own subscription content'.
  $permissions['delete own subscription content'] = array(
    'name' => 'delete own subscription content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any subscription content'.
  $permissions['edit any subscription content'] = array(
    'name' => 'edit any subscription content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own subscription content'.
  $permissions['edit own subscription content'] = array(
    'name' => 'edit own subscription content',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
