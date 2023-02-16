<?php
/**
 * @file
 * commerce_more_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_more_rules_default_rules_configuration() {
  $items = array();
  $items['commerce_for_dl_new_user_checkout_only_checkout_page_'] = entity_import('rules_config', '{ "commerce_for_dl_new_user_checkout_only_checkout_page_" : {
      "LABEL" : "New User Checkout Only (checkout page)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_cart", "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_pane" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : {
                "2" : "2",
                "3" : "3",
                "11" : "11",
                "16" : "16",
                "4" : "4",
                "5" : "5",
                "6" : "6",
                "7" : "7",
                "9" : "9",
                "8" : "8",
                "21" : "21"
              }
            },
            "operation" : "OR"
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "commerce-order:owner" ],
            "roles" : { "value" : { "10" : "10" } }
          }
        }
      ],
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "commerce-order" ] } },
        { "drupal_message" : { "message" : "Since you already have an account, \\u003Ca href=\\u0027\\/contact-us\\u0027\\u003EContact Us\\u003C\\/a\\u003E for a new subscription." } },
        { "redirect" : { "url" : "\\/future-billing" } }
      ]
    }
  }');
  return $items;
}
