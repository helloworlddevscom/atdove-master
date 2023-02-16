<!--

Available variables from atdove_quiz_certification.module:
SEE FUNCTION: atdove_quiz_certification_display_certificate

$username = Drupal username
$full_name = First + last name
$certificate_title = The title of the node that's related to the quiz (article or video)
$credit_hours = The number of credit hours listed in the related node
$duration = If a video, the running time as listed in the related node
$matter_category = the RACE category
$accredited_for = DVM, Technician or PM
$accreditations = an array of all accreditations (may be multiples) as follows:
  $accreditations[0]['type'] is the kind of accreditation, e.g., RACE or VHMA
  $accreditations[0]['id'] is the ID of the accreditation in question, currently only applies to RACE
$contributors = array of contributor names to attribute to content
  $contributors[#]['name']

-->
<div class="certificate-background"></div>

<div class="section-wrapper">

  <section class="node-content">

      <p class="smallP">This certifies that</p>
      <p class="cert-user-name"><?php print $full_name; ?></p>
      <hr class="print-hr" />
      <p class="specialP">Has successfully completed <a href="node/<?php print $certificate_id; ?>">
          <?php print $certificate_title; ?></a> <?php if(isset($contributors[0]['name'])) print " by " . $contributors[0]['name']. " "; ?>
          on <?php print $certificateDateEarned; ?>
      </p>
    <?php

    if (empty($accreditations)) {
      $html = <<<HTML
      <p class="supersmallP">This content has not been pre-approved by any accrediting body for continuing education credit.
      Please check with your licensure for more information about applicability.</p>
HTML;
      print $html;
    }
    else {
      foreach ($accreditations as &$value){
        if($value['type'] == 'RACE'){
          if(isset($accredited_for)){
              if(isset($matter_category)){
                /* The RACE Categories assuming we only do  non-interactive distance */
                  switch($matter_category){
                    case "Scientific Program":
                      $cat = <<<EOL
                        <p class="smallP">Category One: Scientific using the delivery method of Non-Interactive-Distance. This approval is valid in
                        jurisdictions which recognize AAVSB RACE; however, participants are responsible for ascertaining each board's
                        CE requirements. RACE does not "accredit" or "endorse" or "certify" any program or person, nor does RACE
                        approval validate the content of the program.</p><br />
EOL;
                      break;
                    case "Non-Scientific Clinical":
                      $cat = <<<EOL
                        <p class="smallP">Category Two: Non-Scientific-Clinical using the delivery method(s) of: Non-Interactive-Distance. This
                        approval is valid in jurisdictions which recognize AAVSB RACE; however, participants are responsible for
                        ascertaining each board's CE requirements.</p><br />
EOL;
                      break;
                    case "Non-Scientific Pract. Mgmt, Prof. Dev.":
                      $cat =<<<EOL
                        <p class="smallP">Category Three: Non-Scientific-Practice Management/Professional Development using the delivery method(s) of:
                        Non-Interactive-Distance. This approval is valid in jurisdictions which recognize AAVSB RACE; however,
                        participants are responsible for ascertaining each board's CE requirements.</p><br />
EOL;
                        break;
                    default:
                        $cat = "Unknown Category";
                  }
              }
              if($accredited_for == "DVM"){
                $html = <<<HTML
                    <p class='smallP'>This program <strong># {$value['id']} </strong> is approved by the AAVSB RACE
                    to offer a total of $credit_hours CE Credits ($credit_hours max) being available to any one
                    veterinarian: and/or $credit_hours Veterinary Technician CE Credits ($credit_hours max).
                    This RACE approval is for the subject matter categories of:</p><br />
HTML;
                 print $html;
                 print $cat;
              }
              elseif ($accredited_for == "Technician"){
                $html = <<<HTML
                    <p class='smallP'>This program <strong># {$value['id']} </strong> is approved by the AAVSB RACE to
                    offer a total of 0 CE Credits (0 max) being available to any one veterinarian:
                    and/or $credit_hours Veterinary Technician CE Credits ($credit_hours max). This RACE approval is for
                    the subject matter categories of: </p><br />
HTML;
                print $html;
                print $cat;
              }
              elseif ($accredited_for == "PM"){
                $html = <<<HTML
                    <p class='smallP'>This program <strong># {$value['id']} </strong> is approved by the AAVSB RACE to
                    offer a total of $credit_hours CE Credits ($credit_hours max) being available to any one veterinarian:
                    and/or $credit_hours Veterinary Technician CE Credits ($credit_hours max). This RACE approval is for
                    the subject matter categorie(s) of: </p><br />
HTML;
                print $html;
                print $cat;
              }
              else {
                  // something went wrong, should have accredited for
                watchdog("atdove_quiz_certification","certificate.tpl.php: Accredited for does not exist",Null,WATCHDOG_ERROR);
              }
          }
          else{
            // This should not happen because $accredited_for for should be set
            watchdog("atdove_quiz_certification","certificate.tpl.php: Accredited for missing",Null,WATCHDOG_ERROR);
            $html = <<<HTML
                <p class="smallP">This program <strong>#{$value['id']}</strong> is approved by the AAVSB RACE to offer a
                total of $credit_hours CE Credits, with a maximum of $credit_hours CE Credits being
                available to any individual veterinarian or veterinary technician/technologist.</p>
                <p class="smallP">This RACE approval is for the subject matter categories of: $matter_category using the
                delivery method of Non-Interactive-Distance.</p>
                <p>This approval is valid in jurisdictions which recognize AAVSB RACE; however, participants are
                responsible for ascertaining each board's CE requirements.</p>
HTML;
            print $html;
          }
        }
        else if($value['type'] == 'VHMA'){
          $html = <<<HTML
            <p class="smallP">This program is approved for $credit_hours on demand CE credits for the Certified
            Veterinary Practice Manager program offered by the Veterinary Hospital Managers Association.</p><br />
HTML;
          print $html;
        }
      }
    }
    ?>

  </section>

</div>
