<?php
/**
 * @file
 * flags_for_dove.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function flags_for_dove_flag_default_flags() {
  $flags = array();
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'entity_type' => 'node',
    'title' => 'Bookmarks',
    'global' => 0,
    'types' => array(
      0 => 'article',
      1 => 'blog',
      2 => 'faq',
      3 => 'help_topic',
      4 => 'video',
    ),
    'flag_short' => 'Add To<br />Bookmarks',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove From<br />Bookmarks',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'question' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'flags_for_dove',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
