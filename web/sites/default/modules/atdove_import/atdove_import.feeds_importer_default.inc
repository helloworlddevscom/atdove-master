<?php
/**
 * @file
 * atdove_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function atdove_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'accreditations_field_collections';
  $feeds_importer->config = array(
    'name' => 'Accreditations Field Collections',
    'description' => 'Import accr. as field collections from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_accreditation_info',
        'host_entity_type' => 'node',
        'is_field' => 0,
        'guid_field_name' => 'uuid',
        'identifier_field_name' => 'uuid',
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'quiz_accreditation',
            'target' => 'field_accreditations',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'quiz_race_id',
            'target' => 'field_accreditation_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'field_accreditation_info',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['accreditations_field_collections'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ads';
  $feeds_importer->config = array(
    'name' => 'Ads',
    'description' => 'Import ad nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'embed_code',
            'target' => 'body',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'related_blogs',
            'target' => 'field_related_blog',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'related_videos',
            'target' => 'field_related_videos',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'related_articles',
            'target' => 'field_related_articles',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'ad',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ads'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'announcements';
  $feeds_importer->config = array(
    'name' => 'Announcements',
    'description' => 'Import announcement nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'announcement',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['announcements'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'article_comments';
  $feeds_importer->config = array(
    'name' => 'Article Comments',
    'description' => 'Import article comments from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'comment',
            'target' => 'comment_body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'createdBy',
            'target' => 'user_mail',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'createdBy',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'resource_id',
            'target' => 'nid_by_guid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'comment_node_article',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['article_comments'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'articles';
  $feeds_importer->config = array(
    'name' => 'Articles',
    'description' => 'Import article (resource) nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'file_name',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'pdf_name',
            'target' => 'field_pdf_version:uri',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'related_ads',
            'target' => 'field_related_ads',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'related_blogs',
            'target' => 'field_related_blog',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'related_videos',
            'target' => 'field_related_videos',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'related_articles',
            'target' => 'field_related_articles',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'related_surveys',
            'target' => 'field_related_surveys',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'related_tags',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          19 => array(
            'source' => 'related_tags',
            'target' => 'field_content_category',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          20 => array(
            'source' => 'related_tags',
            'target' => 'field_additional_content_categor',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          21 => array(
            'source' => 'related_quizzes',
            'target' => 'field_related_quiz',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'contributors',
            'target' => 'field_contributors:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['articles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'assignments';
  $feeds_importer->config = array(
    'name' => 'Assignments',
    'description' => 'Import assignments from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'author',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'resource_id',
            'target' => 'field_assigned_content',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'program_id',
            'target' => 'field_related_trainingplan',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'member_id',
            'target' => 'field_assignee:label',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'instructions',
            'target' => 'body',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'assignment_id',
            'target' => 'title',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'due_date',
            'target' => 'field_due_date:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'assignment',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['assignments'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'blog_comments';
  $feeds_importer->config = array(
    'name' => 'Blog comments',
    'description' => 'Import blog comments from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'comment',
            'target' => 'comment_body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'createdBy',
            'target' => 'user_mail',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'createdBy',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'resource_id',
            'target' => 'nid_by_guid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'comment_node_blog',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['blog_comments'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'blogs';
  $feeds_importer->config = array(
    'name' => 'Blogs',
    'description' => 'Import blog nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'related_ads',
            'target' => 'field_related_ads',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'related_blogs',
            'target' => 'field_related_blog',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'related_videos',
            'target' => 'field_related_videos',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'related_articles',
            'target' => 'field_related_articles',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'related_surveys',
            'target' => 'field_related_surveys',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'related_tags',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          17 => array(
            'source' => 'related_tags',
            'target' => 'field_content_category',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          18 => array(
            'source' => 'related_tags',
            'target' => 'field_additional_content_categor',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          19 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'contributors',
            'target' => 'field_contributors:label',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'blog',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['blogs'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'faq_import';
  $feeds_importer->config = array(
    'name' => 'FAQ import',
    'description' => 'Import faq nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'question',
            'target' => 'title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'answer',
            'target' => 'body',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'related_help',
            'target' => 'field_related_help_topics',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'faq',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['faq_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'groups';
  $feeds_importer->config = array(
    'name' => 'Groups',
    'description' => 'Import orgs from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'notes',
            'target' => 'field_notes',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'sponsorFile_name',
            'target' => 'field_sponsor_logo:uri',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'sponsorName',
            'target' => 'field_sponsor_name',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'sponsorLink',
            'target' => 'field_sponsor_link:url',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'recordID',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'organization',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['groups'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'help_import';
  $feeds_importer->config = array(
    'name' => 'Help Import',
    'description' => 'Import helpContent nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'file_name',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'related_tags',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          13 => array(
            'source' => 'related_faqs',
            'target' => 'field_related_faqs',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'related_help',
            'target' => 'field_related_help_topics:etid',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'help_topic',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['help_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'quizzes';
  $feeds_importer->config = array(
    'name' => 'Quizzes',
    'description' => 'Import quiz(test) nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'file_name',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'related_videos',
            'target' => 'field_related_videos',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'related_articles',
            'target' => 'field_related_articles',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'quiz',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['quizzes'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'subgroups';
  $feeds_importer->config = array(
    'name' => 'Subgroups',
    'description' => 'Import subgroups (organizational groups) from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'subgroup_title',
            'target' => 'field_actual_group_name',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'temp_subgroup_title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'temp_subgroup_title',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'organizational_groups',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['subgroups'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'training_plans';
  $feeds_importer->config = array(
    'name' => 'Training Plans',
    'description' => 'Import training plans from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'related_videos',
            'target' => 'field_related_videos',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'related_articles',
            'target' => 'field_related_articles',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'training_plan',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['training_plans'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'users';
  $feeds_importer->config = array(
    'name' => 'Users',
    'description' => 'Import users from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'fname',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'lname',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'username',
            'target' => 'name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'username',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'extended_bio',
            'target' => 'field_bio',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'temp_org_grp_name',
            'target' => 'og_user_node1:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'organization_id',
            'target' => 'og_user_node',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'organization_status',
            'target' => 'og_roles',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'file_name',
            'target' => 'picture',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['users'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'video_comments';
  $feeds_importer->config = array(
    'name' => 'Video Comments',
    'description' => 'Import video comments from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'comment',
            'target' => 'comment_body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'createdBy',
            'target' => 'user_mail',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'createdBy',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'resource_id',
            'target' => 'nid_by_guid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'comment_node_video',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['video_comments'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'videos';
  $feeds_importer->config = array(
    'name' => 'Videos',
    'description' => 'Import video nodes from old site',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'uuid:uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'seo_title',
            'target' => 'meta_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'seo_description',
            'target' => 'meta_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'seo_keywords',
            'target' => 'meta_keywords',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'seo_url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'featured_name',
            'target' => 'field_featured_image:uri',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'file_name',
            'target' => 'field_image:uri',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'length',
            'target' => 'field_duration',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'wistia_paid_video_embed',
            'target' => 'field_wistia_iframe_logged_in_ac',
            'format' => 'full_html',
          ),
          12 => array(
            'source' => 'wistia_public_anon_video_embed',
            'target' => 'field_wistia_iframe_logged_in_no',
            'format' => 'full_html',
          ),
          13 => array(
            'source' => 'wistia_public_video_embed',
            'target' => 'field_wistia_iframe_logged_in_ac',
            'format' => 'full_html',
          ),
          14 => array(
            'source' => 'related_ads',
            'target' => 'field_related_ads',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'related_blogs',
            'target' => 'field_related_blog',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'related_videos',
            'target' => 'field_related_videos',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'author',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'related_articles',
            'target' => 'field_related_articles',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'related_surveys',
            'target' => 'field_related_surveys',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'related_tags',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          21 => array(
            'source' => 'related_tags',
            'target' => 'field_content_category',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          22 => array(
            'source' => 'related_tags',
            'target' => 'field_additional_content_categor',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          23 => array(
            'source' => 'related_quizzes',
            'target' => 'field_related_quiz',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'deleted',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'active',
            'target' => 'status',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'contributors',
            'target' => 'field_contributors:label',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'video_type',
            'target' => 'field_premium',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'summary',
            'target' => 'body',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'additional_downloads',
            'target' => 'field_additional_downloads:uri',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'video',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['videos'] = $feeds_importer;

  return $export;
}
