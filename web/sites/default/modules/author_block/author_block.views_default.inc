<?php
/**
 * @file
 * author_block.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function author_block_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'author_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Author Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Author Block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: User: Content authored */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'users';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['text'] = '<p>[field_first_name-value]</p>';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_first_name']['element_wrapper_class'] = 'author-first-name';
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '<p>[field_first_name] [field_last_name]</p>';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_class'] = 'author-last-name';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: User: Designations */
  $handler->display->display_options['fields']['field_designations']['id'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['table'] = 'field_data_field_designations';
  $handler->display->display_options['fields']['field_designations']['field'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['label'] = '';
  $handler->display->display_options['fields']['field_designations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_designations']['alter']['text'] = '<p></p>';
  $handler->display->display_options['fields']['field_designations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_designations']['element_wrapper_class'] = 'user-designations';
  $handler->display->display_options['fields']['field_designations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['delta_offset'] = '0';
  /* Field: User: Specialty Designation */
  $handler->display->display_options['fields']['field_specialty_designation_1']['id'] = 'field_specialty_designation_1';
  $handler->display->display_options['fields']['field_specialty_designation_1']['table'] = 'field_data_field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation_1']['field'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation_1']['label'] = '';
  $handler->display->display_options['fields']['field_specialty_designation_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_specialty_designation_1']['alter']['text'] = '<p>[field_designations] - [field_specialty_designation_1]</p>';
  $handler->display->display_options['fields']['field_specialty_designation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_specialty_designation_1']['element_wrapper_class'] = 'user-specialty-designations';
  $handler->display->display_options['fields']['field_specialty_designation_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation_1']['delta_offset'] = '0';
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bio']['alter']['text'] = '[field_bio-value]';
  $handler->display->display_options['fields']['field_bio']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_bio']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bio']['element_wrapper_class'] = 'author-bio-snippet';
  $handler->display->display_options['fields']['field_bio']['element_default_classes'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['author_block'] = $view;

  return $export;
}
