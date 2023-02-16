<?php
/**
 * @file
 * commerce_for_dl.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_for_dl_default_rules_configuration() {
  $items = array();
  $items['commerce_cardonfile_order_status_after_free_trial_auth'] = entity_import('rules_config', '{ "commerce_cardonfile_order_status_after_free_trial_auth" : {
      "LABEL" : "Activate a free trial",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-9",
      "OWNER" : "rules",
      "REQUIRES" : [
        "rules",
        "dl_billing_management",
        "commerce_order",
        "commerce_license",
        "entity"
      ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "checkout_payment" } }
      ],
      "DO" : [
        { "dl_billing_management_advance_free_trial" : { "order" : [ "commerce-order" ] } },
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "pending" } },
        { "commerce_license_activate_order_licenses" : { "commerce_order" : [ "commerce_order" ] } },
        { "dl_billing_management_set_free_trial_duration" : { "order" : [ "commerce-order" ] } },
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : []
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_create_acct_org_and_users_debug_'] = entity_import('rules_config', '{ "commerce_checkout_create_acct_org_and_users_debug_" : {
      "LABEL" : "Create Users and Organization",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "DLCommerce" ],
      "REQUIRES" : [
        "rules",
        "dl_billing_management",
        "php",
        "mimemail",
        "og",
        "commerce_payment",
        "commerce_checkout"
      ],
      "ON" : {
        "commerce_payment_order_paid_in_full" : [],
        "commerce_checkout_complete" : []
      },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } },
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "commerce_customer_billing" } }
      ],
      "DO" : [
        { "dl_billing_management_get_ubid_for_rule_action" : {
            "USING" : { "email" : [ "commerce-order:mail" ] },
            "PROVIDE" : { "ubid" : { "ubid" : "Unique Billing ID" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "commerce-order:mail" ] },
            "PROVIDE" : { "variable_added" : { "submitted_mail" : "Submitted Mail" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "commerce-order:mail-username" ] },
            "PROVIDE" : { "variable_added" : { "submitted_name" : "Submitted Name" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : {
                "select" : "ubid",
                "php" : { "code" : "return \\u0022dlBillingUser+\\u0022.$value;" }
              },
              "param_mail" : {
                "select" : "ubid",
                "php" : { "code" : "return \\u0022dlBillingUser+\\u0022.$value.\\u0022@outlier.com\\u0022;" }
              }
            },
            "PROVIDE" : { "entity_created" : { "billing_account" : "Billing Account" } }
          }
        },
        { "entity_save" : { "data" : [ "billing-account" ], "immediate" : "1" } },
        { "data_set" : { "data" : [ "billing-account:status" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "billing-account" ], "immediate" : "1" } },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "uid",
              "value" : [ "billing-account:uid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "billing_list_item" : "Billing list item" },
            "DO" : [
              { "data_set" : {
                  "data" : [ "commerce-order:uid" ],
                  "value" : [ "billing-list-item:uid" ]
                }
              },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                  "value" : [ "billing-list-item:uid" ]
                }
              },
              { "data_set" : {
                  "data" : [ "commerce-order:mail" ],
                  "value" : [ "billing-account:mail" ]
                }
              }
            ]
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : [ "submitted-name" ],
              "param_mail" : [ "submitted-mail" ]
            },
            "PROVIDE" : { "entity_created" : { "general_account" : "General Account" } }
          }
        },
        { "entity_save" : { "data" : [ "general-account" ], "immediate" : "1" } },
        { "data_set" : { "data" : [ "general-account:status" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "general-account" ], "immediate" : "1" } },
        { "entity_fetch" : {
            "USING" : {
              "type" : "commerce_customer_profile",
              "id" : [ "commerce-order:commerce-customer-billing:profile-id" ]
            },
            "PROVIDE" : { "entity_fetched" : { "customer_billing_profile" : "Customer Billing Profile" } }
          }
        },
        { "data_set" : {
            "data" : [ "general-account:field-first-name" ],
            "value" : "[customer-billing-profile:commerce-customer-address:first_name]"
          }
        },
        { "entity_save" : { "data" : [ "general-account" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "general-account:field-last-name" ],
            "value" : "[customer-billing-profile:commerce-customer-address:last_name]"
          }
        },
        { "entity_save" : { "data" : [ "general-account" ], "immediate" : "1" } },
        { "mimemail" : {
            "key" : "Free Trial is Activated",
            "to" : [ "general-account:mail" ],
            "subject" : "[site:name] Free Trial is Activated",
            "body" : "\\u003Ch2\\u003EHi [customer-billing-profile:commerce-customer-address:first_name] [customer-billing-profile:commerce-customer-address:last_name],\\u003C\\/h2\\u003E\\r\\n\\u003Cp\\u003EWe\\u2019re excited for you to join us for a free trial to [site:name]!\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EBe sure to add your team members to your free trial, so everyone has full access to our procedural shorts, RACE-approved CE and medical articles!\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ENote that your seven-day free trial will automatically renew on \\u003C?php echo date(\\u0022jS F, Y\\u0022, strtotime(\\u0022+7 days\\u0022)); ?\\u003E, at which time your credit card will be charged. \\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EIf you have any questions, visit our \\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\/help-center\\u0022\\u003EHelp Center\\u003C\\/a\\u003E or \\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\/contact-us\\u0022\\u003EContact Us\\u003C\\/a\\u003E directly. \\u003C\\/p\\u003E",
            "language" : [ "" ]
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "organization",
              "param_title" : "[customer-billing-profile:commerce-customer-address:organisation_name]",
              "param_author" : [ "commerce-order:owner" ]
            },
            "PROVIDE" : { "entity_created" : { "new_organization" : "New Organization" } }
          }
        },
        { "entity_save" : { "data" : [ "new-organization" ], "immediate" : "1" } },
        { "user_add_role" : {
            "account" : [ "billing-account" ],
            "roles" : { "value" : { "10" : "10" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "general-account" ],
            "roles" : { "value" : { "5" : "5", "6" : "6" } }
          }
        },
        { "list_add" : {
            "list" : [ "general-account:og-user-node" ],
            "item" : [ "new-organization" ],
            "unique" : "1"
          }
        },
        { "entity_save" : { "data" : [ "general-account" ], "immediate" : "1" } },
        { "og_grant_og_role" : {
            "account" : [ "general-account" ],
            "group" : [ "new-organization" ],
            "roles" : { "value" : { "administrator member" : "administrator member" } }
          }
        },
        { "dl_billing_management_authenicate_user" : {
            "USING" : { "user" : [ "general-account" ] },
            "PROVIDE" : { "auth_user" : { "auth_user" : "Authenicated User" } }
          }
        },
        { "dl_billing_management_make_org_admin" : {
            "user" : [ "general-account:uid" ],
            "group" : [ "new-organization:nid" ]
          }
        }
      ]
    }
  }');
  $items['rules_adjust_1st_renewal_w_c'] = entity_import('rules_config', '{ "rules_adjust_1st_renewal_w_c" : {
      "LABEL" : "Adjust 1st Renewal With Any Coupons From The Free Trial",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [
        "dl_billing_management",
        "commerce_cart",
        "commerce_line_item",
        "commerce_product_reference"
      ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "dl_billing_management_does_order_get_coupon_from_free_trail" : { "entity" : [ "commerce-line-item:order" ] } },
        { "NOT commerce_order_is_cart" : { "commerce_order" : [ "commerce-line-item:order" ] } }
      ],
      "DO" : [
        { "dl_billing_management_get_discount_from_free_trial" : {
            "USING" : {
              "order" : [ "commerce-line-item:order" ],
              "lineItem" : [ "commerce-line-item" ]
            },
            "PROVIDE" : { "discount_amount" : { "discount_amount" : "Discount Amount" } }
          }
        },
        { "commerce_line_item_unit_price_subtract" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "amount" : [ "discount-amount" ],
            "component_name" : "discount",
            "round_mode" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_clear_the_cart_of_authenticated_non_billing_users_'] = entity_import('rules_config', '{ "rules_clear_the_cart_of_authenticated_non_billing_users_" : {
      "LABEL" : "Clear the Cart of Authenticated Non-Billing Users ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "16" : "16" } } } }
      ],
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "site:current-cart-order" ] } }
      ]
    }
  }');
  $items['rules_new_user_checkout_only'] = entity_import('rules_config', '{ "rules_new_user_checkout_only" : {
      "LABEL" : "New User Checkout Only",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : {
                "2" : "2",
                "3" : "3",
                "4" : "4",
                "5" : "5",
                "6" : "6",
                "7" : "7",
                "9" : "9",
                "8" : "8",
                "10" : "10",
                "11" : "11",
                "16" : "16"
              }
            },
            "operation" : "OR"
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
  $items['rules_on_successful_order_create_an_organization'] = entity_import('rules_config', '{ "rules_on_successful_order_create_an_organization" : {
      "LABEL" : "On Successful Order Create an Organization",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "DLCommerce" ],
      "REQUIRES" : [ "rules", "commerce_payment" ],
      "ON" : { "commerce_payment_order_paid_in_full" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "commerce_customer_billing" } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "commerce_customer_profile",
              "id" : [ "commerce-order:commerce-customer-billing:profile-id" ]
            },
            "PROVIDE" : { "entity_fetched" : { "customer_billing_profile" : "Customer Billing Profile" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "organization",
              "param_title" : "[customer-billing-profile:field-company]",
              "param_author" : [ "commerce-order:owner" ]
            },
            "PROVIDE" : { "entity_created" : { "organization_created" : "Created Organization" } }
          }
        }
      ]
    }
  }');
  $items['rules_redirect_to_checkout_on_add_to_cart'] = entity_import('rules_config', '{ "rules_redirect_to_checkout_on_add_to_cart" : {
      "LABEL" : "Redirect to checkout on add to cart",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart", "Commerce Checkout", "DLCommerce" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [ { "redirect" : { "url" : "checkout" } } ]
    }
  }');
  $items['rules_restrict_cart_to_1_item'] = entity_import('rules_config', '{ "rules_restrict_cart_to_1_item" : {
      "LABEL" : "Restrict cart to 1 item",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart" ],
      "ON" : { "commerce_cart_product_prepare" : [] },
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  return $items;
}
