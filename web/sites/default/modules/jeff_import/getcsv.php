<?php

$servername = "127.0.0.1";
$username = "root";
$password = "";
$database = "atdove2";

$timestamp = "2015-06-09";

// Create connection
$conn = new mysqli($servername, $username, $password, $database);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$set_utf8 = "SET NAMES utf8";
$result = $conn->query($set_utf8);


// Choose the base table you want to work from
$base_table_name = "custom";
//$base_table_name = "blog";
//$base_table_name = "resource";
//$base_table_name = "ads";
//$base_table_name = "announcement";
//$base_table_name = "faq";
//$base_table_name = 'helpContent';
$base_table_name = 'people';
//$base_table_name = 'testQuestion';
//$base_table_name = 'test';
//$base_table_name = 'people';
//$base_table_name = 'organization';
//$base_table_name = 'comment';
//$base_table_name = 'testResult';
//$base_table_name = 'assignments';
//$base_table_name = 'contentGroups';

if ($base_table_name == 'comment') {
  //$where_clause = '%blog%';
  //$where_clause = '%resource%';
  $where_clause = '%customVideo%';
  //$where_clause = '%peopleMembers%';
  //$where_clause = '%Website%';
}





$table_name = "swt_".$base_table_name;
$relations_table_names = array();
switch ($base_table_name) {
  case "custom":
    $relations_table_names['swt_dynamicReference_ads_custom'] = array('custom_id','ads_id','related_ads');
    $relations_table_names['swt_dynamicReference_blog_custom'] = array('custom_id','blog_id','related_blogs');
    $relations_table_names['swt_dynamicReference_custom_custom'] = array('custom_1_id','custom_2_id','related_videos');
    $relations_table_names['swt_dynamicReference_custom_people'] = array('custom_id','people_id','contributors');
    $relations_table_names['swt_dynamicReference_custom_resource'] = array('custom_id','resource_id','related_articles');
    $relations_table_names['swt_dynamicReference_custom_survey'] = array('custom_id','survey_id','related_surveys');
    $relations_table_names['swt_dynamicReference_custom_tag'] = array('custom_id','tag_id','related_tags');
    $relations_table_names['swt_dynamicReference_custom_test'] = array('custom_id','test_id','related_quizzes');
    $relations_table_names['swt_dynamicReference_custom_fileManager'] = array('custom_id','fileManager_id','additional_downloads');
    break;
  case "blog":
    $relations_table_names['swt_dynamicReference_ads_blog'] = array('blog_id','ads_id','related_ads');
    $relations_table_names['swt_dynamicReference_blog_blog'] = array('blog_1_id','blog_2_id','related_blogs');
    $relations_table_names['swt_dynamicReference_blog_custom'] = array('blog_id','custom_id','related_videos');
    $relations_table_names['swt_dynamicReference_blog_people'] = array('blog_id','people_id','contributors');
    $relations_table_names['swt_dynamicReference_blog_resource'] = array('blog_id','resource_id','related_articles');
    $relations_table_names['swt_dynamicReference_blog_survey'] = array('blog_id','survey_id','related_surveys');
    $relations_table_names['swt_dynamicReference_blog_tag'] = array('blog_id','tag_id','related_tags');
    break;
  case "resource":
    $relations_table_names['swt_dynamicReference_ads_resource'] = array('resource_id','ads_id','related_ads');
    $relations_table_names['swt_dynamicReference_blog_resource'] = array('resource_id','blog_2_id','related_blogs');
    $relations_table_names['swt_dynamicReference_custom_resource'] = array('resource_id','custom_id','related_videos');
    $relations_table_names['swt_dynamicReference_people_resource'] = array('resource_id','people_id','contributors');
    $relations_table_names['swt_dynamicReference_resource_resource'] = array('resource_1_id','resource_2_id','related_articles');
    $relations_table_names['swt_dynamicReference_blog_survey'] = array('resource_id','survey_id','related_surveys');
    $relations_table_names['swt_dynamicReference_resource_tag'] = array('resource_id','tag_id','related_tags');
    $relations_table_names['swt_dynamicReference_resource_test'] = array('resource_id','test_id','related_quizzes');
    break;
  case "ads":
    $relations_table_names['swt_dynamicReference_ads_blog'] = array('ad_id','blog_id','related_blogs');
    $relations_table_names['swt_dynamicReference_ads_custom'] = array('ad_id','custom_id','related_videos');
    $relations_table_names['swt_dynamicReference_ads_resource'] = array('ad_id','resource_id','related_articles');
    break;
  case "announcement":
    break;
  case "faq":
    $relations_table_names['swt_dynamicReference_faq_helpContent'] = array('faq_id','helpContent_id','related_help');
    break;
  case "helpContent":
    $relations_table_names['swt_dynamicReference_faq_helpContent'] = array('helpContent_id','faq_id','related_faqs');
    $relations_table_names['swt_dynamicReference_helpContent_helpContent'] = array('helpContent_1_id','helpContent_2_id','related_help');
    $relations_table_names['swt_dynamicReference_helpContent_tag'] = array('helpContent_id','tag_id','related_tags');
    break;
  case "test":
    $relations_table_names['swt_dynamicReference_custom_test'] = array('test_id','custom_id','related_videos');
    $relations_table_names['swt_dynamicReference_resource_test'] = array('test_id','resource_id','related_articles');
    $relations_table_names['swt_test_rel'] = array('link_id','link_group','test_group');
    $relations_table_names['swt_testQuestion_data'] = array('test_id','id','test_questions');
    break;
  case "contentGroups":
    $relations_table_names['swt_dynamicReference_contentGroups_custom'] = array('contentGroups_id','custom_id','related_videos');
    $relations_table_names['swt_dynamicReference_contentGroups_resource'] = array('contentGroups_id','resource_id','related_articles');
    break;
}

echo ('RELATED TABLES'); var_dump($relations_table_names);

$field_query = "SELECT DISTINCT(fieldName) FROM ".$table_name."_fields";

$result = $conn->query($field_query);
$fields = array();

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    //echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br>";
    //var_dump($row);
    $fields[] = $row['fieldName'];
  }
} else {
  echo "0 fields found";
}
echo 'FIELDS ARE';var_dump($fields);


$query = "SELECT * FROM ".$table_name."_data";
//var_dump($query);
if ($base_table_name == 'comment') {
  $query = $query.' WHERE resource_id LIKE "'. $where_clause.'"';
}
if (!empty($timestamp)) {
  if (strpos($query,'WHERE ')) {
    $query .= ' AND ';
  }
  else {
    $query .= ' WHERE ';
  }
  $query .='modified > "'.$timestamp.'"';
}
var_dump ($query);
$result = $conn->query($query);
var_dump('number of rows is '.$result->num_rows);
$ids = array();
$count = 0;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    //echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br>";
    //var_dump($row);
    if ($count==0) {
      $base_fields = array_keys($row);
      $base_fields[] = 'groupName';
      var_dump($base_fields);
      if (in_array('answers',$base_fields)) {
        $position = array_search('answers',$base_fields)+2;
        array_splice($base_fields,$position,0,'correct answer');
        array_splice($base_fields,$position+1,0,'wrong answer 1');
        array_splice($base_fields,$position+2,0,'wrong answer 2');
        array_splice($base_fields,$position+3,0,'wrong answer 3');
        array_splice($base_fields,$position+4,0,'wrong answer 4');
        array_splice($base_fields,$position+5,0,'wrong answer 5');
      }
    }
    $all_fields = array_merge($base_fields,$fields);
    $count++;


    foreach ($row as $key => $item) {
      if ((strlen($item)==32 && ctype_xdigit($item)) || $key == 'recordID') {
        if ($key == 'recordID' && $base_table_name == 'organization') {      // Find a viable Administrator-roled author for the org.
          $nodemanagerquery = 'select id from swt_people_fields where fieldName = "organization_id" and fieldValue = "' . str_replace('-', '', $row['id']) . '"';
          $nodemanager = NULL;
          //var_dump($nodemanagerquery);
          $nodemanagerresult = $conn->query($nodemanagerquery);
          while ($nodemanagerrow = $nodemanagerresult->fetch_assoc()) {
            //var_dump($nodemanagerrow['id']);
            $nodemanagersubquery = 'select id from swt_people_fields where fieldName = "organization_status" and fieldValue = "Administrator" and id = "' . $nodemanagerrow['id'] . '"';
            //var_dump($nodemanagersubquery);
            $nodemanagersubresult = $conn->query($nodemanagersubquery);
            while ($nodemanagersubrow = $nodemanagersubresult->fetch_assoc()) {
              if (strlen($nodemanagersubrow['id']) == 32) {
                $nodemanager = ($nodemanagersubrow['id']);
              }
            }
          }

          $row[$key] = makeUsername($nodemanager);
          if (strlen($row[$key]) < 3) {
            //var_dump('Error with uid ' . $nodemanager);
          }
        }
        elseif ($key == 'createdBy' || $key == 'modifiedBy' || $key == 'member_id') {
          //var_dump($key);
          $row[$key] = makeUsername($item);
        }
        else {
          $row[$key] = makeUUID($item);
        }
      }
      elseif ($key=='resource_id' && $base_table_name == 'comment') {
        $item = preg_replace('/[^:]+:[^:]+:/','',$item);
        $row[$key] = makeUUID($item);
        //var_dump($item);
      }
      elseif ($key == 'answers' && $base_table_name=='testQuestion') {
        $item = str_replace('[','',$item);
        $item = str_replace(']','',$item);
        $item = str_replace('""','" "',$item);
        //var_dump($item);
        $itemArray = explode('},{',$item);
        foreach ($itemArray as $counter=>$itemVal) {
          $itemArray[$counter] = str_replace('{','',$itemArray[$counter]);
          $itemArray[$counter] = str_replace('}','',$itemArray[$counter]);
          $itemArray[$counter] = explode('","',$itemArray[$counter]);
          foreach ($itemArray[$counter] as $subcounter=>$subItemVal) {
            if ($subItemVal == "isCorrectAnswer\":false") {
              $itemArray[$counter][$subcounter] = false;
            }
            elseif ($subItemVal == "isCorrectAnswer\":true") {
              $itemArray[$counter][$subcounter] = true;
            }
            else {
              $itemArray[$counter][$subcounter] = str_replace('"answer":"','',$itemArray[$counter][$subcounter]);
            }
          }
          if ($itemArray[$counter][1] == true) {
            $itemArray[$counter] = 'aaa'.$itemArray[$counter][0];
          }
          else {
            $itemArray[$counter] = 'zzz'.$itemArray[$counter][0];
          }
        }
        sort($itemArray);
        foreach ($itemArray as $counter=>$itemVal) {
          $itemArray[$counter]=str_replace('aaa','',$itemArray[$counter]);
          $itemArray[$counter]=str_replace('zzz','',$itemArray[$counter]);
          //var_dump($itemArray['counter']);
        }
        //var_dump($itemArray);
        if (isset($itemArray[0])) {$row['correct answer'] = $itemArray[0];} else {$row['correct answer'] = null;}
        if (isset($itemArray[1])) {$row['wrong answer 1'] = $itemArray[1];} else {$row['wrong answer 1'] = null;}
        if (isset($itemArray[2])) {$row['wrong answer 2'] = $itemArray[2];} else {$row['wrong answer 2'] = null;}
        if (isset($itemArray[3])) {$row['wrong answer 3'] = $itemArray[3];} else {$row['wrong answer 3'] = null;}
        if (isset($itemArray[4])) {$row['wrong answer 4'] = $itemArray[4];} else {$row['wrong answer 4'] = null;}
        if (isset($itemArray[5])) {$row['wrong answer 5'] = $itemArray[5];} else {$row['wrong answer 5'] = null;}
      }
      else {
        //var_dump($key);
        //var_dump('Before: '.$item);
        $item = encodeToUtf8($item);
        //var_dump('After: '.$item);
        $row[$key] = $item;
      }
      //$tempUUID = preg_replace('/([0-9a-f]{8})([0-9a-f]{4})([0-9a-f]{4})([0-9a-f]{4})([0-9a-f]{12})/','$1-$2-$3-$4-$5',$tempUUID);
    }
    if (isset($row['answers'])) {
      $row['answers'] =  str_replace('""','" "',$row['answers']);
    }
    /*
    if (isset($row['active']) && isset($row['deleted'])) {
      if ($row['deleted'] == 1) {
        $row['active'] = 0;
      }
    }
    */

    $ids[] = $row;
  }
} else {
  echo "0 results";
}

//echo 'HERE ARE THE IDs';var_dump($ids);

//Now add in the group name...
foreach ($ids as $count => $id) {
  $groupquery = str_replace('blog',$base_table_name,'SELECT swt_blog_data.title, swt_blog_group.title AS `group` FROM swt_blog_data
JOIN swt_blog_rel ON
(swt_blog_data.id = swt_blog_rel.link_record)
JOIN swt_blog_group ON
(swt_blog_rel.link_group = swt_blog_group.id)
').' WHERE swt_'.$base_table_name.'_data.id="'.str_replace('-','',$id['id']).'"';
  $groupresult= $conn->query($groupquery);
  //var_dump($groupquery);
  if ($groupresult) {
    while ($grouprow = $groupresult->fetch_assoc()) {
      //var_dump('Group name is');
      //var_dump($grouprow);
      $ids[$count]['group'] = $grouprow['group'];
    }
  }
  if (!isset($ids[$count]['group'])) {$ids[$count]['group'] = '';}
}



foreach ($ids as $count => $id) {
  foreach ($fields as $field) {
    $rowquery = 'SELECT * FROM ' . $table_name . '_fields WHERE id="' . str_replace('-','',$id['id']) . '" AND fieldName="' . $field . '"';
    //print $rowquery;
    $rowresult = $conn->query($rowquery);
    if ($rowresult) {
      while ($row = $rowresult->fetch_assoc()) {
        //var_dump($ids[$count]);
        //echo '('.$row['fieldName'].','.$row['fieldValue'].')\p';
        if (isset($row['fieldValue'])) {
          $fieldValue = $row['fieldValue'];
          if (strlen($fieldValue) == 32 && ctype_xdigit($fieldValue)) {
            $fieldValue = makeUUID($fieldValue);
          }
          if ($field == 'video_type') { // Replace text values with booleans for Video Type fields
            if ($fieldValue == 'Premium') {
              $fieldValue = 1;
            }
            else {
              $fieldValue = 0;
            }
          } elseif ($field == 'length') { // Convert Video Length fields to seconds
            $timequery = 'SELECT * FROM ' . $table_name . '_fields WHERE id="' . str_replace('-','',$id['id']) . '" AND fieldName="length_unit"';
            $timeresult = $conn->query($timequery);
            while ($timerow = $timeresult->fetch_assoc()) {
              $unit = $timerow['fieldValue'];
            }
            if ($unit == 'Hours') {
              $unitarray = explode(":",$fieldValue);
              $fieldValue = $unitarray[0]*3600+$unitarray[1]*60;
              //var_dump($fieldValue);
            }
            elseif ($unit == 'Minutes') {
              $unitarray = explode(":",$fieldValue);
              $fieldValue = $unitarray[0]*60+$unitarray[1];
              //var_dump($fieldValue);
            }
          }
          else {
            $fieldValue = encodeToUtf8($fieldValue);
          }
        }
        else {
          $fieldValue = NULL;
        }
        $ids[$count][$field] = $fieldValue;
      }
    }
      if (!isset($ids[$count][$field])){
        $ids[$count][$field] = NULL;
    }
  }
  foreach ($relations_table_names as $relations_table_name=>$relations_table_name_details) {
    $rowquery = 'SELECT '.$relations_table_name_details[1].' FROM ' . $relations_table_name .' WHERE '. $relations_table_name_details[0] . '="'. str_replace('-','',$id['id']) . '"';
    //var_dump ($rowquery);
    $rowresult = $conn->query($rowquery);
    if ($rowresult) {
      $fieldValue = '';
      while ($row = $rowresult->fetch_assoc()) {
        //var_dump($relations_table_name_details);
        if (isset($relations_table_name_details[2]['people_id']) || $relations_table_name_details[2] == 'contributors'|| $relations_table_name_details[2] == 'contributor') { //It's a user ref, grab username
          //var_dump($rowquery);

          //var_dump ($row);
          $tempUUID = $row['people_id'];
          //var_dump($tempUUID);
          $maybeanid = makeUsername($tempUUID);
          //var_dump($maybeanid);

        } elseif($relations_table_name_details[2] == 'additional_downloads') {
          //var_dump('ITS A DOWNLOADS THING');
          $dlquery = "SELECT file_name from swt_fileManager_data WHERE id='".$row['fileManager_id']."'";
          //var_dump($dlquery);
          $dlresult = $conn->query($dlquery);
          while ($dlrow = $dlresult->fetch_assoc()) {
            $maybeanid = "https://www.atdove.org".$dlrow['file_name'];
            //var_dump($maybeanid);
          }
        } elseif (strlen($row[$relations_table_name_details[1]]) == 32 && ctype_xdigit($row[$relations_table_name_details[1]])) {
          $tempUUID = $row[$relations_table_name_details[1]];
          $maybeanid = makeUUID($tempUUID);
        }
        else {
          $maybeanid = $row[$relations_table_name_details[1]];
        }
        if (strlen($fieldValue)>1) {
          $fieldValue .= '|';
          $fieldValue .= $maybeanid;
          //var_dump ('we have multiples of type '.$relations_table_name_details[2]);
        }
        else {
          $fieldValue = $maybeanid;
        }
      }
      //var_dump($ids[$count]);
    } else {
      $fieldValue = '';
    }
    $ids[$count][$relations_table_name_details[2]] = $fieldValue;
    //var_dump($ids[$count][$relations_table_name_details[2]]);
  }
}



foreach ($relations_table_names as $relations_table_name) {
  $all_fields[] = $relations_table_name[2];
}

if ($base_table_name == 'people') { // Create an entry which munges org name + subgroup name for mapping to subgroups
  $all_fields[] = 'temp_org_grp_name';
  foreach ($ids as $subgroupkey=>$id) {
    $subgroupquery = 'select title from swt_organization_data where id="'.str_replace('-','',$id['organization_id']).'"';
    $subgroupresult = $conn->query($subgroupquery);
    while ($subgrouprow = $subgroupresult->fetch_assoc()) {
      $orgname = $subgrouprow['title'];
    }
    if (strlen($ids[$subgroupkey]['organization_group'])>2) {
      $ids[$subgroupkey]['temp_org_grp_name'] = $orgname . ':' . $ids[$subgroupkey]['organization_group'];
    }
    else {
      $ids[$subgroupkey]['temp_org_grp_name'] = '';
    }
  }
} elseif ($base_table_name == 'custom' || $base_table_name == 'resource') { // Get the accreditations from related quiz
  $all_fields[] = 'quiz_race_id';
  $all_fields[] = 'quiz_accreditation';
  foreach ($ids as $subgroupkey => $id) {
    $quizzes = ($id['related_quizzes']);
    if (strpos($quizzes, '|')) { //there is one stinker that has two related quizzes, so hard coding around it
      //var_dump('This ID has multiple quizzes:');
      //var_dump($id['id']);
      //var_dump($id['related_quizzes']);
      $id['related_quizzes'] = str_replace('66f623ae-90b6-b0cc-016f-124607f2da92|', '', $id['related_quizzes']);
    }
    $quizzes = str_replace('-', '', $quizzes);
    if (isset($quizzes) && strlen($quizzes) > 4) {
      $relatedquizquery = 'SELECT fieldValue FROM swt_test_data JOIN swt_test_fields ON (swt_test_data.id = swt_test_fields.id) WHERE swt_test_data.id ="' . $quizzes . '" AND fieldName="race_id"'; // Get the race_id from related quiz
      //var_dump($relatedquizquery);
      $relatedquizresult = $conn->query($relatedquizquery);
      if ($relatedquizresult->num_rows > 0) {
        //var_dump('results!');
        while ($relatedquizrow = $relatedquizresult->fetch_assoc()) {
          //var_dump('Related quiz:');
          //var_dump($relatedquizrow);
          if (isset($relatedquizrow['fieldValue']) && strlen($relatedquizrow['fieldValue']) > 1) {
            $ids[$subgroupkey]['quiz_race_id'] = $relatedquizrow['fieldValue'];
          }
          else {
            $ids[$subgroupkey]['quiz_race_id'] = '';
          }
        }
        }
      else {
        $ids[$subgroupkey]['quiz_race_id'] = '';
      }
        $relatedquizquery2 = 'SELECT fieldValue FROM swt_test_data JOIN swt_test_fields ON (swt_test_data.id = swt_test_fields.id) WHERE swt_test_data.id ="' . $quizzes . '" AND fieldName="accreditation"'; // Now get the accreditation from related quiz
        $relatedquizresult2 = $conn->query($relatedquizquery2);
        if ($relatedquizresult2->num_rows > 0) {
          while ($relatedquizrow2 = $relatedquizresult2->fetch_assoc()) {
            if (isset($relatedquizrow2['fieldValue']) && is_numeric($relatedquizrow2['fieldValue'])) {
              $ids[$subgroupkey]['quiz_accreditation'] = $relatedquizrow2['fieldValue'];
            }
            else {
              $ids[$subgroupkey]['quiz_accreditation'] = '';
            }
          }
        }
      else {
        $ids[$subgroupkey]['quiz_accreditation'] = '';
      }
    }
  }
}



var_dump($ids[12]);


//echo 'HERE ARE THE IDs';var_dump($ids);

if ($base_table_name == 'comment') {
  $filename = 'swt_comment'.'_'.str_replace('%','',$where_clause).'.csv';
  var_dump($filename);
  $fp = fopen($filename, 'w');
}
else {
  $fp = fopen($table_name.'.csv', 'w');
}
fputcsv($fp, $all_fields);

foreach ($ids as $id) {
  fputcsv($fp, $id);
}

fclose($fp);

if ($base_table_name == 'resource' || $base_table_name == 'custom') { // Create additional CSV files for field_collections articles/videos
  $filename = "swt_field_collection_".$base_table_name.'.csv';
  var_dump($filename);
  $fp = fopen($filename, 'w');
  $all_fields[] = 'guid';
  fputcsv($fp, $all_fields);
  foreach($ids as $count=>$id) {
    if (isset($id['quiz_accreditation'])) { //only write rows with non-null value for accreditation code
      if ($id['quiz_accreditation'] == 1) { //RACE only
        $id['quiz_accreditation'] = 'RACE';
        $id['guid'] = makeUUID(hash("md5",$id['id'].'RACE'));
        //var_dump($id['guid']);
        fputcsv($fp, $id);
      }
      elseif ($id['quiz_accreditation'] == 3) { //VHMA only
        $id['quiz_accreditation'] = 'VHMA';
        $id['quiz_race_id'] = '';
        $id['guid'] = makeUUID(hash("md5",$id['id'].'VHMA'));
        fputcsv($fp, $id);
      }
      elseif ($id['quiz_accreditation'] == 2) { //VHMA and RACE
        $id['quiz_accreditation'] = 'RACE';
        $id['guid'] = makeUUID(hash("md5",$id['id'].'RACE'));
        fputcsv($fp, $id);
        $id['quiz_accreditation'] = 'VHMA';
        $id['quiz_race_id'] = '';
        $id['guid'] = makeUUID(hash("md5",$id['id'].'VHMA'));
        fputcsv($fp, $id);
      }
    }
  }
}



function makeUUID($uuid) {
  return preg_replace('/([0-9a-f]{8})([0-9a-f]{4})([0-9a-f]{4})([0-9a-f]{4})([0-9a-f]{12})/','$1-$2-$3-$4-$5',$uuid);
}

function makeUsername($item) {
  global $conn;
  $username = NULL;
  $userquery = 'SELECT username FROM swt_people_data WHERE id="' . $item . '"';
  $userresult = $conn->query($userquery);
  if ($userresult) {
    while ($userrow = $userresult->fetch_assoc()) {
      $username = $userrow['username'];
    }
    //var_dump("username for ".$item." is ".$username);
  }
  else {
    //var_dump($item.' not found');
  }

  return $username;
}

function encodeToUtf8($string) {
  //$string = mb_convert_encoding($string, "UTF-8", mb_detect_encoding($string, "WINDOWS-1252, UTF-8, ISO-8859-1, ISO-8859-15, cp1252",TRUE));
  //var_dump (mb_detect_encoding($string,"auto",TRUE));

  //$string = iconv('UTF-8','ISO-8859-15',$string);
  //var_dump('working on '.$string);
  $string = htmlentities($string,ENT_NOQUOTES|ENT_SUBSTITUTE|ENT_HTML401,"UTF-8",FALSE);
  //var_dump("op 1: ".$string);
  $string = htmlspecialchars_decode($string,ENT_NOQUOTES|ENT_HTML401);
  //var_dump("op 2: ".$string);
  $string = mb_convert_encoding($string, "UTF-8", mb_detect_encoding($string, "UTF-8, ISO-8859-1, ISO-8859-15",TRUE));
  //var_dump('op 3: '.$string);
  return $string;
}


$conn->close();