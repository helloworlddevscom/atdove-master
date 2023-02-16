<?php
/**
 * @file
 * organizational_groups_subgroups.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function organizational_groups_subgroups_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:organizational_groups:add user'
  $permissions['node:organizational_groups:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:administer group'
  $permissions['node:organizational_groups:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:approve and deny subscription'
  $permissions['node:organizational_groups:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:create organizational_groups content'
  $permissions['node:organizational_groups:create organizational_groups content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:delete any organizational_groups content'
  $permissions['node:organizational_groups:delete any organizational_groups content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organizational_groups:delete own organizational_groups content'
  $permissions['node:organizational_groups:delete own organizational_groups content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organizational_groups:invite people'
  $permissions['node:organizational_groups:invite people'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:manage members'
  $permissions['node:organizational_groups:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:manage permissions'
  $permissions['node:organizational_groups:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organizational_groups:manage roles'
  $permissions['node:organizational_groups:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organizational_groups:subscribe'
  $permissions['node:organizational_groups:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:subscribe without approval'
  $permissions['node:organizational_groups:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organizational_groups:unsubscribe'
  $permissions['node:organizational_groups:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:update any organizational_groups content'
  $permissions['node:organizational_groups:update any organizational_groups content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organizational_groups:update group'
  $permissions['node:organizational_groups:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organizational_groups:update own organizational_groups content'
  $permissions['node:organizational_groups:update own organizational_groups content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
