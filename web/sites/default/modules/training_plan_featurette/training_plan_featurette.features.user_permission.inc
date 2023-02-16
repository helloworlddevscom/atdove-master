<?php
/**
 * @file
 * training_plan_featurette.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function training_plan_featurette_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create training_plan content'.
  $permissions['create training_plan content'] = array(
    'name' => 'create training_plan content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any training_plan content'.
  $permissions['delete any training_plan content'] = array(
    'name' => 'delete any training_plan content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own training_plan content'.
  $permissions['delete own training_plan content'] = array(
    'name' => 'delete own training_plan content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any training_plan content'.
  $permissions['edit any training_plan content'] = array(
    'name' => 'edit any training_plan content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own training_plan content'.
  $permissions['edit own training_plan content'] = array(
    'name' => 'edit own training_plan content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'admin2' => 'admin2',
    ),
    'module' => 'node',
  );

  return $permissions;
}
