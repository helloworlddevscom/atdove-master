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

            <div class="<?php if ($page['sidebar_second']): ?>main-left-col<?php endif; ?><?php if (!$page['sidebar_second']): ?>single-main-col<?php endif; ?>">
                <?php print render($page['content']); ?>
            </div>

            <?php if ($page['sidebar_second']): ?>
                <aside id="sidebar-second" role="complementary" class="sidebar">
                  <?php print render($page['sidebar_second']); ?>
                </aside>  <!-- /#sidebar-second -->
            <?php endif; ?>
        </div>

    </section> <!-- /#page-content -->

    <?php print render($page['comments']); ?>
    <?php if (!user_is_logged_in()) { print render($page['sign_up_cta']); } ?>

    <footer id="footer" role="contentinfo" class="clearfix">

        <?php include_once "footer.inc"; ?>

    </footer> <!-- /#footer -->

</div> <!-- /#page-wrapper -->

<?php if (user_is_logged_in()) { print render($page['suggest_content_modal']); } ?>

<a class="to-top-arrow" href="#totop"><img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/small-icons/to-top-arrow.png" /></a>
