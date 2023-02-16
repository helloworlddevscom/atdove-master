<?php
/**
 * @file
 * news_room_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function news_room_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news_room';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News Room';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News Room';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="news-room-h2-wrapper"><h2>[title]</h2></div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<p class="news-publish-date">[created]</p>';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: News Room File */
  $handler->display->display_options['fields']['field_news_room_file']['id'] = 'field_news_room_file';
  $handler->display->display_options['fields']['field_news_room_file']['table'] = 'field_data_field_news_room_file';
  $handler->display->display_options['fields']['field_news_room_file']['field'] = 'field_news_room_file';
  $handler->display->display_options['fields']['field_news_room_file']['label'] = '';
  $handler->display->display_options['fields']['field_news_room_file']['alter']['text'] = 'Download PDF';
  $handler->display->display_options['fields']['field_news_room_file']['alter']['path'] = 'sites/atdove.org/files/[field_news_room_file]';
  $handler->display->display_options['fields']['field_news_room_file']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_news_room_file']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_news_room_file']['element_class'] = 'news-room-file';
  $handler->display->display_options['fields']['field_news_room_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_room_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_news_room_file']['click_sort_column'] = 'fid';
  /* Field: Content: Article Link */
  $handler->display->display_options['fields']['field_article_link']['id'] = 'field_article_link';
  $handler->display->display_options['fields']['field_article_link']['table'] = 'field_data_field_article_link';
  $handler->display->display_options['fields']['field_article_link']['field'] = 'field_article_link';
  $handler->display->display_options['fields']['field_article_link']['label'] = '';
  $handler->display->display_options['fields']['field_article_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_article_link']['alter']['text'] = '<span class="file"><a class="news-room-link" href="[field_article_link]">Read Article</a></span>';
  $handler->display->display_options['fields']['field_article_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_link']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'news_room' => 'news_room',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['block_description'] = 'Newsroom';
  $export['news_room'] = $view;

  return $export;
}
