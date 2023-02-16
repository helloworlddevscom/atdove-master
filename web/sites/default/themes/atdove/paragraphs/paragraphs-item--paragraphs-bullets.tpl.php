<section class="paragraph bullets-wrapper">
    
    <div class="content-wrapper">
        <h2><?php print render($content['field_paragraphs_header'][0]['#markup']); ?></h2>

        <ul>
            <?php foreach(($content['field_paragraphs_bullet']['#items']) as $listItemText) {
                print '<li>' . $listItemText['value'] . '</li>';
            } ?>
        </ul>
    </div>
    
</section>