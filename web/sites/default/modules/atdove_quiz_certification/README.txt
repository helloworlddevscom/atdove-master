-- SUMMARY --

This module adds "certifications" to quiz module for the Atdove site. A certification is a printable PDF that
shows that a user has completed a single quiz with a passing score. Any quiz node on the site can have a certification,
although only quizzes which are related to a video or article will have valid fields.

-- WHAT IS IMPLEMENTED --

The module contains several hook_view and hook_block statements that instantiate pages and blocks on the site.

  -- Blocks added

  Quiz actions block: This block should be placed somewhere visible, and its visibility settings set to Video and
  Article nodes only (and, I guess, subscriber role only). If the current user has not yet passed a quiz related to the
  current node, the block reads "Take Quiz" and links to the quiz page. If the current user has successfully passed the
  quiz related to the current node, the block reads "View Certificate" and links to the PDF version of the cert.

  My Certificates: This is a block that simply lists all the certificates awarded to the current user (as a UL,
  currently), each of which links to the PDF version of the certificate.

  -- Pages added

  Certificate page: This is a callback that works for any user and any quiz node id. If the nid is a valid quiz node,
  and the user has passed that quiz, the callback displays an HTML version of the certificate, passing values to the
  certificate.tpl.php file for themeing. These pages are visible at /node/[nid]/certificate.

  Certificate pdf: This is just a generated callback by the print module: a printable version of the certificate. They
  use the same access callbacks as the cert pages, and take the path /printpdf/node/[nid]/certificate

  Certificate report: This is a report for group admins only. It lists all users for the group the current user admins,
  along with any certificates they've achieved as comma-delimited lists of links. The path is
  my-organization/certificate-report.

  My Certificates: The same content as the My Certificates block, only exposed as a page at /my-account/my-certificates

  -- Additional stuff

  Modifying assignments: When a test is passed, the module looks for any assignments related to that quiz (via the
  related_quiz field on articles and videos) and that user. If any assignments are found, their completed_date is set
  to the current time() and their field_related_quiz fields are set to the just-completed quiz's nid.

  Printing links to certs: When a test is passed, the module prints a Drupal message allowing the user to either view
  the cert, or email it.

  Forward module form alter: When using Forward to send a certificate, the form is altered so that the recipients field
  is prepopulated with the email addresses of any group admins attached to the user's OG.