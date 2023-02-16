<?php
/**
 * @file
 * helptopic_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function helptopic_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|help_topic|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'help_topic';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Help Topics',
    'weight' => '7',
    'children' => array(
      0 => 'field_related_help_topics',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Related Help Topics',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related|node|help_topic|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related Help Topics');

  return $field_groups;
}
