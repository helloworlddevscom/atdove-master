<?php
/**
 * @file
 * commerce_for_dl.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_for_dl_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer licenses'.
  $permissions['administer licenses'] = array(
    'name' => 'administer licenses',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_license',
  );

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce',
  );

  // Exported permission: 'redeem any coupon'.
  $permissions['redeem any coupon'] = array(
    'name' => 'redeem any coupon',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view own licenses'.
  $permissions['view own licenses'] = array(
    'name' => 'view own licenses',
    'roles' => array(
      'Billing Admin' => 'Billing Admin',
      'Subscriber' => 'Subscriber',
      'admin2' => 'admin2',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_license',
  );

  return $permissions;
}
