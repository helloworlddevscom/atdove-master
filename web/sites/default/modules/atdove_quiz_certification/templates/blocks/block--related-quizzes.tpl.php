<?php
/**
 * Template for Quizzes block. Renders quizzes related to an article or video.
 *
 * Renders link to Quiz and if Quiz has already been passed/completed, a link to certificate.
 */
?>

<section id="block--related-quizzes" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
    <?php
      // @TODO: Cannot figure out how to pass title to template.
    ?>
    <h2<?php print $title_attributes; ?>><?php print t('Quizzes'); ?></h2>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php if (!empty($quizzes)): ?>
      <ul class="item-list">
        <?php foreach($quizzes as $quiz): ?>
          <li class="item-list__item">
            <?php if (!$quiz['passed'] && $quiz['published']): ?>
              <a class="quiz-link" title="<?php print t('Take Quiz') ?>" href="/node/<?php print $quiz['nid']; ?>">
                <span class="quiz-link__icon"></span>
                <span class="quiz-link__text"><?php print $quiz['title']; ?></span>
              </a>
            <?php elseif ($quiz['passed'] && $quiz['published']): ?>
              <a class="quiz-link quiz-passed" title="<?php print t('Take Quiz Again') ?>" href="/node/<?php print $quiz['nid']; ?>">
                <span class="quiz-link__icon"></span>
                <span class="quiz-link__text"><?php print $quiz['title']; ?></span>
              </a>
            <?php elseif ($quiz['passed'] && !$quiz['published']): ?>
              <div class="quiz-link quiz-passed quiz-unpublished">
                <span class="quiz-link__icon"></span>
                <span class="quiz-link__text"><?php print $quiz['title']; ?></span>
              </div>
            <?php endif; ?>
            <?php if ($quiz['passed']): ?>
              <span class="divider"> | </span><a class="cert-link" href="/printpdf/node/<?php print $quiz['nid']; ?>/certificate" title="<?php print t('View Certificate'); ?>"><?php print t('View Certificate'); ?></a>
            <?php endif; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>
  </div>

</section> <!-- /.block -->
