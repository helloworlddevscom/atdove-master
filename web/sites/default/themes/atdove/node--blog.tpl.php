<div class="video-node-wrapper">

    <?php
        // Hide comments, tags, and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_tags']);
        //print render($content);
    ?>
    
    <div class="section-wrapper">
        <div itemprop="publisher" itemscope itemtype="https://schema.org/Organization">
            <div itemprop="logo" itemscope itemtype="https://schema.org/ImageObject">
                <meta itemprop="url" content="https://www.atdove.org/sites/atdove.org/files/atdove_logo_sm_horz.png">
                <meta itemprop="width" content="248">
                <meta itemprop="height" content="60">
            </div>
            <meta itemprop="name" content="atdove.org">
        </div>
        <meta itemprop="mainEntityOfPage" content="https://www.atdove.org">
        <?php if ($created):?><meta itemprop="datePublished" content="<?php print date('c', $created) ?>"><?php endif; ?>
        <?php if ($revision_timestamp):?><meta itemprop="dateModified" content="<?php print date('c', $revision_timestamp) ?>"><?php endif; ?>
        <?php if (isset($field_image[0]["uri"])): ?><meta itemprop="image" content="<?php print file_create_url($field_image[0]["uri"]); ?>"><?php endif; ?>
        <?php if ($title): ?>
            <h1 class="title" id="page-title" itemprop="headline"><?php print $title; ?></h1>
            <meta itemprop="name" content="<?php print $title; ?>">
        <?php endif; ?>
        <p class="view-count"><span id="pub-date">Posted: <?php print format_date($node->created, 'custom', 'M j, Y'); ?></span><br>Views: <span><?php print $viewcount ?></span> - Comments: <span itemprop="commentCount"><?php print $comment_count ?></span></p>
        <?php print theme('breadcrumb', array('breadcrumb'=>drupal_get_breadcrumb())); ?>
    
        <?php print render($content['field_blog_image']); ?>

        <div itemprop="articleBody"><?php print ($body[0]['value']); ?></div>
        
        <div class="clearit"></div>

    </div>
        
</div>