<?php
/**
 * @file
 * atdove_user_invitations.views.inc
 */

/**
 * Implements hook_views_data().
 */
function atdove_user_invitations_views_data() {
  $data = array();
  $data['atdove_invites']['table']['group'] = t('Invitations');
  $data['atdove_invites']['table']['base'] = array(
    'title' => t('Invitations'),
    'help' => t('Contains invitations extended to new and existing users.'),
  );

  $data['atdove_invites']['table']['join']['users'] = array(
    'left_field' => 'mail',
    'field' => 'email'
  );

  $data['atdove_invites']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'gid'
  );

  $data['atdove_invites']['id'] = array(
    'title' => t('ID'),
    'help' => t('The record ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
  );

  $data['atdove_invites']['subgroup'] = array(
    'title' => t('Subgroup'),
    'help' => t('The subgroup ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Subgroup Relationship'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
  );

  $data['atdove_invites']['gid'] = array(
    'title' => t('Group ID'),
    'help' => t('The group ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'relationship' => array(
      'base' => 'node',
      'field' => 'gid',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Group'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
  );

  $data['atdove_invites']['email'] = array(
    'title' => t('Email'),
    'help' => t('The invitee\'s email/username.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'email',
      'base field' => 'mail',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'numeric' => FALSE,
      'validate type' => 'string',
    ),
  );

  $data['atdove_invites']['new_user'] = array(
    'title' => t('New User'),
    'help' => t('Whether the user is new or existing.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
  );

  $data['atdove_invites']['active'] = array(
    'title' => t('Active'),
    'help' => t('Whether the invitation is still pending.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
  );

  $data['atdove_invites']['accepted'] = array(
    'title' => t('Accepted'),
    'help' => t('Whether the invitee has accepted.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
  );

  $data['atdove_invites']['created'] = array(
    'title' => t('Created On'),
    'help' => t('The date this invitation was first created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
