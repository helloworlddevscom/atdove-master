<?php

/**
 * User access checking for the certification race report.
 *
 * Allowed roles:
 *   Superadmin
 *   Administrator
 *   Billing admin
 *
 * @return bool
 *   TRUE if allowed, FALSE if not allowed.
 */
function atdove_quiz_certification_race_report_access() {
  global $user;
  if (
    $user->uid == 1
    || !empty(array_intersect(
      $user->roles,
      [
        'administrator',
        'Billing Admin',
      ]
    ))
  ) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Content rendering for the race report
 */
function  atdove_quiz_certification_race_report() {

  $result = atdove_quiz_certification_race_report_certifications_get_query(TRUE);

  // @todo see about better way to do this? Fetch assoc? Fetch all keyed?
  // Get results, put into a renderable array of values,
  $quizes = [];

  while ($quiz = $result->fetchAssoc()) {
    // @todo see about converting time_end in the query to date format?
    $quiz['completed_clean_date'] = date('m/d/Y', $quiz['time_end']);
    $quizes[] = $quiz;
  }

  if (!empty($quizes)) {

    $output = theme('table',
      [
        'header' => array_keys($quizes[0]),
        'rows' => $quizes,
        'caption' => "<a href='/" . current_path() . "/csv'>" . t("CSV EXPORT"). "</a>",
      ]
    );

    $output .= theme('pager');

    // @todo place current amount of certifications into the page
    return $output;
  }
  else {
    $content = 'There are currently no users with R.A.C.E. credentials who have received any certificates by completing a quiz.';
    return $content;
  }
}

/**
 * Race report CSV path for generating the race report CSV. Triggers batch.
 */
function  atdove_quiz_certification_race_report_csv() {
  $filename = 'race_report_' . date('m_d_Y_H_i') . '.csv';

  $batch = array(
    'operations' => array(
      array('atdove_quiz_certification_race_report_csv_batch', [$filename]),
    ),
    'finished' => 'atdove_quiz_certification_race_report_csv_batch_finished',
    'title' => t('Generating R.A.C.E. Report CSV'),
    'init_message' => t('R.A.C.E. Report is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('R.A.C.E. Report CSV has encountered an error.'),
    'file' => drupal_get_path('module', 'atdove_quiz_certification') . '/includes/atdove_quiz_certification_race_report.inc',
  );
  batch_set($batch);
  batch_process('admin/reports/race-certification');
}

/**
 * Batch processor for generating CSV file.
 *
 * Accepts filename as the parameter. Is generated with timestamp from time batch is opened.
 */
function atdove_quiz_certification_race_report_csv_batch($filename, &$context) {
  global $base_path;
  $directory = 'public://race_reports/';
  $file_path = 'sites/default/files/race_reports/' . $filename;
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
  $_SESSION['csv_path'] = $base_path . $file_path;

  // Establish the basics.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['certifications'] = atdove_quiz_certification_race_report_certifications_get_query();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['currentRow'] = 0;
    $context['sandbox']['iteration'] = 20;
    $context['sandbox']['max'] = $context['sandbox']['certifications']->rowCount();
  }
  // Make the race reports directory. Only makes if not existent.
  $file = fopen(DRUPAL_ROOT . '/' . $file_path, 'a') or die("can't open file");

  // @todo Write table headings here.
  $limit = 20;

  // @todo Add check that we aren't exceeding max returned values from DB results.
  // Loop through $limit amount of times.
  for ($x = 0; $x < $limit; $x++) {
    if ($row = $context['sandbox']['certifications']->fetchAssoc()) {
      $csv_row = [
        'CEB_Provider_Number' => '50-27291',
        'CEB_Course_Number' => $row['field_accreditation_id_value'],
        'blank_1' => '',
        'blank_2' => '',
        'numeric_license_number' => $row['field_license_id_number_value'],
        'completion_date' => date('m/d/Y', $row['time_end']),
        'state' => strtoupper($row['field_license_state_value']),
      ];
      // Determine vet or vet tech.
      if ($row['field_license_type_value'] == 'vet') {
        $csv_row['profession'] = 'V';
      }
      else {
        $csv_row['profession'] = 'VT';
      }
      // Render the CSV row.
      $stringData = implode(',', array_values($csv_row)) . "\n";
      fwrite($file, $stringData);
      $context['sandbox']['progress']++;
    }

  }

  fclose($file);

  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Completion of batch process function.
 *
 * Sets message with link to last generated CSV.
 */
function atdove_quiz_certification_race_report_csv_batch_finished($success, $results, $operations) {
  if ($success) {
    $link = $_SESSION['csv_path'];
    // Message with external link.
    $path = $_SESSION['csv_path'];
    drupal_set_message(
      t("CSV link to RACE report: <a href='$path'>Race Report CSV File.</a>")
    , 'status');
  } else {
    // @todo: Add error handling.
  }
}

/**
 * Generates the query for race report certifications.
 *
 * @param false $paged
 *   Whether to run the query as a paged set of results or not.
 *
 * @return \DatabaseStatementInterface|null
 *   The query results.
 */
function atdove_quiz_certification_race_report_certifications_get_query($paged = FALSE) {
  // Get the quiz fields.
  if ($paged) {
    $query = db_select('field_data_field_related_quiz','frq')->extend('PagerDefault');
  }
  else {
    $query = db_select('field_data_field_related_quiz','frq');
  }

  $query->join('quiz_node_properties','qnp','frq.field_related_quiz_target_id = qnp.nid');
  $query->join('quiz_node_results','qnr','frq.field_related_quiz_target_id = qnr.nid');
  // Only get quizzes the user passed.
  $query->where('qnr.score > qnp.pass_rate');

  // Get the user table.
  $query->join('users','usr','usr.uid = qnr.uid');
  // Get all Field values from the user relating to RACE certification.
  $query->join('field_data_field_license_id_number', 'rlid', 'rlid.entity_id = qnr.uid');
  $query->join('field_data_field_license_state', 'rfls', 'rfls.entity_id = qnr.uid');
  $query->join('field_data_field_license_type', 'rflt', 'rflt.entity_id = qnr.uid');

  // Get the video or article this relates to.
  $query->join('node','node','node.nid = frq.entity_id');
  $query->where(
    'node.type IN (:types)',
    [':types' => ['article', 'video']]
  );
  // Get the accreditation values in from from article or video.
  $query->join('field_data_field_accreditation_info','fai','node.nid = fai.entity_id');
  $query->join('field_data_field_accreditations','facc','facc.entity_id = fai.field_accreditation_info_value');
  $query->join('field_data_field_accreditation_id','faccid','faccid.entity_id = fai.field_accreditation_info_value');
  // Restrict this to accreditation of TID 1 aka RACE.
  $query->where('facc.field_accreditations_tid = 1');

  // Fetch all values we're interested in putting in the table/csv.
  if ($paged) {
    $query->fields('node', ['title', 'type', 'nid']);
    $query->fields('faccid', ['field_accreditation_id_value']);
    $query->fields('usr', ['uid', 'mail']);
    $query->fields('qnr', ['time_end']);
    $query->fields('rlid', ['field_license_id_number_value']);
    $query->fields('rfls', ['field_license_state_value']);
    $query->fields('rflt', ['field_license_type_value']);
  }
  else {
    // Fetch all the values we need fo the CSV.
    $query->fields('faccid', ['field_accreditation_id_value']);
    $query->fields('usr', ['mail']);
    $query->fields('qnr', ['time_end']);
    $query->fields('rlid', ['field_license_id_number_value']);
    $query->fields('rfls', ['field_license_state_value']);
    $query->fields('rflt', ['field_license_type_value']);
  }


  // This reduces duplicates we were getting for some reason.
  $query->groupBy('qnr.result_id');
  $query->groupBy('qnr.uid');

  // Add header sorting and paging by default, add a page limit as well.
  $query->orderby('qnr.time_end', 'desc');

  if ($paged) {
    $query->limit(20);
  }

  $results = $query->execute();

  return $results;
}
