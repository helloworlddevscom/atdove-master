<?php
/**
 * @file
 * sidebar_download_button.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sidebar_download_button_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sidebar_download_button';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sidebar Download Button';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sidebar Download Button';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: PDF Version */
  $handler->display->display_options['fields']['field_pdf_version']['id'] = 'field_pdf_version';
  $handler->display->display_options['fields']['field_pdf_version']['table'] = 'field_data_field_pdf_version';
  $handler->display->display_options['fields']['field_pdf_version']['field'] = 'field_pdf_version';
  $handler->display->display_options['fields']['field_pdf_version']['label'] = '';
  $handler->display->display_options['fields']['field_pdf_version']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pdf_version']['alter']['text'] = '<a class="user-button download" href="[field_pdf_version]" title="Download PDF">Download<br />PDF</a>';
  $handler->display->display_options['fields']['field_pdf_version']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_version']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_version']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_version']['type'] = 'file_url_plain';
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
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['sidebar_download_button'] = $view;

  return $export;
}
