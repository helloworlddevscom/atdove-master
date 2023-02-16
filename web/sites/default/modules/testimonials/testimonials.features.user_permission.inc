<?php
/**
 * @file
 * testimonials.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function testimonials_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create testimonials content'.
  $permissions['create testimonials content'] = array(
    'name' => 'create testimonials content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any testimonials content'.
  $permissions['delete any testimonials content'] = array(
    'name' => 'delete any testimonials content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own testimonials content'.
  $permissions['delete own testimonials content'] = array(
    'name' => 'delete own testimonials content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any testimonials content'.
  $permissions['edit any testimonials content'] = array(
    'name' => 'edit any testimonials content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own testimonials content'.
  $permissions['edit own testimonials content'] = array(
    'name' => 'edit own testimonials content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'search testimonials content'.
  $permissions['search testimonials content'] = array(
    'name' => 'search testimonials content',
    'roles' => array(),
    'module' => 'search_config',
  );

  return $permissions;
}
