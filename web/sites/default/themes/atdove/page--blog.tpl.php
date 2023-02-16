<header id="header" role="banner" class="clearfix">

    <?php print render($page['header']); ?>
    <?php include_once('navigation.inc'); ?>

</header> <!-- /#header -->

<div id="page-wrapper" class="clearfix" itemscope itemType="http://schema.org/BlogPosting">
    <?php if(isset($node->field_contributors["und"][0]["entity"]->field_blog_title["und"][0]["value"])): ?>
        <meta itemprop="articleSection" content="<?php print $node->field_contributors["und"][0]["entity"]->field_blog_title["und"][0]["value"]?>">
    <?php endif; ?>
    <?php if(isset($node->field_contributors["und"][0]["entity"]->field_blog_description["und"][0]["value"])): ?>
        <meta itemprop="description" content="<?php print $node->field_contributors["und"][0]["entity"]->field_blog_description["und"][0]["value"]?>">
    <?php endif; ?>

    <section id="page-content" role="main" class="clearfix">

        <?php print $messages; ?>

        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div><?php endif; ?>

        <div class="section-wrapper">

            <div class="main-left-col">
                <?php print render($page['content']); ?>
            </div>

            <?php if ($page['sidebar_second']): ?>
                <aside id="sidebar-second" role="complementary" class="sidebar">
                  <?php print render($page['sidebar_second']); ?>

                    <?php //if($html->find('.checkToPrintRSSFeedButton', 0)) : ?>
<!--                        <a class="rss-feed" href="<?php //$pathPiece = explode('/', drupal_get_path_alias()); print($pathPiece[0] . '/' . $pathPiece[1] . '/rss/'); ?>">RSS Feed</a>-->
                    <?php //endif; ?>

                    <div class="rss-button-goes-here"></div>

                    <script>
                        jQuery(document).ready(function ($) {

                            if ($('.checkToPrintRSSFeedButton').length) {

                                var blogURLPath = location.pathname.split("/");
                                var newURLPath = '<a class="rss-feed" href="/' + blogURLPath[1] + '/' + blogURLPath[2] + '/rss">RSS Feed</a>';
                                var drupalSideBar = $('#sidebar-second');
                                $('.rss-button-goes-here').html(newURLPath);
                            }

                        });
                    </script>

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