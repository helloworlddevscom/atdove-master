<div class="section-wrapper">

    <?php print $user_picture; ?>
    <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; ?>

    <section class="node-content">
        <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
        <?php
            // Hide comments, tags, and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_tags']);
            hide($content['field_blog_image']);
            print render($content);
        ?>

    </section>

    <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
        <footer>
            <?php print render($content['field_tags']); ?>
            <?php //print render($content['links']); ?>
        </footer>
    <?php endif; ?>
        
</div>