<?php
  // comment subscribe link
  $links = node_view($node);
  print render($links['links']['node']);
?>
<section id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($content['comments']); ?>
  <?php if ($content['comment_form']): ?>
    <section id="comment-form-wrapper">
      <?php print render($content['comment_form']); ?>
    </section> <!-- /#comment-form-wrapper -->
  <?php endif; ?>
</section> <!-- /#comments -->
