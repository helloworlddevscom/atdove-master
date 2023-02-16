<?php
/**
 * @file
 * atdove_import.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function atdove_import_default_rules_configuration() {
  $items = array();
  $items['rules_add_questions_to_quiz_on_import'] = entity_import('rules_config', '{ "rules_add_questions_to_quiz_on_import" : {
      "LABEL" : "Add questions to quiz on import",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "feeds" ],
      "ON" : { "feeds_import_multichoice" : [] },
      "DO" : [
        { "php_eval" : { "code" : "jeff_import_hookup_quiz_questions($node);" } }
      ]
    }
  }');
  return $items;
}
