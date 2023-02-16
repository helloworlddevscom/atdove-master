<?php
/**
 * @file
 * quiz_content_type.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function quiz_content_type_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_quiz-form-configuration:admin/quiz/settings/quiz_form
  $menu_links['management_quiz-form-configuration:admin/quiz/settings/quiz_form'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/quiz/settings/quiz_form',
    'router_path' => 'admin/quiz/settings/quiz_form',
    'link_title' => '@quiz form configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure default values for the quiz creation form.',
      ),
      'identifier' => 'management_quiz-form-configuration:admin/quiz/settings/quiz_form',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_quiz-settings:admin/quiz/settings',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('@quiz form configuration');

  return $menu_links;
}
