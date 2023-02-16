<div class="home-node-wrapper">


        <div class="hero">
            <img src="<?php print image_style_url("hero", $content['field_featured_image'][0]['#item']['uri']); ?>" />

            <div class="overlay"></div>
            <div class="intro">
                <?php if ($title): ?><h1 class="title"><?php print $title; ?></h1><?php endif; ?>
                <?php if ($content['field_after_hero_message']['#items'][0]['value']): ?><h2 class="hero-subheader"><?php print render($content['field_after_hero_message']['#items'][0]['value']); ?></h2><?php endif; ?>
                <p><?php print render($content['field_hero_intro_text']['#items'][0]['value']); ?></p>
                <?php print render($content['field_url']); ?>
            </div>
        </div>
    
        <?php print render($content['field_paragraphs']); ?>

     <footer>
        <?php //print render($content['links']); ?>
    </footer>

</div>
