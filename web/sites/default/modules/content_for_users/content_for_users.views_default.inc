<?php
/**
 * @file
 * content_for_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function content_for_users_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_for_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content for Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Educational Videos and Articles for the Veterinarian Industry';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear Filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 0,
      ),
    ),
    'field_tags_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_content_category_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'type_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = '[field_special_class]';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'type' => 'type',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="view-header-inner-wrapper">
<h1><?php print ucwords(arg(1)); ?></h1>
<?php if( empty(arg(1)) ): ?>
<h1>All</h1>
<?php endif; ?>

<?php if( strtolower(arg(1))=="all" || empty(arg(1)) ): ?>
<p></p>
<?php endif; ?>

<?php if( strtolower(arg(1))=="veterinarian" ): ?>
<p>Whether you’re showing your staff how to perform a treatment or you’re looking to cross off a few CE hours with our RACE-approved lectures, we’ve got what you’re looking for.  </p>
<?php endif; ?>

<?php if( strtolower(arg(1))=="technician" ): ?>
<p>You’re on your way! Up-level your skills alongside our certified and specialized technicians, then bring your new skills straight to your next shift.  </p>
<?php endif; ?>

<?php if( strtolower(arg(1))=="assistant" ): ?>
<p>You’re essential to the hospital floor, and so is training! Keep building your skills with quick procedural videos and blogs straight from our veterinary team. </p>
<?php endif; ?>

<?php if( strtolower(arg(1))=="receptionist" ): ?>
<p>You’re on the front lines, so you always need to be prepared. Check out some of the lessons our client service managers, liaisons, and representatives have learned in their careers. </p>
<?php endif; ?>

<?php if( strtolower(arg(1))=="manager" ): ?>
<p>Ever feel like some days you’ve totally got this and other days you need a bit of help? We’ve been there. Read management blogs or watch a quick training video to get you back to 100%.</p>
<?php endif; ?>

</div>
<hr />
<div class="view-header-inner-wrapper with-border">
<h3>Filter Content</h3>
<p>Search, filter and sort the hundreds of videos, lectures, blogs and articles so you can find exactly what you’re looking for.</p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Flags: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Thumbnail */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image] ';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['empty'] = '<img src=\'/sites/atdove.org/themes/atdove/images/user-avatar.png\' width=\'220\' height=\'220\' />';
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<p class="type-span black-type" title="[type] Type Content">[type]</p>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h2 class="browse-title" title="Link To [title_1]">[title_1]</h2>';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['label'] = '';
  $handler->display->display_options['fields']['field_length']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_length']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_length']['alter']['text'] = '<span class="video-length">Length: [field_length-value] - </span>';
  $handler->display->display_options['fields']['field_length']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_length']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Job Category */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="comment-count">[comment_count] Comments</span>';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['exclude'] = TRUE;
  $handler->display->display_options['fields']['totalcount']['alter']['text'] = '<span class="view-count">[totalcount] Views - [comment_count] Comments</span>';
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<span class="browse-body">[body-value]</span>';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '230';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Duration (in seconds) */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
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
  $handler->display->display_options['fields']['field_premium']['label'] = '';
  $handler->display->display_options['fields']['field_premium']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_premium']['alter']['text'] = '<span class="views-footer-detail">[field_premium]</span>';
  $handler->display->display_options['fields']['field_premium']['element_label_colon'] = FALSE;
  /* Field: Content: Accreditation Info */
  $handler->display->display_options['fields']['field_accreditation_info']['id'] = 'field_accreditation_info';
  $handler->display->display_options['fields']['field_accreditation_info']['table'] = 'field_data_field_accreditation_info';
  $handler->display->display_options['fields']['field_accreditation_info']['field'] = 'field_accreditation_info';
  $handler->display->display_options['fields']['field_accreditation_info']['label'] = '';
  $handler->display->display_options['fields']['field_accreditation_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accreditation_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accreditation_info']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_accreditation_info']['delta_offset'] = '0';
  /* Field: Content: Accredited For */
  $handler->display->display_options['fields']['field_accredited_for']['id'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['table'] = 'field_data_field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['field'] = 'field_accredited_for';
  $handler->display->display_options['fields']['field_accredited_for']['label'] = '';
  $handler->display->display_options['fields']['field_accredited_for']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accredited_for']['element_label_colon'] = FALSE;
  /* Field: Content: Credit Hours */
  $handler->display->display_options['fields']['field_credit_hours']['id'] = 'field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['table'] = 'field_data_field_credit_hours';
  $handler->display->display_options['fields']['field_credit_hours']['field'] = 'field_credit_hours';
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
if (isset($data->field_field_accreditation_info[0][\'raw\'][\'value\'])) {
  $term = $data->field_field_accreditation_info[0][\'raw\'][\'value\'];
  $accreditation = $data->field_field_accreditation_info[0][\'rendered\'][\'entity\'][\'field_collection_item\'][$term][\'field_accreditations\'][0][\'#title\'];
  if(isset($data->field_field_credit_hours[0][\'raw\'][\'value\'])) {
    $credits = $data->field_field_credit_hours[0][\'raw\'][\'value\'];
    if($credits == 1) {$hours = " Credit";} else {$hours = " Credits";}
	$accreditation .= \' - \'. $credits . $hours;
  }
  print \'<p class="type-span">\' . $accreditation . \'</p>\'; 
}
if (isset($data->field_field_accreditation_info[1][\'raw\'][\'value\'])) {
	$term = $data->field_field_accreditation_info[1][\'raw\'][\'value\'];
	$accreditation = $data->field_field_accreditation_info[1][\'rendered\'][\'entity\'][\'field_collection_item\'][$term][\'field_accreditations\'][0][\'#title\'];
	if(isset($data->field_field_credit_hours[0][\'raw\'][\'value\'])) {
		$credits = $data->field_field_credit_hours[0][\'raw\'][\'value\'];
		if($credits == 1) {$hours = " Credit";} else {$hours = " Credits";}
		$accreditation .= \' - \'. $credits . $hours;
	}
	print \'<p class="type-span">\' . $accreditation . \'</p>\'; 
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: nodeType for CSS class */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['ui_name'] = 'nodeType for CSS class';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  /* Field: Assign to */
  $handler->display->display_options['fields']['nothing_6']['id'] = 'nothing_6';
  $handler->display->display_options['fields']['nothing_6']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_6']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_6']['ui_name'] = 'Assign to';
  $handler->display->display_options['fields']['nothing_6']['label'] = '';
  $handler->display->display_options['fields']['nothing_6']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_6']['alter']['text'] = '<a href="#" class="user-button-browse person allType[type_1]" data-id="[nid]" title="Assign to Person"></a>';
  $handler->display->display_options['fields']['nothing_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_6']['element_default_classes'] = FALSE;
  /* Field: Add to TP */
  $handler->display->display_options['fields']['nothing_7']['id'] = 'nothing_7';
  $handler->display->display_options['fields']['nothing_7']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_7']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_7']['ui_name'] = 'Add to TP';
  $handler->display->display_options['fields']['nothing_7']['label'] = '';
  $handler->display->display_options['fields']['nothing_7']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_7']['alter']['text'] = '<a href="#" class="user-button-browse training allType[type_1]" data-id="[nid]" title="Add To Training Plan"></a>';
  $handler->display->display_options['fields']['nothing_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_7']['element_default_classes'] = FALSE;
  /* Field: Content: PDF Version */
  $handler->display->display_options['fields']['field_pdf_version']['id'] = 'field_pdf_version';
  $handler->display->display_options['fields']['field_pdf_version']['table'] = 'field_data_field_pdf_version';
  $handler->display->display_options['fields']['field_pdf_version']['field'] = 'field_pdf_version';
  $handler->display->display_options['fields']['field_pdf_version']['label'] = '';
  $handler->display->display_options['fields']['field_pdf_version']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pdf_version']['alter']['text'] = '<a class="user-button-browse download" href="printpdf/[nid]" title="Download PDF"></a>';
  $handler->display->display_options['fields']['field_pdf_version']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_version']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_version']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_version']['type'] = 'file_url_plain';
  /* Field: Download Feature Message for Inactive Users */
  $handler->display->display_options['fields']['nothing_8']['id'] = 'nothing_8';
  $handler->display->display_options['fields']['nothing_8']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_8']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_8']['ui_name'] = 'Download Feature Message for Inactive Users';
  $handler->display->display_options['fields']['nothing_8']['label'] = '';
  $handler->display->display_options['fields']['nothing_8']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_8']['alter']['text'] = '<span class="user-button-browse downloadMsg allType[type_1]"><span class="tooltip">PDF and Downloads are a Premium Feature</span></span>';
  $handler->display->display_options['fields']['nothing_8']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['text'] = '<span class="bookmark-span" title="Bookmark This Content">[ops]</span>';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Bookmark Feature Message for Inactive Users */
  $handler->display->display_options['fields']['nothing_9']['id'] = 'nothing_9';
  $handler->display->display_options['fields']['nothing_9']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_9']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_9']['ui_name'] = 'Bookmark Feature Message for Inactive Users';
  $handler->display->display_options['fields']['nothing_9']['label'] = '';
  $handler->display->display_options['fields']['nothing_9']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_9']['alter']['text'] = '<span class="bookmarkMsg">
  <span class="flag-wrapper flag-bookmarks flag-bookmarks-4">
    <a rel="nofollow" class="flag unflag-action flag-link-toggle flag-processed">
        ADD TO<br />BOOKMARKS
    </a>
  </span>
  <span class="tooltip redTooltip">Bookmarking is a Premium Feature</span>
</span>';
  $handler->display->display_options['fields']['nothing_9']['element_label_colon'] = FALSE;
  /* Field: Content: Special Class */
  $handler->display->display_options['fields']['field_special_class']['id'] = 'field_special_class';
  $handler->display->display_options['fields']['field_special_class']['table'] = 'field_data_field_special_class';
  $handler->display->display_options['fields']['field_special_class']['field'] = 'field_special_class';
  $handler->display->display_options['fields']['field_special_class']['label'] = '';
  $handler->display->display_options['fields']['field_special_class']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_special_class']['element_label_colon'] = FALSE;
  /* Field: Image Div */
  $handler->display->display_options['fields']['nothing_11']['id'] = 'nothing_11';
  $handler->display->display_options['fields']['nothing_11']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_11']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_11']['ui_name'] = 'Image Div';
  $handler->display->display_options['fields']['nothing_11']['label'] = '';
  $handler->display->display_options['fields']['nothing_11']['alter']['text'] = '<div class="views-image-wrapper">
[field_image]
<div class="thumbnail-overlay"></div>
<span class="content-type-flag content-type-flag-[type]">[type]</span>
</div>';
  $handler->display->display_options['fields']['nothing_11']['element_label_colon'] = FALSE;
  /* Field: Content Div */
  $handler->display->display_options['fields']['nothing_10']['id'] = 'nothing_10';
  $handler->display->display_options['fields']['nothing_10']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_10']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_10']['ui_name'] = 'Content Div';
  $handler->display->display_options['fields']['nothing_10']['label'] = '';
  $handler->display->display_options['fields']['nothing_10']['alter']['text'] = '<div class="views-info-wrapper">
<h2>[title_1]</h2>
<span class="views-statistics">Views: [totalcount] - Comments: [comment_count]</span>
<p>[body]</p>
<div class="views-footer">[field_duration][field_premium][field_credit_hours]</div>
<div class="user-buttons">[nothing_6][nothing_7][nothing_8][nothing_9][ops]</div>
</div>';
  $handler->display->display_options['fields']['nothing_10']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['comment_count']['expose']['label'] = 'Comment count';
  /* Sort criterion: Content statistics: Total views */
  $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['totalcount']['expose']['label'] = 'Popularity';
  /* Sort criterion: Content statistics: Views today */
  $handler->display->display_options['sorts']['daycount']['id'] = 'daycount';
  $handler->display->display_options['sorts']['daycount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['daycount']['field'] = 'daycount';
  $handler->display->display_options['sorts']['daycount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['daycount']['expose']['label'] = 'Views today';
  /* Sort criterion: Content: Duration (in seconds) (field_duration) */
  $handler->display->display_options['sorts']['field_duration_value']['id'] = 'field_duration_value';
  $handler->display->display_options['sorts']['field_duration_value']['table'] = 'field_data_field_duration';
  $handler->display->display_options['sorts']['field_duration_value']['field'] = 'field_duration_value';
  $handler->display->display_options['sorts']['field_duration_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_duration_value']['expose']['label'] = 'Duration';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Job Category (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
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
  $handler->display->display_options['filters']['field_content_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_content_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_content_category_tid']['vocabulary'] = 'content_categories';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'blog' => 'blog',
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
  $handler->display->display_options['filters']['type_1']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type_1']['group_info']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['type_1']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
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
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_1' => 'title_1',
    'body' => 'body',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all';
  $export['content_for_users'] = $view;

  return $export;
}
