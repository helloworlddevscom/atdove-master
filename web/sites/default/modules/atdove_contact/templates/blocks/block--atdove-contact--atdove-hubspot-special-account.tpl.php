<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div class="content__top">
      <p><?php print t('Do you have more than 125 employees or multiple locations? Will you need custom invoicing, or do you represent a school? Let us know!'); ?></p>
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
          formId: "b21521a0-fa3b-469d-8ae5-90cab8f1e8d1"
        });
      </script>
    </div>
  </div>

</section>
