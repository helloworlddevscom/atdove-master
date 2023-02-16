<header id="header" role="banner" class="clearfix">

    <?php print render($page['header']); ?>
    <?php include_once('navigation.inc'); ?>

</header> <!-- /#header -->

<div id="page-wrapper" class="clearfix" itemscope itemtype="http://schema.org/Article">
    <div itemprop="publisher" itemscope itemtype="https://schema.org/Organization">
        <div itemprop="logo" itemscope itemtype="https://schema.org/ImageObject">
            <meta itemprop="url" content="https://www.atdove.org/sites/atdove.org/files/atdove_logo_sm_horz.png">
            <meta itemprop="width" content="248">
            <meta itemprop="height" content="60">
        </div>
        <meta itemprop="name" content="atdove.org">
    </div>

    <meta itemprop="mainEntityOfPage" content="https://www.atdove.org">
    <?php if($title):?><meta itemprop="headline" content="<?php print $title;?>"><?php endif; ?>
    <?php if (isset($node->created)):?><meta itemprop="datePublished" content="<?php print date('c', $node->created) ?>"><?php endif; ?>
    <?php if (isset($node->revision_timestamp)):?><meta itemprop="dateModified" content="<?php print date('c', $node->revision_timestamp) ?>"><?php endif; ?>
    <?php if (isset($node->field_image["und"][0]["uri"])):?><meta itemprop="image" content="<?php print file_create_url($node->field_image["und"][0]["uri"]); ?>"><?php endif; ?>
    

    <section id="page-content" role="main" class="clearfix">
        
        <?php print $messages; ?>
        
        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div><?php endif; ?>
        
        <div class="section-wrapper">
            <div class="article-header">
                <?php $articleImage = field_view_field('node', $node, 'field_image', array('label'=>'hidden')); print render($articleImage); ?>
                <?php if ($title): ?><h1 class="article-title" id="page-title" itemprop="name"><?php print $title; ?></h1><?php endif; ?>
                <?php if (isset($node->body['und'][0]['summary'])): ?>
                    <span class="article-summary" itemprop="description"><?php print $node->body['und'][0]['summary']; ?></span>
                <?php endif; ?>
                <p class="view-count">Views: <span><?php print $viewcount; ?></span> - Comments: <span itemprop="commentCount"><?php print $node->comment_count; ?></span></p>
            </div>
            <div class="clearit"></div>
            <?php print theme('breadcrumb', array('breadcrumb'=>drupal_get_breadcrumb())); ?>
            
            <div class="main-left-col" itemprop="articleBody">
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