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
            
            <div class="checkout-intro">
                <p>Your first 7 days are free! Your credit card will be charged when your free trial ends.</p>
            </div>
            
            <?php print render($page['content']); ?>

            <!-- (c) 2005, 2016. Authorize.Net is a registered trademark of CyberSource Corporation --> <div class="AuthorizeNetSeal"> <script type="text/javascript" language="javascript">var ANS_customer_id="3ddda44a-5e5a-4906-badb-ad7b843af6a0";</script> <script type="text/javascript" language="javascript" src="//verify.authorize.net/anetseal/seal.js" ></script> <a href="http://www.authorize.net/" id="AuthorizeNetText" target="_blank">Merchant Services</a> </div>
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