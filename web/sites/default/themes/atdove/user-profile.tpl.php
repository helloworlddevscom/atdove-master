<?php
$current_path = current_path();
preg_match_all('!\d+!', $current_path, $userid);
drupal_goto('user-profile/' . $userid[0][0]);
