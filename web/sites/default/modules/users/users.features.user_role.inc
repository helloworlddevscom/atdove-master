<?php
/**
 * @file
 * users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function users_user_default_roles() {
  $roles = array();

  // Exported role: Blogger.
  $roles['Blogger'] = array(
    'name' => 'Blogger',
    'weight' => 5,
  );

  // Exported role: Consultant.
  $roles['Consultant'] = array(
    'name' => 'Consultant',
    'weight' => 10,
  );

  // Exported role: Contributor.
  $roles['Contributor'] = array(
    'name' => 'Contributor',
    'weight' => 9,
  );

  // Exported role: Unverified.
  $roles['Unverified'] = array(
    'name' => 'Unverified',
    'weight' => 8,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
