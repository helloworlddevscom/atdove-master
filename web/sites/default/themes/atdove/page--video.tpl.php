<header id="header" role="banner" class="clearfix">

    <?php print render($page['header']); ?>
    <?php include_once('navigation.inc'); ?>
</header> <!-- /#header -->

<div id="page-wrapper" class="clearfix" itemscope itemtype="http://schema.org/VideoObject">

    <section id="page-content" role="main" class="clearfix">

        <?php print $messages; ?>

        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div><?php endif; ?>
        
        <div class="section-wrapper">
            
            <?php print theme('breadcrumb', array('breadcrumb'=>drupal_get_breadcrumb())); ?>
            
            <?php print isset($accessible_video) ? $accessible_video : ''; ?>

            <div class="main-left-col">
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

<?php
// inject some js to fix poster files for users that don't have access
if(isset($poster_fix)) {
    $pattern = '/wistia_async_([a-zA-Z0-9]+)/'; // match pattern on wistia async embed codes
    preg_match($pattern, $poster_fix, $matches);
    if ($matches[1]) {
        $wistia_url = "http://fast.wistia.net/oembed?url=http://home.wistia.com/medias/$matches[1]&height=720";
        $response = drupal_http_request($wistia_url);
        $wistia_json = json_decode($response->data, true);
        $path = drupal_get_path('theme', 'atdove');
        drupal_add_js(array('VideoPage' => array('wistiaId' => $wistia_json["thumbnail_url"])), 'setting');
        drupal_add_js("$path/js/fix_poster.js");
    }
}
?>