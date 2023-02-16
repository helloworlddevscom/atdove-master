<?php
/**
 * @file
 * blogs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function blogs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blogs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Blogs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blogs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1 class="center-align">atdove.org Blogs</h1>
<p class="center-align">DoveLewis staff and guest contributors share stories from the hospital floor, professional advice, and some off-the-clock musings.</p>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="blogs-wrapper">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Blog Title */
  $handler->display->display_options['fields']['field_blog_title']['id'] = 'field_blog_title';
  $handler->display->display_options['fields']['field_blog_title']['table'] = 'field_data_field_blog_title';
  $handler->display->display_options['fields']['field_blog_title']['field'] = 'field_blog_title';
  $handler->display->display_options['fields']['field_blog_title']['label'] = '';
  $handler->display->display_options['fields']['field_blog_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_title']['alter']['text'] = '<a href="blog/[field_blog_title]"><h2>[field_blog_title]</h2></a>';
  $handler->display->display_options['fields']['field_blog_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_title']['element_default_classes'] = FALSE;
  /* Field: Field: Blog Image */
  $handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_blog_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_blog_image']['alter']['text'] = '<a href="blog/[field_blog_title]"><div class="blogs-image">[field_blog_image]</div></a>';
  $handler->display->display_options['fields']['field_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="blogs-wrapper-content">';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['label'] = '';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '<a href="blog/[field_blog_title]"><h2>[field_blog_title]</h2></a>';
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<p class="blogs-name">[name]';
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: Designations */
  $handler->display->display_options['fields']['field_designations_1']['id'] = 'field_designations_1';
  $handler->display->display_options['fields']['field_designations_1']['table'] = 'field_data_field_designations';
  $handler->display->display_options['fields']['field_designations_1']['field'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations_1']['label'] = '';
  $handler->display->display_options['fields']['field_designations_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_designations_1']['alter']['text'] = ',';
  $handler->display->display_options['fields']['field_designations_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_designations_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_designations_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_designations_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_designations_1']['separator'] = '';
  /* Field: User: Designations */
  $handler->display->display_options['fields']['field_designations']['id'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['table'] = 'field_data_field_designations';
  $handler->display->display_options['fields']['field_designations']['field'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['label'] = '';
  $handler->display->display_options['fields']['field_designations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['delta_offset'] = '0';
  /* Field: User: Specialty Designation */
  $handler->display->display_options['fields']['field_specialty_designation']['id'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['table'] = 'field_data_field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['field'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['label'] = '';
  $handler->display->display_options['fields']['field_specialty_designation']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_specialty_designation']['alter']['text'] = ', [field_specialty_designation]</p>';
  $handler->display->display_options['fields']['field_specialty_designation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_specialty_designation']['separator'] = '';
  /* Field: User: Blog Description */
  $handler->display->display_options['fields']['field_blog_description']['id'] = 'field_blog_description';
  $handler->display->display_options['fields']['field_blog_description']['table'] = 'field_data_field_blog_description';
  $handler->display->display_options['fields']['field_blog_description']['field'] = 'field_blog_description';
  $handler->display->display_options['fields']['field_blog_description']['label'] = '';
  $handler->display->display_options['fields']['field_blog_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_blog_description']['alter']['text'] = '<p class="blog-description-text">[field_blog_description]</p>';
  $handler->display->display_options['fields']['field_blog_description']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['field_blog_description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_blog_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_description']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'blogs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Blogs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-community';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['blogs'] = $view;

  return $export;
}
