<div class="section-wrapper" itemscope itemtype="http://schema.org/Organization">

    <?php print $user_picture; ?>
    <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; 
      if (isset($content['field_website']['#items'][0]['url'])) {
        $url = $content['field_website']['#items'][0]['url'];
        $url_array = explode('//', $url);
        $http = count($url_array) > 1 ? $url_array[0] : 'http:';
        $url = count($url_array) > 1 ? $url_array[1] : $url_array[0];
      }
    ?>

    <section class="node-content">
        <?php if ($title): ?><a href="<?php print $http . '//' . $url; ?>" target="_blank"><h1 class="title" id="page-title" itemprop="name"><?php print $title; ?></h1></a><?php endif; ?>
        <?php
            // Hide comments, tags, and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_tags']);
            hide($content['field_blog_image']);
            //print render($content);
        ?>
        <?php if(isset($field_clinic_logo[0]["uri"])): ?><meta itemprop="logo" content="<?php print drupal_realpath($field_clinic_logo[0]["uri"]); ?>"><?php endif; ?>
        <?php print render($content['field_clinic_logo']); ?>
        <div id="org-body" itemprop="description"><?php print render($content['body']); ?></div>
        <h3 itemprop="telephone"><?php print render($content['field_phone']['#items'][0]['value']); ?></h3>
        <div id="org-address" itemprop="address">
            <p><?php print render($content['field_street_address']['#items'][0]['value']); ?><br />
            <?php print render($content['field_city']['#items'][0]['value']); ?>,
            <?php print render($content['field_state']['#items'][0]['value']); ?><br />
            <?php print render($content['field_postal_code']['#items'][0]['value']); ?>
            <?php print render($content['field_country']['#items'][0]['value']); ?></p>
        </div>
    </section>

    <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
        <footer>
            <?php print render($content['field_tags']); ?>
            <?php //print render($content['links']); ?>
        </footer>
    <?php endif; ?>
        
</div>