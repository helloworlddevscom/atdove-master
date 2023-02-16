<section class="image-with-text <?php print $content['field_float_option']['#items'][0]['value']; ?>" style="background-color: <?php print $content['field_background_color_option']['#items'][0]['value']; ?>">
    
    <div class="content-wrapper">
    
        <div class="image-wrapper">
            <img src="<?php print image_style_url("1280px_wide", $content['field_image'][0]['#item']['uri']); ?>" />
        </div>

        <div class="text-wrapper">

            <h2><?php print render($content['field_dove_story_h2'][0]['#markup']); ?></h2>
            <p><?php print $content['field_hero_intro_text']['#items'][0]['value']; ?></p>
            <?php print render($content['field_url']); ?>

        </div>
        
    </div>
    
</section>