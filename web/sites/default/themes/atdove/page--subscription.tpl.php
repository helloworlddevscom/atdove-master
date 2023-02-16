<header id="header" role="banner" class="clearfix">

    <?php print render($page['header']); ?>
    <?php include_once('navigation.inc'); ?>

</header> <!-- /#header -->

<div id="page-wrapper" class="clearfix">
    
    <section id="page-content" role="main" class="clearfix">
        
        <?php print $messages; ?>
        
        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div><?php endif; ?>
        
        <div class="section-wrapper">
            
            <?php print render($page['content']); ?>

        </div> 
                
    </section> <!-- /#page-content -->
    
    <footer id="footer" role="contentinfo" class="clearfix">
        
        <?php include_once "footer.inc"; ?>
        
    </footer> <!-- /#footer -->

</div> <!-- /#page-wrapper -->

<?php if (user_is_logged_in()) { print render($page['suggest_content_modal']); } ?>

<div class="assign-to-person-modal">
    <h2>Content Assignment</h2>
    
    <a class="close-person-modal-window" href="#">X</a>
    
    <div class="modal-inner-wrapper">
    
        <h3>Assign to person</h3>
        <select multiple="multiple">
            <option value="Article">Article</option>
            <option value="Blog">Blog</option>
            <option value="Video">Video</option>
        </select>

        <h3>Assign to group</h3>
        <select multiple="multiple">
            <option value="Group 1">Group 1</option>
            <option value="Group 2">Group 2</option>
            <option value="Group 3">Group 3</option>
        </select>
        
    </div>
    
</div>