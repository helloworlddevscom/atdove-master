<?php
/**
 * @file
 * commerce_for_dl.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function commerce_for_dl_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_coupons:admin/commerce/coupons.
  $menu_links['management_coupons:admin/commerce/coupons'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/coupons',
    'router_path' => 'admin/commerce/coupons',
    'link_title' => 'Coupons',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage coupons',
      ),
      'identifier' => 'management_coupons:admin/commerce/coupons',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_store:admin/commerce',
  );
  // Exported menu link: management_create-coupon:admin/commerce/coupons/add.
  $menu_links['management_create-coupon:admin/commerce/coupons/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/coupons/add',
    'router_path' => 'admin/commerce/coupons/add',
    'link_title' => 'Create Coupon',
    'options' => array(
      'attributes' => array(
        'title' => 'Create a new coupon',
      ),
      'identifier' => 'management_create-coupon:admin/commerce/coupons/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_coupons:admin/commerce/coupons',
  );
  // Exported menu link: management_create-label:admin/commerce/coupons/add/discount-coupon.
  $menu_links['management_create-label:admin/commerce/coupons/add/discount-coupon'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/coupons/add/discount-coupon',
    'router_path' => 'admin/commerce/coupons/add/discount-coupon',
    'link_title' => 'Create !label',
    'options' => array(
      'identifier' => 'management_create-label:admin/commerce/coupons/add/discount-coupon',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_create-coupon:admin/commerce/coupons/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Coupons');
  t('Create !label');
  t('Create Coupon');

  return $menu_links;
}
