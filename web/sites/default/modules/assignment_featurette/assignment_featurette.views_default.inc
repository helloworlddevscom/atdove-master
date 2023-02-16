<?php
/**
 * @file
 * assignment_featurette.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function assignment_featurette_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'assignments_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Assignments - Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Assignments - Admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear Filters';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'gid' => 'gid',
    'name' => 'name',
    'name_1' => 'name_1',
    'field_image' => 'field_image',
    'title_1' => 'title_1',
    'created' => 'created',
    'body' => 'body',
    'field_due_date' => 'field_due_date',
    'field_completed' => 'field_completed',
    'nid' => 'nid',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_first_name_1' => 'field_first_name_1',
    'field_last_name_1' => 'field_last_name_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'gid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_due_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="clearit"></div>
<h1>Manage Assignments <a class="question" title="Learn More" target="_blank" href="/guides/sending-and-managing-assignments" >?</a></h1>';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_assignee_node']['id'] = 'reverse_field_assignee_node';
  $handler->display->display_options['relationships']['reverse_field_assignee_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_assignee_node']['field'] = 'reverse_field_assignee_node';
  $handler->display->display_options['relationships']['reverse_field_assignee_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['id'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['table'] = 'field_data_field_assigned_content';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['field'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['id'] = 'field_related_trainingplan_target_id';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['table'] = 'field_data_field_related_trainingplan';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['field'] = 'field_related_trainingplan_target_id';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['relationship'] = 'reverse_field_assignee_node';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Batch';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::dl_assignments_unpublish_content_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Delete',
    ),
  );
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Image and Title */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Image and Title';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Title';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<span class="views-inline-image-wrapper">[field_image]<div class="thumbnail-overlay"></div><span class="content-type-flag content-type-flag-[type]">[type]</span></span><span class="views-inline-title-wrapper">[title_1]</span>';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Assigned To';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = '/my-organization/assignments/[gid]/[uid]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Assigned By';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['fields']['created']['label'] = 'Assigned On';
  $handler->display->display_options['fields']['created']['alter']['text'] = '<span class="date-display-single">[created]</span>';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'privatemsg_years';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Content: Due On */
  $handler->display->display_options['fields']['field_due_date']['id'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['fields']['field_due_date']['field'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['fields']['field_due_date']['label'] = 'Due By';
  $handler->display->display_options['fields']['field_due_date']['alter']['text'] = '[field_due_date]';
  $handler->display->display_options['fields']['field_due_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_due_date']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_due_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_due_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_due_date']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Completed */
  $handler->display->display_options['fields']['field_completed']['id'] = 'field_completed';
  $handler->display->display_options['fields']['field_completed']['table'] = 'field_data_field_completed';
  $handler->display->display_options['fields']['field_completed']['field'] = 'field_completed';
  $handler->display->display_options['fields']['field_completed']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['fields']['field_completed']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="#" class="user-button-browse person" data-id="[nid]" title="Assign to Another Person"></a>';
  /* Field: Add to TP */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Add to TP';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<a href="#" class="user-button-browse training" data-id="[nid]" title="Add To Training Plan"></a>';
  /* Field: assigned_to_first_name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['ui_name'] = 'assigned_to_first_name';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  /* Field: assigned_to_last_name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['ui_name'] = 'assigned_to_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_plain';
  /* Field: assigned_by_first_name */
  $handler->display->display_options['fields']['field_first_name_1']['id'] = 'field_first_name_1';
  $handler->display->display_options['fields']['field_first_name_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name_1']['ui_name'] = 'assigned_by_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name_1']['type'] = 'text_plain';
  /* Field: assigned_by_last_name */
  $handler->display->display_options['fields']['field_last_name_1']['id'] = 'field_last_name_1';
  $handler->display->display_options['fields']['field_last_name_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['ui_name'] = 'assigned_by_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name_1']['type'] = 'text_plain';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Assign To';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name_1']['id'] = 'name_1';
  $handler->display->display_options['sorts']['name_1']['table'] = 'users';
  $handler->display->display_options['sorts']['name_1']['field'] = 'name';
  $handler->display->display_options['sorts']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['sorts']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name_1']['expose']['label'] = 'Assigned By';
  /* Sort criterion: Content: Due On (field_due_date) */
  $handler->display->display_options['sorts']['field_due_date_value']['id'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['sorts']['field_due_date_value']['field'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['sorts']['field_due_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_due_date_value']['expose']['label'] = 'Due By';
  /* Sort criterion: Content: Completed (field_completed) */
  $handler->display->display_options['sorts']['field_completed_value']['id'] = 'field_completed_value';
  $handler->display->display_options['sorts']['field_completed_value']['table'] = 'field_data_field_completed';
  $handler->display->display_options['sorts']['field_completed_value']['field'] = 'field_completed_value';
  $handler->display->display_options['sorts']['field_completed_value']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['sorts']['field_completed_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_completed_value']['expose']['label'] = 'Completed';
  /* Contextual filter: User: Organization (og_user_node) */
  $handler->display->display_options['arguments']['og_user_node_target_id']['id'] = 'og_user_node_target_id';
  $handler->display->display_options['arguments']['og_user_node_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_user_node_target_id']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['arguments']['og_user_node_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_user_node_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['og_user_node_target_id']['default_argument_options']['code'] = 'return organization_control_orgID();';
  $handler->display->display_options['arguments']['og_user_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_user_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_user_node_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['og_user_node_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_user_node_target_id']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['og_user_node_target_id']['validate_options']['code'] = '//the id could be a org or group.
//test if org
if(organization_control_is_group_admin($argument)){
return true;
}
//test if group
elseif(organization_control_is_group_admin_by_subgroup($argument)){
return true;
}
return false;';
  /* Contextual filter: Content: Assignee (field_assignee) */
  $handler->display->display_options['arguments']['field_assignee_target_id']['id'] = 'field_assignee_target_id';
  $handler->display->display_options['arguments']['field_assignee_target_id']['table'] = 'field_data_field_assignee';
  $handler->display->display_options['arguments']['field_assignee_target_id']['field'] = 'field_assignee_target_id';
  $handler->display->display_options['arguments']['field_assignee_target_id']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['arguments']['field_assignee_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_assignee_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignee_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignee_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_assignee_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_assignee_target_id']['validate']['type'] = 'user';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'reverse_field_assignee_node';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Content: Job Category (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Pick Your Track';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Content: Content Category (field_content_category) */
  $handler->display->display_options['filters']['field_content_category_tid']['id'] = 'field_content_category_tid';
  $handler->display->display_options['filters']['field_content_category_tid']['table'] = 'field_data_field_content_category';
  $handler->display->display_options['filters']['field_content_category_tid']['field'] = 'field_content_category_tid';
  $handler->display->display_options['filters']['field_content_category_tid']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['field_content_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_content_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['operator_id'] = 'field_content_category_tid_op';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['label'] = 'Content Category';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['operator'] = 'field_content_category_tid_op';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['identifier'] = 'field_content_category_tid';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_content_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_content_category_tid']['vocabulary'] = 'content_categories';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  /* Filter criterion: assigned_to_name */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['ui_name'] = 'assigned_to_name';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Assigned To';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'assigned_to';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  /* Filter criterion: assigned_by_name */
  $handler->display->display_options['filters']['combine_1']['id'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['table'] = 'views';
  $handler->display->display_options['filters']['combine_1']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_1']['ui_name'] = 'assigned_by_name';
  $handler->display->display_options['filters']['combine_1']['operator'] = 'word';
  $handler->display->display_options['filters']['combine_1']['group'] = 1;
  $handler->display->display_options['filters']['combine_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_1']['expose']['operator_id'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['label'] = 'Assigned By';
  $handler->display->display_options['filters']['combine_1']['expose']['operator'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['identifier'] = 'assigned_by';
  $handler->display->display_options['filters']['combine_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine_1']['fields'] = array(
    'name_1' => 'name_1',
    'field_first_name_1' => 'field_first_name_1',
    'field_last_name_1' => 'field_last_name_1',
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'not';
  $handler->display->display_options['filters']['mail']['value'] = 'dlBillingUser';
  $handler->display->display_options['filters']['mail']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'my-organization/assignments';
  $export['assignments_admin'] = $view;

  $view = new view();
  $view->name = 'my_assignments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Assignments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Completed Assignments';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear Filters';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_image' => 'field_image',
    'title_1' => 'title_1',
    'name' => 'name',
    'created' => 'created',
    'body' => 'body',
    'field_due_date' => 'field_due_date',
    'field_completed' => 'field_completed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_due_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'my_assignments:block_1';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>You have no assignments matching your filter criteria.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['id'] = 'field_related_trainingplan_target_id';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['table'] = 'field_data_field_related_trainingplan';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['field'] = 'field_related_trainingplan_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['id'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['table'] = 'field_data_field_assigned_content';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['field'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['required'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Due On */
  $handler->display->display_options['fields']['field_due_date']['id'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['fields']['field_due_date']['field'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['settings'] = array(
    'format_type' => 'just_the_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Content Category */
  $handler->display->display_options['fields']['field_content_category']['id'] = 'field_content_category';
  $handler->display->display_options['fields']['field_content_category']['table'] = 'field_data_field_content_category';
  $handler->display->display_options['fields']['field_content_category']['field'] = 'field_content_category';
  $handler->display->display_options['fields']['field_content_category']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_content_category']['label'] = '';
  $handler->display->display_options['fields']['field_content_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_content_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_content_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_content_category']['delta_offset'] = '0';
  /* Field: Content: Premium */
  $handler->display->display_options['fields']['field_premium']['id'] = 'field_premium';
  $handler->display->display_options['fields']['field_premium']['table'] = 'field_data_field_premium';
  $handler->display->display_options['fields']['field_premium']['field'] = 'field_premium';
  $handler->display->display_options['fields']['field_premium']['label'] = '';
  $handler->display->display_options['fields']['field_premium']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['element_label_colon'] = FALSE;
  /* Field: Content: Credit Hours */
  $handler->display->display_options['fields']['field_credit_hours']['id'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['table'] = 'field_data_field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['field'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['label'] = '';
  $handler->display->display_options['fields']['field_credit_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_hours']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Image Div */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Image Div';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="my-assignment-image-wrapper">
[field_image]
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content Div */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Content Div';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="my-assignment-info-wrapper">
<h2>[title_1]</h2>

</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Contextual filter: Content: Assignee (field_assignee) */
  $handler->display->display_options['arguments']['field_assignee_target_id']['id'] = 'field_assignee_target_id';
  $handler->display->display_options['arguments']['field_assignee_target_id']['table'] = 'field_data_field_assignee';
  $handler->display->display_options['arguments']['field_assignee_target_id']['field'] = 'field_assignee_target_id';
  $handler->display->display_options['arguments']['field_assignee_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_assignee_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_assignee_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignee_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignee_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_assignee_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_assignee_target_id']['validate']['type'] = 'current_user_or_role';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'assignment' => 'assignment',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Completed (field_completed) */
  $handler->display->display_options['filters']['field_completed_value']['id'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['table'] = 'field_data_field_completed';
  $handler->display->display_options['filters']['field_completed_value']['field'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_completed_value']['expose']['operator_id'] = 'field_completed_value_op';
  $handler->display->display_options['filters']['field_completed_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_completed_value']['expose']['description'] = 'or by Status...';
  $handler->display->display_options['filters']['field_completed_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_completed_value']['expose']['operator'] = 'field_completed_value_op';
  $handler->display->display_options['filters']['field_completed_value']['expose']['identifier'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Assignments';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="view-header-inner-wrapper">
<h3>Filter Content</h3>
<p>Search for videos and blogs by filtering content. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text.</p>
</div>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<h2>Completed Assignments</h2>';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'my_assignments:block_1';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['id'] = 'field_related_trainingplan_target_id';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['table'] = 'field_data_field_related_trainingplan';
  $handler->display->display_options['relationships']['field_related_trainingplan_target_id']['field'] = 'field_related_trainingplan_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['id'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['table'] = 'field_data_field_assigned_content';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['field'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['required'] = TRUE;
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '230';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Duration (in seconds) */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_duration']['label'] = '';
  $handler->display->display_options['fields']['field_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['alter']['text'] = '<span class="views-footer-detail">[field_duration]</span>';
  $handler->display->display_options['fields']['field_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_duration']['type'] = 'timeperiod_default';
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'granularity' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Premium */
  $handler->display->display_options['fields']['field_premium']['id'] = 'field_premium';
  $handler->display->display_options['fields']['field_premium']['table'] = 'field_data_field_premium';
  $handler->display->display_options['fields']['field_premium']['field'] = 'field_premium';
  $handler->display->display_options['fields']['field_premium']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_premium']['label'] = '';
  $handler->display->display_options['fields']['field_premium']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['text'] = '<span class="views-footer-detail">[field_premium]</span>';
  $handler->display->display_options['fields']['field_premium']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_premium']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['empty_zero'] = TRUE;
  /* Field: Content: Accredited For */
  $handler->display->display_options['fields']['field_accredited_for']['id'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['table'] = 'field_data_field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['field'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_accredited_for']['label'] = '';
  $handler->display->display_options['fields']['field_accredited_for']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accredited_for']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accredited_for']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_accredited_for']['empty_zero'] = TRUE;
  /* Field: Content: Credit Hours */
  $handler->display->display_options['fields']['field_credit_hours']['id'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['table'] = 'field_data_field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['field'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_credit_hours']['label'] = '';
  $handler->display->display_options['fields']['field_credit_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['alter']['text'] = '<span class="views-footer-detail">[field_accredited_for] Credit: [field_credit_hours]</span>';
  $handler->display->display_options['fields']['field_credit_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_hours']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['text'] = '<span class="bookmark-icon" title="Bookmark This Content">[ops]</span>';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Image Div */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Image Div';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="views-image-wrapper">
[field_image]
<div class="thumbnail-overlay"></div>
<span class="content-type-flag content-type-flag-[type]">[type]</span>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content Div */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Content Div';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-info-wrapper">
<h2>[title_1]</h2>
<span class="views-statistics">Views: [totalcount] - Comments: [comment_count]</span>
[body]
<div class="views-footer">[field_duration][field_premium][field_credit_hours]</div>
[ops]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Due On */
  $handler->display->display_options['fields']['field_due_date']['id'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['fields']['field_due_date']['field'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['label'] = '';
  $handler->display->display_options['fields']['field_due_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_due_date']['alter']['text'] = '<div class="views-due-on-wrapper">
<h2>Due on</h2>
[field_due_date]
</div>';
  $handler->display->display_options['fields']['field_due_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_due_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_due_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_due_date']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Due On (field_due_date) */
  $handler->display->display_options['sorts']['field_due_date_value']['id'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['sorts']['field_due_date_value']['field'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_due_date_value']['expose']['label'] = 'Due By';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'assignment' => 'assignment',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Completed (field_completed) */
  $handler->display->display_options['filters']['field_completed_value']['id'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['table'] = 'field_data_field_completed';
  $handler->display->display_options['filters']['field_completed_value']['field'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_completed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_completed_value']['expose']['operator_id'] = 'field_completed_value_op';
  $handler->display->display_options['filters']['field_completed_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_completed_value']['expose']['description'] = 'or by Status...';
  $handler->display->display_options['filters']['field_completed_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_completed_value']['expose']['operator'] = 'field_completed_value_op';
  $handler->display->display_options['filters']['field_completed_value']['expose']['identifier'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['body_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['body_value']['group'] = 1;
  $handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['label'] = 'Body';
  $handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Job Category (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Pick Your Track';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Content: Content Category (field_content_category) */
  $handler->display->display_options['filters']['field_content_category_tid']['id'] = 'field_content_category_tid';
  $handler->display->display_options['filters']['field_content_category_tid']['table'] = 'field_data_field_content_category';
  $handler->display->display_options['filters']['field_content_category_tid']['field'] = 'field_content_category_tid';
  $handler->display->display_options['filters']['field_content_category_tid']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['field_content_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_content_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['operator_id'] = 'field_content_category_tid_op';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['label'] = 'Content Category';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['operator'] = 'field_content_category_tid_op';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['identifier'] = 'field_content_category_tid';
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_content_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_content_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_content_category_tid']['vocabulary'] = 'content_categories';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    16 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_1' => 'title_1',
    'body' => 'body',
  );
  $handler->display->display_options['path'] = 'my-account/my-assignments';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Title';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="views-inline-image-wrapper">[field_image]<div class="thumbnail-overlay"></div><span class="content-type-flag content-type-flag-[type]">[type]</span></span><span class="views-inline-title-wrapper">[title_1]</span>';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Assigned By';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Instructions';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Assigned On';
  $handler->display->display_options['fields']['created']['date_format'] = 'privatemsg_years';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Content: Due On */
  $handler->display->display_options['fields']['field_due_date']['id'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['fields']['field_due_date']['field'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Completed */
  $handler->display->display_options['fields']['field_completed']['id'] = 'field_completed';
  $handler->display->display_options['fields']['field_completed']['table'] = 'field_data_field_completed';
  $handler->display->display_options['fields']['field_completed']['field'] = 'field_completed';
  $handler->display->display_options['fields']['field_completed']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Assigned On';
  /* Sort criterion: Content: Due On (field_due_date) */
  $handler->display->display_options['sorts']['field_due_date_value']['id'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['sorts']['field_due_date_value']['field'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_due_date_value']['expose']['label'] = 'Due By';
  /* Sort criterion: Content: Completed (field_completed) */
  $handler->display->display_options['sorts']['field_completed_value']['id'] = 'field_completed_value';
  $handler->display->display_options['sorts']['field_completed_value']['table'] = 'field_data_field_completed';
  $handler->display->display_options['sorts']['field_completed_value']['field'] = 'field_completed_value';
  $handler->display->display_options['sorts']['field_completed_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_completed_value']['expose']['label'] = 'Completed';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'assignment' => 'assignment',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Completed (field_completed) */
  $handler->display->display_options['filters']['field_completed_value']['id'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['table'] = 'field_data_field_completed';
  $handler->display->display_options['filters']['field_completed_value']['field'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_completed_value']['expose']['operator_id'] = 'field_completed_value_op';
  $handler->display->display_options['filters']['field_completed_value']['expose']['label'] = 'Completed (field_completed)';
  $handler->display->display_options['filters']['field_completed_value']['expose']['operator'] = 'field_completed_value_op';
  $handler->display->display_options['filters']['field_completed_value']['expose']['identifier'] = 'field_completed_value';
  $export['my_assignments'] = $view;

  return $export;
}
