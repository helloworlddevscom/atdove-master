<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
$field_body = isset($row->field_body[0]['raw']['safe_value']) ? $row->field_body[0]['raw']['safe_value'] : '';
$form = '<form method="post" action="/node/add/training-plan">';
$form .= '<input type="hidden" name="edit[title]" value="'.$row->node_title.'">';
$form .= '<input type="hidden" name="edit[body][und][0][value]" value="' . $field_body . '">';

$articles='';
$articles_array = array();
foreach($row->field_field_related_articles as $count=>$article) {
  if ($count > 0) {$articles .= ',';}
  $articles .= str_replace(' ',' ',$row->field_field_related_articles_1[$count]['rendered']['#markup']).' ('.$article['raw']['target_id'].')';
  $articles_array[] = $article['raw']['target_id'];
}
$form .= '<input type="hidden" name="edit[field_related_articles][und]" value="'.$articles.'">';

$videos='';
$videos_array = array();
foreach($row->field_field_related_videos as $count=>$video) {
  if ($count > 0) {$videos .= ',';}
  $videos .= str_replace(' ',' ',$row->field_field_related_videos_1[$count]['rendered']['#markup']).' ('.$video['raw']['target_id'].')';
  $videos_array[] = $video['raw']['target_id'];
}
$form .= '<input type="hidden" name="edit[field_related_videos][und]" value="'.$videos.'">';

if ($articles_array) {
  print '<label>Articles</label><ul>';
  foreach ($articles_array as $article) {
    $article_node = node_load($article);
    print '<li><a href="/node/' . $article_node->nid . '">' . $article_node->title . '</a></li>';
  }
  print '</ul>';
}

if ($videos_array) {
  print '<label>Videos</label><ul>';
  foreach ($videos_array as $video) {
    $video_node = node_load($video);
    print '<li><a href="/node/' . $video_node->nid . '">' . $video_node->title . '</a></li>';
  }
  print '</ul>';
}

$form .= '<input type="submit" class="stock-plan-submit">';
$form .= '</form>';
print $form;
?>
