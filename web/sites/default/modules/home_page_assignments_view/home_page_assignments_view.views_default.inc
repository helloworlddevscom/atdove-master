<?php
/**
 * @file
 * home_page_assignments_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function home_page_assignments_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'home_page_assignments_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home Page Assignments View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Home Page Assignments View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Welcome[php]</h2>
<p class="center-align"></p>
<p class="home-view-paragraph">Check out your recent assignments below or view them all <a href="/my-account/my-assignments">here</a>.</p>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php 
global $user;
$user_details = user_load($user->uid);
$first = $user_details->field_first_name[\'und\'][0][\'value\']; 
if (!empty($first)){
 $first = \', \'.$first . \'!\';  
}
else {
 $first = \'!\';
}
?>

<h2>Welcome<?php print $first; ?></h2>
<p class="center-align"></p>
<img class="big-green-check" src="/sites/atdove.org/themes/atdove/images/icons/big-green-check.png" />
<p class="home-view-paragraph">You\'re all caught up on assignments. View previous assignments <a href="/my-account/my-assignments">here</a></p>
';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['id'] = 'field_assigned_content_target_id';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['table'] = 'field_data_field_assigned_content';
  $handler->display->display_options['relationships']['field_assigned_content_target_id']['field'] = 'field_assigned_content_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Due On */
  $handler->display->display_options['fields']['field_due_date']['id'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['fields']['field_due_date']['field'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['label'] = '';
  $handler->display->display_options['fields']['field_due_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_due_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Related Quiz */
  $handler->display->display_options['fields']['field_related_quiz']['id'] = 'field_related_quiz';
  $handler->display->display_options['fields']['field_related_quiz']['table'] = 'field_data_field_related_quiz';
  $handler->display->display_options['fields']['field_related_quiz']['field'] = 'field_related_quiz';
  $handler->display->display_options['fields']['field_related_quiz']['label'] = 'Related Quiz:';
  $handler->display->display_options['fields']['field_related_quiz']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_quiz']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_related_quiz']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_related_quiz']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_assigned_content_target_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'global $user;
$user_details = user_load($user->uid);
$first = $user_details->field_first_name[\'und\'][0][\'value\']; 
if (!empty($first)){
 return \', \'.$first . \'!\';  
}
else {
 return \'!\';
}';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Content: Completed (field_completed) */
  $handler->display->display_options['filters']['field_completed_value']['id'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['table'] = 'field_data_field_completed';
  $handler->display->display_options['filters']['field_completed_value']['field'] = 'field_completed_value';
  $handler->display->display_options['filters']['field_completed_value']['operator'] = 'empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['home_page_assignments_view'] = $view;

  return $export;
}
