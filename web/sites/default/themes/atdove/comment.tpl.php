<article class="<?php print $classes . ' ' . $zebra; ?>"<?php print $attributes; ?>>
    
    <?php print $picture; ?>
  
    <div itemprop="comment" class="content"<?php print $content_attributes; ?>>
        
        <header>

            <div class="submitted">
                <div class="user-info">
                    <?php print $author; ?>
                    <?php print $created; ?>
                </div>
            </div>

        </header>
        
        <?php hide($content['links']); print render($content); ?>
        
        <?php if ($signature): ?>
            <div class="user-signature clearfix">
                <?php print $signature ?>
            </div>
        <?php endif; ?>
        
        <?php if (!empty($content['links'])): ?>
            <div class="comment-footer">
                <?php print render($content['links']) ?>
            </div>
        <?php endif; ?>
        
    </div>

    <div class="clearit"></div>
</article> <!-- /.comment -->
