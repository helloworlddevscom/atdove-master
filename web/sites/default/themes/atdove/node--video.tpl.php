<div class="section-wrapper">

    <?php print $user_picture; ?>
    <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; ?>

    <section class="node-content <?php if(isset($field_special_class['und'][0]['value'])) print $field_special_class['und'][0]['value'];?>">

        <?php
            // Hide comments, tags, and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_tags']);
            //print render($content);
        ?>

        <?php if(isset($field_special_class['und'][0]['value'])):?>
        <span class="<?php print $field_special_class['und'][0]['value'];?>">&nbsp;</span>
        <?php endif; ?>
        
        <?php if ($title): ?>
        <h1 class="video-title" id="page-title" itemprop="name"><?php print $title; ?>
        </h1><?php endif; ?>
        
        <p class="view-count">Views: <?php print $viewcount; ?> - Comments: <span itemprop="commentCount"><?php print $comment_count ?></span></p>
        
        <?php if (isset($field_duration[0]["value"]))?> <meta itemprop="duration" content="<?php print "P{$field_duration[0]["value"]}S";?>">
        
        <?php if (isset($field_image[0]["uri"]))?><meta itemprop="thumbnailUrl" content="<?php print file_create_url($field_image[0]["uri"]); ?>">
        
        <?php if (isset($created))?><meta itemprop="uploadDate" content="<?php print date('c', $created) ?>">
        
        <span class="video-description" itemprop="description"><?php print isset($body[0]['value']) ? $body[0]['value'] : ''; ?></span>

        <?php if (!empty($content['field_additional_download_links'])): ?>
        
            <h4>Downloads:</h4>
            <span class="video-downloads"><?php print render($content['field_additional_downloads']); ?>
            <div class="clearit"></div></span>

        <?php endif; ?>

    </section>

   <?php
    $checklist_user = in_array('Subscriber', $user->roles) || in_array('administrator', $user->roles);
    if (isset($content['field_checklist']) && $checklist_user) : ?>
    <div id="printthis">
      <div id="site_logo">
        <?php
          if (theme_get_setting('toggle_logo')) {
            $image = array(
              'path' => theme_get_setting('logo'),
              'alt' => 'my logo',
            );
            print theme('image', $image);
          }
        ?>
      </div>
      <h1 class="checklist"><?php print $title; ?></h1>
      <div class="clearit"></div>
      <?php print render($content['field_checklist']); ?>
      <p class="checklist-copyright">&copy; 2017 DoveLewis - All Rights Reserved</p>
    </div>

    <a class="printthisbutton" href="#">
      <?php
        if (!isset($content['field_addon_button'])){
          print ("Print Checklist");
        }
        else {
          print render($content['field_addon_button']);
        }
      ?>
    </a>
  <?php endif; ?>
</div>
