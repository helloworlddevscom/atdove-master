<?php

/**
 * @file
 * Multilingual support.
 */

/**
 * Implements hook_variable_info().
 */
function olark_variable_info($options) {
  $variables['olark_code'] = array(
    'type' => 'text',
    'title' => t('Olark Code', array(), $options),
    'description' => t('Olark Code and settings.', array(), $options),
    'required' => TRUE,
    'localize' => TRUE,
    'group' => 'olark',
  );

  return $variables;
}

/**
 * Implements hook_variable_group_info().
 */
function olark_variable_group_info() {
  $groups['olark'] = array(
    'title' => t('Olark'),
    'description' => t('Olark Code and settings.'),
    'access' => 'administer site configuration',
  );

  return $groups;
}
