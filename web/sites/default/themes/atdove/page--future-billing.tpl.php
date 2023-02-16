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
            
            <div class="billing-intro">
                <p class="bigP">Try us FREE for seven days!</p>
                <p class="smallP">Cancel any time before your free trial ends. Choose an option below:</p>
            </div>
            <!--p class="subP">Yearly subscribers get customer support 365 days a year, have time to create and see results
                from their custom training plans, and get access to any CE needed all year long. </p-->
            <?php print render($page['content']); ?>
        </div>

    </section> <!-- /#page-content -->

    <footer id="footer" role="contentinfo" class="clearfix">

        <?php include_once "footer.inc"; ?>

    </footer> <!-- /#footer -->

</div> <!-- /#page-wrapper -->

<?php if (user_is_logged_in()) { print render($page['suggest_content_modal']); } ?>
