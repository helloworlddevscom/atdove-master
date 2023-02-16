<?php
/**
 * @file
 * user_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function user_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    4 => '4',
    8 => '8',
    9 => '9',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href="[edit_node]">Edit Profile</a>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-profile';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Profile';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: User: Designations */
  $handler->display->display_options['fields']['field_designations']['id'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['table'] = 'field_data_field_designations';
  $handler->display->display_options['fields']['field_designations']['field'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['label'] = '';
  $handler->display->display_options['fields']['field_designations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_designations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['delta_offset'] = '0';
  /* Field: User: Specialty Designation */
  $handler->display->display_options['fields']['field_specialty_designation']['id'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['table'] = 'field_data_field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['field'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['label'] = '';
  $handler->display->display_options['fields']['field_specialty_designation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<h2><?php if (!empty($row->field_first_name)) { print $row->field_first_name.\' \'.$row->field_last_name; } else { print $row->name; } ?><?php if (!empty($row->field_designations) || !empty($row->field_specialty_designation)) { print \', \'.$row->field_designations.\' \'.$row->field_specialty_designation; } ?></h2>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_title']['alter']['text'] = '<p class="profile-title">[field_title]</p>';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="profile-left-col">[picture][edit_node]</div>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-right-col">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['label'] = '';
  $handler->display->display_options['fields']['field_school']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school']['alter']['text'] = '<h3>Education:</h3>
<p class="profile-school">[field_school]</p>';
  $handler->display->display_options['fields']['field_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_graduation_date']['id'] = 'field_graduation_date';
  $handler->display->display_options['fields']['field_graduation_date']['table'] = 'field_data_field_graduation_date';
  $handler->display->display_options['fields']['field_graduation_date']['field'] = 'field_graduation_date';
  $handler->display->display_options['fields']['field_graduation_date']['label'] = '';
  $handler->display->display_options['fields']['field_graduation_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_graduation_date']['alter']['text'] = '<h3>Graduation Date:</h3>
<p>[field_graduation_date]</p>';
  $handler->display->display_options['fields']['field_graduation_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graduation_date']['element_default_classes'] = FALSE;
  /* Field: User: Current Institution, School or Practice  */
  $handler->display->display_options['fields']['field_current_school']['id'] = 'field_current_school';
  $handler->display->display_options['fields']['field_current_school']['table'] = 'field_data_field_current_school';
  $handler->display->display_options['fields']['field_current_school']['field'] = 'field_current_school';
  $handler->display->display_options['fields']['field_current_school']['label'] = '';
  $handler->display->display_options['fields']['field_current_school']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_current_school']['alter']['text'] = '<h3>Current School or Practice:</h3>
<p class="profile-current-school">[field_current_school]</p>';
  $handler->display->display_options['fields']['field_current_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_current_school']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pratice_start_year']['id'] = 'field_pratice_start_year';
  $handler->display->display_options['fields']['field_pratice_start_year']['table'] = 'field_data_field_pratice_start_year';
  $handler->display->display_options['fields']['field_pratice_start_year']['field'] = 'field_pratice_start_year';
  $handler->display->display_options['fields']['field_pratice_start_year']['label'] = '';
  $handler->display->display_options['fields']['field_pratice_start_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pratice_start_year']['alter']['text'] = '<h3>Year Started Practicing:</h3>
<span>[field_pratice_start_year]</span>';
  $handler->display->display_options['fields']['field_pratice_start_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pratice_start_year']['element_default_classes'] = FALSE;
  /* Field: User: Professional Memberships */
  $handler->display->display_options['fields']['field_professional_memberships']['id'] = 'field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['table'] = 'field_data_field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['field'] = 'field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['label'] = '';
  $handler->display->display_options['fields']['field_professional_memberships']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_memberships']['alter']['text'] = '<h3>Professional Memberships:</h3>
<p class="profile-memberships">[field_professional_memberships]</p>';
  $handler->display->display_options['fields']['field_professional_memberships']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_memberships']['element_default_classes'] = FALSE;
  /* Field: User: Professional Interests */
  $handler->display->display_options['fields']['field_professional_interests']['id'] = 'field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['table'] = 'field_data_field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['field'] = 'field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['label'] = '';
  $handler->display->display_options['fields']['field_professional_interests']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_interests']['alter']['text'] = '<h3>Professional Interests:</h3>
<p>[field_professional_interests]</p>';
  $handler->display->display_options['fields']['field_professional_interests']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_interests']['element_default_classes'] = FALSE;
  /* Field: User: Practice Type */
  $handler->display->display_options['fields']['field_practice_type']['id'] = 'field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['table'] = 'field_data_field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['field'] = 'field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['label'] = '';
  $handler->display->display_options['fields']['field_practice_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_practice_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_practice_type']['delta_offset'] = '0';
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bio']['alter']['text'] = '<h3>Bio:</h3>
<span>[field_bio]</span>';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio']['element_default_classes'] = FALSE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = '<h3>My Links:</h3>
<a href="[field_website-url]" target="_blank">[field_website-title]</a>';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_title_plain';
  /* Field: User: LinkedIn URL */
  $handler->display->display_options['fields']['field_linkedin_url']['id'] = 'field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['table'] = 'field_data_field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['field'] = 'field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['label'] = '';
  $handler->display->display_options['fields']['field_linkedin_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_linkedin_url']['alter']['text'] = '<a href="[field_linkedin_url-url]" target="_blank">LinkedIn</a>';
  $handler->display->display_options['fields']['field_linkedin_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_linkedin_url']['type'] = 'link_title_plain';
  /* Field: User: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_url']['alter']['text'] = '<a href="[field_twitter_url-url]" target="_blank">Twitter</a>';
  $handler->display->display_options['fields']['field_twitter_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_twitter_url']['type'] = 'link_title_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';

  /* Display: User Profile view */
  $handler = $view->new_display('page', 'User Profile view', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href="[edit_node]">Edit Profile</a>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-profile';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Profile';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: User: Designations */
  $handler->display->display_options['fields']['field_designations']['id'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['table'] = 'field_data_field_designations';
  $handler->display->display_options['fields']['field_designations']['field'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['label'] = '';
  $handler->display->display_options['fields']['field_designations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_designations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['delta_offset'] = '0';
  /* Field: User: Specialty Designation */
  $handler->display->display_options['fields']['field_specialty_designation']['id'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['table'] = 'field_data_field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['field'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['label'] = '';
  $handler->display->display_options['fields']['field_specialty_designation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<h2><?php if (!empty($row->field_first_name)) { print $row->field_first_name.\' \'.$row->field_last_name; } else { print $row->name; } ?><?php if (!empty($row->field_designations) || !empty($row->field_specialty_designation)) { print \', \'.$row->field_designations.\' \'.$row->field_specialty_designation; } ?></h2>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_title']['alter']['text'] = '<p class="profile-title">[field_title]</p>';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="profile-left-col">[picture][edit_node]</div>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-right-col">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Message User link */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Message User link';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
global $user;
$uid = $row->uid;
if ($user->uid != $uid) {
  print \'<a class="message-user-button" href="/messages/new/\' . $uid . \'">Message User</a>\';
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: User: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['label'] = '';
  $handler->display->display_options['fields']['field_school']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school']['alter']['text'] = '<h3>Education:</h3>
<p class="profile-school">[field_school]</p>';
  $handler->display->display_options['fields']['field_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school']['element_default_classes'] = FALSE;
  /* Field: User: Current Institution, School or Practice  */
  $handler->display->display_options['fields']['field_current_school']['id'] = 'field_current_school';
  $handler->display->display_options['fields']['field_current_school']['table'] = 'field_data_field_current_school';
  $handler->display->display_options['fields']['field_current_school']['field'] = 'field_current_school';
  $handler->display->display_options['fields']['field_current_school']['label'] = '';
  $handler->display->display_options['fields']['field_current_school']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_current_school']['alter']['text'] = '<h3>Current School or Practice:</h3>
<p class="profile-current-school">[field_current_school]</p>';
  $handler->display->display_options['fields']['field_current_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_current_school']['element_default_classes'] = FALSE;
  /* Field: User: Professional Memberships */
  $handler->display->display_options['fields']['field_professional_memberships']['id'] = 'field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['table'] = 'field_data_field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['field'] = 'field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['label'] = '';
  $handler->display->display_options['fields']['field_professional_memberships']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_memberships']['alter']['text'] = '<h3>Professional Memberships:</h3>
<p class="profile-memberships">[field_professional_memberships]</p>';
  $handler->display->display_options['fields']['field_professional_memberships']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_memberships']['element_default_classes'] = FALSE;
  /* Field: User: Professional Interests */
  $handler->display->display_options['fields']['field_professional_interests']['id'] = 'field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['table'] = 'field_data_field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['field'] = 'field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['label'] = '';
  $handler->display->display_options['fields']['field_professional_interests']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_interests']['alter']['text'] = '<h3>Professional Interests:</h3>
<p>[field_professional_interests]</p>';
  $handler->display->display_options['fields']['field_professional_interests']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_interests']['element_default_classes'] = FALSE;
  /* Field: User: Practice Type */
  $handler->display->display_options['fields']['field_practice_type']['id'] = 'field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['table'] = 'field_data_field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['field'] = 'field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['label'] = '';
  $handler->display->display_options['fields']['field_practice_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_practice_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_practice_type']['delta_offset'] = '0';
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bio']['alter']['text'] = '<h3>Bio:</h3>
<span>[field_bio]</span>';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio']['element_default_classes'] = FALSE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = '<h3>My Links:</h3>
<a href="[field_website-url]" target="_blank">[field_website-title]</a>';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_title_plain';
  /* Field: User: LinkedIn URL */
  $handler->display->display_options['fields']['field_linkedin_url']['id'] = 'field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['table'] = 'field_data_field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['field'] = 'field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['label'] = '';
  $handler->display->display_options['fields']['field_linkedin_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_linkedin_url']['alter']['text'] = '<a href="[field_linkedin_url-url]" target="_blank">LinkedIn</a>';
  $handler->display->display_options['fields']['field_linkedin_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_linkedin_url']['type'] = 'link_title_plain';
  /* Field: User: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_url']['alter']['text'] = '<a href="[field_twitter_url-url]" target="_blank">Twitter</a>';
  $handler->display->display_options['fields']['field_twitter_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_twitter_url']['type'] = 'link_title_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
$query = "select * from node as n
join field_data_field_contributors as c on c.entity_id = n.nid 
where c.field_contributors_target_id = :uid AND n.status = 1";
$results = db_query($query, array(\':uid\' => $row->uid));
if ($results->rowCount()) {
  print "<div class=\'contributed-profile-wrapper\'><h2 class=\'contributed-h2\'>Contributed content:</h2>";
}
foreach($results as $item) {
  print "<p class=\'contributed\'><a href=\'/node/$item->nid\'>$item->title</a></p>";
}
if ($results->rowCount()) {
  print "</div>";
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['uid']['validate_options']['code'] = 'global $user;
$other = user_load($argument);
$is_admin = isset($other->field_public_profile[\'und\'][\'0\'][\'value\']) ? $other->field_public_profile[\'und\'][\'0\'][\'value\'] : 0;
if ($user->uid == $argument || $is_admin == 1 || in_array(\'administrator\', $user->roles) || organization_control_orgID($user) == organization_control_orgID($other)) {
 return TRUE;
}';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'user-profile/%';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Account';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Currect user profile view */
  $handler = $view->new_display('page', 'Currect user profile view', 'page_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href="[edit_node]">Edit Profile</a>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['edit_node']['element_wrapper_class'] = 'edit-profile';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Profile';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: User: Designations */
  $handler->display->display_options['fields']['field_designations']['id'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['table'] = 'field_data_field_designations';
  $handler->display->display_options['fields']['field_designations']['field'] = 'field_designations';
  $handler->display->display_options['fields']['field_designations']['label'] = '';
  $handler->display->display_options['fields']['field_designations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_designations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_designations']['delta_offset'] = '0';
  /* Field: User: Specialty Designation */
  $handler->display->display_options['fields']['field_specialty_designation']['id'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['table'] = 'field_data_field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['field'] = 'field_specialty_designation';
  $handler->display->display_options['fields']['field_specialty_designation']['label'] = '';
  $handler->display->display_options['fields']['field_specialty_designation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_specialty_designation']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<h2><?php if (!empty($row->field_first_name)) { print $row->field_first_name.\' \'.$row->field_last_name; } else { print $row->name; } ?><?php if (!empty($row->field_designations) || !empty($row->field_specialty_designation)) { print \', \'.$row->field_designations.\' \'.$row->field_specialty_designation; } ?></h2>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_title']['alter']['text'] = '<p class="profile-title">[field_title]</p>';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<div class="profile-left-col">[picture][edit_node]</div>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-right-col">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['label'] = '';
  $handler->display->display_options['fields']['field_school']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school']['alter']['text'] = '<h3>Education:</h3>
<p class="profile-school">[field_school]</p>';
  $handler->display->display_options['fields']['field_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_graduation_date']['id'] = 'field_graduation_date';
  $handler->display->display_options['fields']['field_graduation_date']['table'] = 'field_data_field_graduation_date';
  $handler->display->display_options['fields']['field_graduation_date']['field'] = 'field_graduation_date';
  $handler->display->display_options['fields']['field_graduation_date']['label'] = '';
  $handler->display->display_options['fields']['field_graduation_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_graduation_date']['alter']['text'] = '<h3>Graduation Date:</h3>
<p>[field_graduation_date]</p>';
  $handler->display->display_options['fields']['field_graduation_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_graduation_date']['element_default_classes'] = FALSE;
  /* Field: User: Current Institution, School or Practice  */
  $handler->display->display_options['fields']['field_current_school']['id'] = 'field_current_school';
  $handler->display->display_options['fields']['field_current_school']['table'] = 'field_data_field_current_school';
  $handler->display->display_options['fields']['field_current_school']['field'] = 'field_current_school';
  $handler->display->display_options['fields']['field_current_school']['label'] = '';
  $handler->display->display_options['fields']['field_current_school']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_current_school']['alter']['text'] = '<h3>Current School or Practice:</h3>
<p class="profile-current-school">[field_current_school]</p>';
  $handler->display->display_options['fields']['field_current_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_current_school']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pratice_start_year']['id'] = 'field_pratice_start_year';
  $handler->display->display_options['fields']['field_pratice_start_year']['table'] = 'field_data_field_pratice_start_year';
  $handler->display->display_options['fields']['field_pratice_start_year']['field'] = 'field_pratice_start_year';
  $handler->display->display_options['fields']['field_pratice_start_year']['label'] = '';
  $handler->display->display_options['fields']['field_pratice_start_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pratice_start_year']['alter']['text'] = '<h3>Year Started Practicing:</h3>
<span>[field_pratice_start_year]</span>';
  $handler->display->display_options['fields']['field_pratice_start_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pratice_start_year']['element_default_classes'] = FALSE;
  /* Field: User: Professional Memberships */
  $handler->display->display_options['fields']['field_professional_memberships']['id'] = 'field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['table'] = 'field_data_field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['field'] = 'field_professional_memberships';
  $handler->display->display_options['fields']['field_professional_memberships']['label'] = '';
  $handler->display->display_options['fields']['field_professional_memberships']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_memberships']['alter']['text'] = '<h3>Professional Memberships:</h3>
<p class="profile-memberships">[field_professional_memberships]</p>';
  $handler->display->display_options['fields']['field_professional_memberships']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_memberships']['element_default_classes'] = FALSE;
  /* Field: User: Professional Interests */
  $handler->display->display_options['fields']['field_professional_interests']['id'] = 'field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['table'] = 'field_data_field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['field'] = 'field_professional_interests';
  $handler->display->display_options['fields']['field_professional_interests']['label'] = '';
  $handler->display->display_options['fields']['field_professional_interests']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_interests']['alter']['text'] = '<h3>Professional Interests:</h3>
<p>[field_professional_interests]</p>';
  $handler->display->display_options['fields']['field_professional_interests']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_interests']['element_default_classes'] = FALSE;
  /* Field: User: Practice Type */
  $handler->display->display_options['fields']['field_practice_type']['id'] = 'field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['table'] = 'field_data_field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['field'] = 'field_practice_type';
  $handler->display->display_options['fields']['field_practice_type']['label'] = '';
  $handler->display->display_options['fields']['field_practice_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_practice_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_practice_type']['delta_offset'] = '0';
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bio']['alter']['text'] = '<h3>Bio:</h3>
<span>[field_bio]</span>';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio']['element_default_classes'] = FALSE;
  /* Field: Field: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = '<h3>My Links:</h3>
<a href="[field_website-url]" target="_blank">[field_website-title]</a>';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_title_plain';
  /* Field: User: LinkedIn URL */
  $handler->display->display_options['fields']['field_linkedin_url']['id'] = 'field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['table'] = 'field_data_field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['field'] = 'field_linkedin_url';
  $handler->display->display_options['fields']['field_linkedin_url']['label'] = '';
  $handler->display->display_options['fields']['field_linkedin_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_linkedin_url']['alter']['text'] = '<a href="[field_linkedin_url-url]" target="_blank">LinkedIn</a>';
  $handler->display->display_options['fields']['field_linkedin_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_linkedin_url']['type'] = 'link_title_plain';
  /* Field: User: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_url']['alter']['text'] = '<a href="[field_twitter_url-url]" target="_blank">Twitter</a>';
  $handler->display->display_options['fields']['field_twitter_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_twitter_url']['type'] = 'link_title_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
$query = "select * from node as n
join field_data_field_contributors as c on c.entity_id = n.nid 
where c.field_contributors_target_id = :uid";
$results = db_query($query, array(\':uid\' => $row->uid));
if ($results->rowCount()) {
  print "<div class=\'contributed-profile-wrapper\'><h2 class=\'contributed-h2\'>Contributed content:</h2>";
}
foreach($results as $item) {
  print "<p class=\'contributed\'><a href=\'/node/$item->nid\'>$item->title</a></p>";
}
if ($results->rowCount()) {
  print "</div>";
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'user-profile';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Account';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['user_profile'] = $view;

  return $export;
}
