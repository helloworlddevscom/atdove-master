<?php
/**
 * @file
 * highlighted_video_view_and_block.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function highlighted_video_view_and_block_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'highlighted_video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Highlighted Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Highlighted Video';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<p class="highlighted-video-subtext">Featured Video</p>';
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  /* Field: Content: Wistia iFrame - Logged In Access */
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['id'] = 'field_wistia_iframe_logged_in_ac';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['table'] = 'field_data_field_wistia_iframe_logged_in_ac';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['field'] = 'field_wistia_iframe_logged_in_ac';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['label'] = '';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_ac']['element_default_classes'] = FALSE;
  /* Field: Content: Wistia iFrame - Logged In No Access */
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['id'] = 'field_wistia_iframe_logged_in_no';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['table'] = 'field_data_field_wistia_iframe_logged_in_no';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['field'] = 'field_wistia_iframe_logged_in_no';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['label'] = '';
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wistia_iframe_logged_in_no']['element_default_classes'] = FALSE;
  /* Field: Content: Wistia iFrame - Anonymous */
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['id'] = 'field_wistia_iframe_anonymous';
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['table'] = 'field_data_field_wistia_iframe_anonymous';
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['field'] = 'field_wistia_iframe_anonymous';
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['label'] = '';
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wistia_iframe_anonymous']['element_default_classes'] = FALSE;
  /* Field: Accessible Video */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Accessible Video';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
Global $user;

//different videos for different roles
//If user has a current subscription. 
if (in_array(\'Subscriber\', array_values($user->roles))) {

 print $row->field_wistia_iframe_logged_in_ac;
}
//If they are logged in
elseif(in_array(\'authenticated user\', array_values($user->roles))){
  print $row->field_wistia_iframe_logged_in_no;
}
//Otherwise Anon
else{
  print $row->field_wistia_iframe_anonymous;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Go To [title] &rarr;';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '[comment_count] Comments';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Close Div */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Close Div';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href=\'#\' class="close-featured-video"><img src="/sites/atdove.org/themes/atdove/images/small-icons/small-icons-dove-01.png" /></a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;
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
    'video' => 'video',
  );
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '1';

  /* Display: Filter By Job Category */
  $handler = $view->new_display('block', 'Filter By Job Category', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;

  /* Display: Show all Job Categories */
  $handler = $view->new_display('block', 'Show all Job Categories', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $export['highlighted_video'] = $view;

  return $export;
}
