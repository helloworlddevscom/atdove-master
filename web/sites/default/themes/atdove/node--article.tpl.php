<div class="section-wrapper">

    <?php print $user_picture; ?>
    <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; ?>

    <section class="node-content">

        <?php
            // Hide comments, tags, and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_tags']);
            //print render($content);
        ?>
        
        <?php print ($body[0]['value']); ?>

    </section>
    
    <?php $_SESSION['contributorName'] = $content['field_contributors'][0]['#markup']; ?>
</div>