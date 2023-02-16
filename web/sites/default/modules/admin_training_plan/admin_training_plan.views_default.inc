<?php
/**
 * @file
 * admin_training_plan.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function admin_training_plan_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_training_plans_current_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin Training Plans - Current Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin Training Plans - Current Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = 'return dl_trainingplans_admin_access_validate();';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>Kristin Spring, CVT, VTS(ECC, Anes.), CVPP, walks you through simple and inexpensive local anesthesia procedures you can start using tomorrow to benefit your patients. Pain management is an important facet of any treatment plan, especially surgical procedures.</p>
<div class="action-wrapper"><a id="tpperson-modal" title="Assign to Members" data-id="[nid]" class="user-button-browse assigntraining single-training" href="#"></a><a class="training-plan-clone-button" title="Clone" href="stockalter/[nid]"></a></div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_videos_target_id']['id'] = 'field_related_videos_target_id';
  $handler->display->display_options['relationships']['field_related_videos_target_id']['table'] = 'field_data_field_related_videos';
  $handler->display->display_options['relationships']['field_related_videos_target_id']['field'] = 'field_related_videos_target_id';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::dl_trainingplans_remove_tp_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Remove Selected Items',
    ),
  );
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Video Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'Video Title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Accreditations ';
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'accreditations' => 'accreditations',
    'additional_content_categories' => 0,
    'available_additional_seats' => 0,
    'categories' => 0,
    'content_categories' => 0,
    'tags' => 0,
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['fields']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_1']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['term_node_tid_1']['label'] = 'Categories';
  $handler->display->display_options['fields']['term_node_tid_1']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid_1']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['vocabularies'] = array(
    'content_categories' => 'content_categories',
    'accreditations' => 0,
    'additional_content_categories' => 0,
    'available_additional_seats' => 0,
    'categories' => 0,
    'tags' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Training Plan NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Training Plan NID';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = '//verify this user is an admin of this training plan
    $query = db_select(\'field_data_field_organization\',\'o\');
    $query->addField(\'o\',\'field_organization_target_id\',\'currOrg\');
    $query->condition(\'entity_id\',$argument);
    $query->condition(\'bundle\',\'training_plan\');
    $results = $query->execute();
    $resultsArr = $results->fetchAssoc();
    $currOrg =$resultsArr[\'currOrg\'];

global $user;
//If the user is in an org, an admin and this is the org they are trying to mod
if($currOrg!=false && organization_control_is_group_admin($currOrg,$user->uid) ){
return true;
};';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
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
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="action-wrapper"><a id="tpperson-modal" title="Assign to Members" data-id="[nid]" class="user-button-browse assigntraining" href="#"></a></div>
<div class="plan-details"><p> {{hook_views_pre_execute_course_count_total}} Courses - {{hook_views_pre_execute_course_hours_total}}</p></div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::dl_trainingplans_remove_tp_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Delete',
    ),
  );
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'square800',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Video Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'Video Title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h2>[title_1]</h2>';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '230';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Duration (in seconds) */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['relationship'] = 'field_related_videos_target_id';
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
  $handler->display->display_options['fields']['field_premium']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_premium']['label'] = '';
  $handler->display->display_options['fields']['field_premium']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['text'] = '<span class="views-footer-detail">[field_premium]</span>';
  $handler->display->display_options['fields']['field_premium']['element_label_colon'] = FALSE;
  /* Field: Content: Accredited For */
  $handler->display->display_options['fields']['field_accredited_for']['id'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['table'] = 'field_data_field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['field'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_accredited_for']['label'] = '';
  $handler->display->display_options['fields']['field_accredited_for']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accredited_for']['element_label_colon'] = FALSE;
  /* Field: Content: Credit Hours */
  $handler->display->display_options['fields']['field_credit_hours']['id'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['table'] = 'field_data_field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['field'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_credit_hours']['label'] = '';
  $handler->display->display_options['fields']['field_credit_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['alter']['text'] = '<span class="views-footer-detail">[field_accredited_for] Credit: [field_credit_hours]</span>';
  $handler->display->display_options['fields']['field_credit_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_hours']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_type'] = 'span';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'accreditations' => 'accreditations',
    'additional_content_categories' => 0,
    'available_additional_seats' => 0,
    'categories' => 0,
    'content_categories' => 0,
    'heard_about_us_from' => 0,
    'help_categories' => 0,
    'tags' => 0,
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['fields']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_1']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['term_node_tid_1']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['text'] = '<span class="views-footer-detail">[term_node_tid] [term_node_tid_1]</span>';
  $handler->display->display_options['fields']['term_node_tid_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['term_node_tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid_1']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid_1']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['vocabularies'] = array(
    'content_categories' => 'content_categories',
    'accreditations' => 0,
    'additional_content_categories' => 0,
    'available_additional_seats' => 0,
    'categories' => 0,
    'heard_about_us_from' => 0,
    'help_categories' => 0,
    'tags' => 0,
  );
  /* Field: Image Div */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Image Div';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-image-wrapper">
[field_image]
<div class="thumbnail-overlay"></div>
<span class="content-type-flag  content-type-flag-[type]">[type]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content Div */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Content Div';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="views-info-wrapper">
[title_1]
<span class="views-statistics">Views: [totalcount] - Comments: [comment_count]</span>
[body]
<div class="views-footer">
[field_duration][field_premium][field_credit_hours]
<h3 class="views-training-category">Categories</h3>
<span class="views-training-category">[term_node_tid]
[term_node_tid_1]</span>
</div>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;

  /* Display: Stock Plans */
  $handler = $view->new_display('block', 'Stock Plans', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
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
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="action-wrapper"><a id="tpperson-modal" title="Assign to Members" data-id="!1" class="user-button-browse assigntraining" href="#"></a><a class="training-plan-clone-button" title="Clone" href="/my-organization/trainingplans/stockalter/!1"></a></div>
<div class="plan-details"><p> {{hook_views_pre_execute_course_count_total}} Courses - {{hook_views_pre_execute_course_hours_total}}</p></div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'square800',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Video Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'Video Title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h2>[title_1]</h2>';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '230';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '230',
  );
  /* Field: Content: Duration (in seconds) */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['relationship'] = 'field_related_videos_target_id';
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
  $handler->display->display_options['fields']['field_premium']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_premium']['label'] = '';
  $handler->display->display_options['fields']['field_premium']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['text'] = '<span class="views-footer-detail">[field_premium]</span>';
  $handler->display->display_options['fields']['field_premium']['element_label_colon'] = FALSE;
  /* Field: Content: Accredited For */
  $handler->display->display_options['fields']['field_accredited_for']['id'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['table'] = 'field_data_field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['field'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_accredited_for']['label'] = '';
  $handler->display->display_options['fields']['field_accredited_for']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accredited_for']['element_label_colon'] = FALSE;
  /* Field: Content: Credit Hours */
  $handler->display->display_options['fields']['field_credit_hours']['id'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['table'] = 'field_data_field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['field'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['field_credit_hours']['label'] = '';
  $handler->display->display_options['fields']['field_credit_hours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_credit_hours']['alter']['text'] = '<span class="views-footer-detail">[field_accredited_for] Credit: [field_credit_hours]</span>';
  $handler->display->display_options['fields']['field_credit_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_credit_hours']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'accreditations' => 'accreditations',
    'additional_content_categories' => 0,
    'available_additional_seats' => 0,
    'categories' => 0,
    'content_categories' => 0,
    'heard_about_us_from' => 0,
    'help_categories' => 0,
    'tags' => 0,
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['fields']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_1']['relationship'] = 'field_related_videos_target_id';
  $handler->display->display_options['fields']['term_node_tid_1']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid_1']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid_1']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['vocabularies'] = array(
    'content_categories' => 'content_categories',
    'accreditations' => 0,
    'additional_content_categories' => 0,
    'available_additional_seats' => 0,
    'categories' => 0,
    'heard_about_us_from' => 0,
    'help_categories' => 0,
    'tags' => 0,
  );
  /* Field: Image Div */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Image Div';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-image-wrapper">
[field_image]
<div class="thumbnail-overlay"></div>
<span class="content-type-flag content-type-flag-[type]">[type]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content Div */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Content Div';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="views-info-wrapper">
[title_1]
<span class="views-statistics">Views: [totalcount] - Comments: [comment_count]</span>
[body]
<div class="views-footer">
[field_duration][field_premium][field_credit_hours]
<h3 class="views-training-category">Categories</h3>
<span class="views-training-category">[term_node_tid]
[term_node_tid_1]</span>
</div>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Training Plan NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Training Plan NID';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'global $user;
//Org admin only
if(organization_control_is_any_admin($user->uid) ){
return true;
};
return false;';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Stock (field_stock) */
  $handler->display->display_options['filters']['field_stock_value']['id'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['table'] = 'field_data_field_stock';
  $handler->display->display_options['filters']['field_stock_value']['field'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['value'] = array(
    1 => '1',
  );
  $export['admin_training_plans_current_content'] = $view;

  return $export;
}
