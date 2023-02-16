<?php
/**
 * @file
 * commerce_for_dl.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_for_dl_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_licenses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_license';
  $view->human_name = 'My Licenses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Licenses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Subscription History</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'full_html_no_wyswyg';
  /* Relationship: Commerce License: Product product_id */
  $handler->display->display_options['relationships']['product']['id'] = 'product';
  $handler->display->display_options['relationships']['product']['table'] = 'commerce_license';
  $handler->display->display_options['relationships']['product']['field'] = 'product';
  /* Relationship: Commerce Product: Additional Seats (field_additional_seats) */
  $handler->display->display_options['relationships']['field_additional_seats_tid']['id'] = 'field_additional_seats_tid';
  $handler->display->display_options['relationships']['field_additional_seats_tid']['table'] = 'field_data_field_additional_seats';
  $handler->display->display_options['relationships']['field_additional_seats_tid']['field'] = 'field_additional_seats_tid';
  $handler->display->display_options['relationships']['field_additional_seats_tid']['relationship'] = 'product';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['cl_billing_cycle_type_target_id']['id'] = 'cl_billing_cycle_type_target_id';
  $handler->display->display_options['relationships']['cl_billing_cycle_type_target_id']['table'] = 'field_data_cl_billing_cycle_type';
  $handler->display->display_options['relationships']['cl_billing_cycle_type_target_id']['field'] = 'cl_billing_cycle_type_target_id';
  $handler->display->display_options['relationships']['cl_billing_cycle_type_target_id']['relationship'] = 'product';
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'product';
  $handler->display->display_options['fields']['title']['label'] = 'Product';
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_additional_seats_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Seats';
  /* Field: Commerce License Billing Cycle Type: Label */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'cl_billing_cycle_type';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'cl_billing_cycle_type_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Billing Cycle';
  /* Field: Commerce License: Expires */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'commerce_license';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['date_format'] = 'privatemsg_years';
  $handler->display->display_options['fields']['expires']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Commerce License: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_license';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Sort criterion: Commerce License: License ID */
  $handler->display->display_options['sorts']['license_id']['id'] = 'license_id';
  $handler->display->display_options['sorts']['license_id']['table'] = 'commerce_license';
  $handler->display->display_options['sorts']['license_id']['field'] = 'license_id';
  $handler->display->display_options['sorts']['license_id']['order'] = 'DESC';
  /* Contextual filter: Commerce License: Owner uid */
  $handler->display->display_options['arguments']['owner']['id'] = 'owner';
  $handler->display->display_options['arguments']['owner']['table'] = 'commerce_license';
  $handler->display->display_options['arguments']['owner']['field'] = 'owner';
  $handler->display->display_options['arguments']['owner']['default_action'] = 'default';
  $handler->display->display_options['arguments']['owner']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['owner']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['owner']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['owner']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['owner']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['owner']['validate']['type'] = 'current_user_or_role';
  $handler->display->display_options['arguments']['owner']['validate']['fail'] = 'access denied';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['my_licenses'] = $view;

  return $export;
}
