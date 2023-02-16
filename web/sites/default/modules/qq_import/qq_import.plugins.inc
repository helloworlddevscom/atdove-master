<?php

/**
 * @file
 * Contains default importer for quiz questions
 */

/**
 * Implements hook_ctools_plugin_api()
 */
function qq_import_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == 'feeds' && $api == 'feeds_importer_default') {
    return array('version' => 1);
  }
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function qq_import_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'long_answer';
  $feeds_importer->config = array(
    'name' => 'Long answer question',
    'description' => 'Importer for long answer question.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'long_answer',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'Question',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Rubric text',
            'target' => 'long_answer_rubric',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => '1',
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );

  $export['long_answer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'matching';
  $feeds_importer->config = array(
    'name' => 'Matching',
    'description' => 'Importer for matching question',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'matching',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'match1',
            'target' => 'matching_answer',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'match2',
            'target' => 'matching_answer',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'match3',
            'target' => 'matching_answer',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'match4',
            'target' => 'matching_answer',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'filtered_html',
        'author' => '1',
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );
  $export['matching'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'multichoice';
  $feeds_importer->config = array(
  'name' => 'Multichoice',
  'description' => 'Importer for multichoice questions. See http://example.com/admin/quiz/import to set default values.',
  'fetcher' => array(
    'plugin_key' => 'FeedsFileFetcher',
    'config' => array(
      'direct' => FALSE,
      'allowed_extensions' => 'txt csv tsv xml opml',
      'directory' => 'public://feeds',
      'allowed_schemes' => array(
        0 => 'public',
      ),
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'bundle' => 'multichoice',
      'update_existing' => '1',
      'expire' => '-1',
      'mappings' => array(
        0 => array(
          'source' => 'guid',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'question',
          'target' => 'body',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'correct answer',
          'target' => 'multichoice_alternative_correct',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'wrong answer 1',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'wrong answer 2',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
        5 => array(
          'source' => 'wrong answer 3',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
        6 => array(
          'source' => 'wrong answer 4',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
        7 => array(
          'source' => 'wrong answer 5',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
      ),
      'input_format' => 'plain_text',
      'author' => 1,
      'authorize' => 1,
      'skip_hash_check' => 0,
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => FALSE,
  );

  $export['multichoice'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'short_answer';
  $feeds_importer->config = array(
    'name' => 'Short Answer',
    'description' => 'Importer for short answer question. Evaluation code values: 0 – automatic & case sensitive, 1- automatic & case insensitive, 2 - regex, 3 – manual',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'short_answer',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'question',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'answer',
            'target' => 'short_answer_correct_answer',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'evaluation code',
            'target' => 'short_answer_evaluation',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => '1',
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );
  $export['short_answer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'truefalse';
  $feeds_importer->config = array(
  'name' => 'True or False',
  'description' => 'Importer for True/False questions. In import file mention 1 for true and 0 false.',
  'fetcher' => array(
    'plugin_key' => 'FeedsFileFetcher',
    'config' => array(
      'direct' => FALSE,
      'allowed_extensions' => 'txt csv tsv xml opml',
      'directory' => 'public://feeds',
      'allowed_schemes' => array(
        0 => 'public',
      ),
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'bundle' => 'truefalse',
      'update_existing' => '1',
      'expire' => '-1',
      'mappings' => array(
        0 => array(
          'source' => 'guid',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'title',
          'target' => 'title',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'body',
          'target' => 'body',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'answer',
          'target' => 'truefalse_answer',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'feedback',
          'target' => 'truefalse_feedback',
          'unique' => FALSE,
        ),
      ),
      'input_format' => 'filtered_html',
      'author' => 1,
      'authorize' => 1,
      'skip_hash_check' => 0,
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => FALSE,
  );
  $export['truefalse'] = $feeds_importer;

  return $export;
}
