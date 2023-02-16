<?php
/**
 * @file
 * users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function users_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address_information|user|user|form';
  $field_group->group_name = 'group_address_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Address Information',
    'weight' => '22',
    'children' => array(
      0 => 'field_city',
      1 => 'field_country',
      2 => 'field_phone',
      3 => 'field_postal_code',
      4 => 'field_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Address Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-address-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_address_information|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultant_information|user|user|form';
  $field_group->group_name = 'group_consultant_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Consultant Information',
    'weight' => '24',
    'children' => array(
      0 => 'field_consultant',
      1 => 'field_consultant_expert_in',
      2 => 'field_consultant_extended_bio',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Consultant Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-consultant-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_consultant_information|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_information|user|user|form';
  $field_group->group_name = 'group_organization_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organization Information',
    'weight' => '25',
    'children' => array(
      0 => 'og_user_node',
      1 => 'og_user_node1',
      2 => 'field_org_employee_ids',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Organization Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-organization-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_organization_information|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_race_certification_info|user|user|form';
  $field_group->group_name = 'group_race_certification_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'R.A.C.E. Certification Information',
    'weight' => '26',
    'children' => array(
      0 => 'field_license_type',
      1 => 'field_license_id_number',
      2 => 'field_license_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-race-certification-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_race_certification_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secondary_information|user|user|form';
  $field_group->group_name = 'group_secondary_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Primary Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_age_range',
      1 => 'field_first_name',
      2 => 'field_gender',
      3 => 'field_last_name',
      4 => 'field_prefix',
      5 => 'field_suffix',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Primary Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-secondary-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_secondary_information|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Address Information');
  t('Consultant Information');
  t('Organization Information');
  t('Primary Information');
  t('R.A.C.E. Certification Information');

  return $field_groups;
}
