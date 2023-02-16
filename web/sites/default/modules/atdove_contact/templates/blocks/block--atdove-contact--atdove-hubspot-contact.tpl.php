<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div class="content__top">
      <p><?php print t('Have a question? Visit our <a href="/help-center">help center</a> for detailed answers to common questions. If you can’t find what you need, please fill out the form below and you will hear back from our team as soon as possible. We suggest users contact us directly with questions about their account. Thank you!'); ?></p>
    </div>
    <div class="content__bottom">
      <!--[if lte IE 8]>
      <script charset="utf-8" type="text/javascript" src="//js.hsforms.net/forms/v2-legacy.js"></script>
      <![endif]-->
      <script charset="utf-8" type="text/javascript" src="//js.hsforms.net/forms/v2.js"></script>
      <script>
        hbspt.forms.create({
          region: "na1",
          portalId: "20523696",
          formId: "69356dc0-ba28-4ecb-b5c4-18fd264c49b9"
        });
      </script>
    </div>
  </div>

</section>
