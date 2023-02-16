<?php if ($title): ?><h2 class="title" id="page-title"><?php print $title; ?></h2><?php endif; ?>
        
<span class="commerce-price"><?php print render($content['product:commerce_price'][0]['#markup']); ?></span>
<span class="option-notes"><?php print render($content['field_option_notes'][0]['#markup']); ?></span>
<?php print render($content['field_subcription_types_availabl']); ?>

<?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
        <?php print render($content['field_tags']); ?>
        <?php //print render($content['links']); ?>
    </footer>
<?php endif; ?>