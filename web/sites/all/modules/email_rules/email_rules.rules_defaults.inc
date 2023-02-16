<?php
/**
 * @file
 * email_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function email_rules_default_rules_configuration() {
  $items = array();
  $items['email_rules_email_rules_send_email_if_no_group_members'] = entity_import('rules_config', '{ "email_rules_email_rules_send_email_if_no_group_members" : {
      "LABEL" : "Send email to new account with no group members",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "rules_scheduler" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "php_eval" : { "code" : "$test = organization_control_subscription_info($account)  \\u0026\\u0026 organization_control_orgID($account) \\u0026\\u0026 (organization_control_organization_size($account) \\u003C 3);\\r\\nreturn $test;" } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "email_rules_send_email_to_account_with_no_group_members",
            "date" : "+8 days",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['email_rules_send_email_to_account_with_no_group_members'] = entity_import('rules_config', '{ "email_rules_send_email_to_account_with_no_group_members" : {
      "LABEL" : "Send email to account with no group members",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "atDove - Getting Started",
            "message" : "\\u003Ch2\\u003EHello [user:field-first-name]\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cp\\u003ENow that you\\u2019ve scrubbed into www.atdove.org and downloaded your Administrator \\r\\nUser Guide, it\\u2019s time to add members to your account! You need to add your members\\r\\nso that they can create their own profiles, start watching videos, take quizzes, \\r\\nand experience all the benefits of On the Floor @Dove.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EAdding members to your account is easy. Click here for step-by-step instructions.\\r\\nOnce you have members on your account you can start assigning videos like this one:\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003Ehttps:\\/\\/www.atdove.org\\/videos\\/Procedure\\/Anesthesia-Leak-Test\\u003C\\/p\\u003E",
            "from" : "atDoveMessage@atdove.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_new_user_day_2'] = entity_import('rules_config', '{ "rules_send_email_to_new_user_day_2" : {
      "LABEL" : "Send email to New User Day 2",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "rules_scheduler" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "php_eval" : { "code" : "$test = organization_control_subscription_info($account)  \\u0026\\u0026 organization_control_orgID($account) \\u0026\\u0026 (organization_control_organization_size($account) \\u003C 3);\\r\\nreturn $test;" } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_send_email_to_user_day_2",
            "date" : "+2 days",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_new_user_day_3'] = entity_import('rules_config', '{ "rules_send_email_to_new_user_day_3" : {
      "LABEL" : "Send email to New User Day 3",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "rules_scheduler" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "php_eval" : { "code" : "\\/\\/ returns true if none of the administrators have created assignments\\r\\n$organization = organization_control_orgID($account);\\r\\n$test = organization_control_subscription_info($account)  \\u0026\\u0026  $organization \\u0026\\u0026 !dl_assignments_content_has_organization($organization, \\u0027assignment\\u0027);\\r\\nreturn $test;" } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_send_email_to_user_day_3",
            "date" : "+3 days",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_new_user_day_4'] = entity_import('rules_config', '{ "rules_send_email_to_new_user_day_4" : {
      "LABEL" : "Send email to New User Day 4",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "schedule" : {
            "component" : "rules_send_email_to_user_day_4",
            "date" : "+4 days",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_new_user_day_6'] = entity_import('rules_config', '{ "rules_send_email_to_new_user_day_6" : {
      "LABEL" : "Send email to New User Day 6",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "rules_scheduler" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "php_eval" : { "code" : "\\/\\/ returns true if none of the administrators have created training plans\\r\\n$organization = organization_control_orgID($account);\\r\\n$test = organization_control_subscription_info($account)  \\u0026\\u0026  $organization \\u0026\\u0026 !dl_assignments_content_has_organization($organization, \\u0027training_plan\\u0027);\\r\\nreturn $test;" } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_send_email_to_user_day_6",
            "date" : "+6 days",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_user_day_2'] = entity_import('rules_config', '{ "rules_send_email_to_user_day_2" : {
      "LABEL" : "Send email to User Day 2",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Start Winning by Adding Your Members!",
            "message" : "\\u003Ch2\\u003EHi [user:field-first-name]\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cp\\u003ETraining can\\u0027t begin until you add your team members. It\\u0027s quick to do-here\\u0027s how! \\u003C\\/p\\u003E\\r\\n\\u003Col\\u003E\\r\\n\\u003Cli\\u003EFrom your menu, select \\u201cInvite Teammates\\u201d\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EEnter in your team\\u0027s email addresses\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EMake sure to let everyone know to watch for an invitation from atdove.org  \\u003C\\/li\\u003E\\r\\n\\u003C\\/ol\\u003E\\r\\n\\u003Cp\\u003EThat\\u0027s it! Start winning at staff training next by assigning a video for your team to watch, like \\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\/videos\\/Procedure\\/Bottle-Feeding-Kittens\\u0022\\u003Ethis\\u003C\\/a\\u003E interesting (and in this case adorable) procedural short.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EIf you have any questions, visit our \\u003Ca href=\\u0027https:\\/\\/www.atdove.org\\/help\\u0027\\u003EHelp Center\\u003C\\/a\\u003E or \\u003Ca href=\\u0027https:\\/\\/www.atdove.org\\/contact-us directly\\u0027\\u003EContact Us\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n",
            "from" : "atDoveMessage@atdove.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_user_day_3'] = entity_import('rules_config', '{ "rules_send_email_to_user_day_3" : {
      "LABEL" : "Send email to User Day 3",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Yes, you do need to put it right in front of them!",
            "message" : "\\u003Ch2\\u003EHello [user:field-first-name]\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou\\u0027ve probably already realize what a chore it is to develop a staff training program. \\r\\nWe\\u2019ve done it and we make it way easier for you! Once your teammates accept their AtDove.org invitation, \\r\\nyou\\u2019ll be able to share content with them and assign your Custom Training Plans or a Pre-Built Training Plan.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EAssigning procedural shorts is the best way to get in front of your team and get them engaged in learning what you need them to know.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\/help\\/My-Account\\/How-Do-I-Assign-Items-to-Member-s\\u0022\\u003ELearn how to send an assignment\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can also track your team\\u2019s progress by downloading your Member Activity Report. \\r\\nThis tool lets you see when a staff member completes their assignments, as well as \\r\\nany other content they\\u2019re viewing, and more.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\/help\\/My-Account\\/Are-there-administrator-tools-to-assign-and-monitor-member-activity\\u0022\\u003ELearn how to monitor member activity\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
            "from" : "atDoveMessage@atdove.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_user_day_4'] = entity_import('rules_config', '{ "rules_send_email_to_user_day_4" : {
      "LABEL" : "Send email to User Day 4",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Are You Winning at Training Yet? Let us Know.",
            "message" : "\\u003Ch2\\u003EHello [user:field-first-name]\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cp\\u003ELet us be your veterinary practice support system! Any of your members can comment \\r\\nor question on any of our content and you\\u2019ll get a quick response. If you haven\\u2019t found what \\r\\nyou\\u2019re looking for, you can suggest content for us to develop, too. We use your suggestions \\r\\nto plan our filming schedule.\\u003Cp\\u003E\\r\\n\\r\\n\\u003Cp\\u003EWhat are you working on today? Find solutions and support for a wide range of practice \\r\\nmanagement tasks, like \\r\\n\\u003Ca href=\\u0022 https:\\/\\/www.atdove.org\\/blog\\/From-the-Front-Desk\\/5-Tips-for-Hiring-Receptionists-1-5\\u0022\\u003Ehiring for veterinary reception\\u003C\\/a\\u003E.\\u003Cp\\u003E\\r\\n \\r\\n\\u003Cp\\u003EIf you haven\\u2019t already, check out some of our Job Specific training for new hires or staff advancement.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ERemember to check back to \\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\u0022\\u003Eatdove.org\\u003C\\/a\\u003E weekly to see our freshest content.\\u003C\\/p\\u003E",
            "from" : "atDoveMessage@atdove.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_email_to_user_day_6'] = entity_import('rules_config', '{ "rules_send_email_to_user_day_6" : {
      "LABEL" : "Send email to User Day 6",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Focusing on What Matters",
            "message" : "\\u003Ch2\\u003EHello [user:field-first-name]\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cp\\u003E Create Those Training Plans! \\u003C\\/p\\u003E \\r\\n\\r\\n\\u003Cp\\u003EWaiting until you can dedicate a full day to start creating your custom training plans? \\r\\nLet\\u0027s be honest, with that busy schedule of yours, that may never happen!\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ECreating a custom training plan will take just take moments of your time and can save you \\r\\nfrom future management headaches. You can create as many plans as you want and they can \\r\\nbe edited or deleted at any time.\\u003C\\/p\\u003E\\r\\n\\r\\n\\r\\n\\u003Cp\\u003ENeed help using your On the Floor @Dove account? Visit our Help Center: https:\\/\\/www.atdove.org\\/help\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EContact Us: https:\\/\\/www.atdove.org\\/contact-us\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022https:\\/\\/www.atdove.org\\/help\\/My-Account\\/How-to-create-a-custom-training-plan\\u0022\\u003EHere\\u003C\\/a\\u003E \\r\\nare the quick step-by-step instructions on how to make your first custom training plan today.\\u003C\\/p\\u003E",
            "from" : "atDoveMessage@atdove.org",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
