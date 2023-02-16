<!DOCTYPE html>
<!--[if lt IE 7]> <html class="ie6 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 7]>    <html class="ie7 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 8]>    <html class="ie8 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if gt IE 8]> <!--> <html class="" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <!--<![endif]-->
<head>
  <?php print $head; ?>
  <!-- Set the viewport width to device width for mobile -->
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1" />
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <link href="https://fonts.googleapis.com/css?family=Molengo" rel="stylesheet" type="text/css">
  <link href="https://fonts.googleapis.com/css?family=Roboto+Slab:100" rel="stylesheet" type="text/css">
  <link href="https://fonts.googleapis.com/css?family=Roboto" rel="stylesheet" type="text/css">
  <link href="https://fonts.googleapis.com/css?family=Oswald" rel="stylesheet" type="text/css">
  <?php print $scripts; ?>
  <!-- IE Fix for HTML5 Tags -->
  <!--[if lt IE 9]>
    <script src="https://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->

    <script src="//fast.wistia.com/static/embed_shepherd-v1.js"></script>
    <script>
        wistiaEmbeds.onFind(function(video) {
          video.videoFoam(true);
        });
    </script>

    <script>

        (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
        (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
        m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
        })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

        ga('create', 'UA-24611161-1', 'auto');//atdove account
        ga('require', 'displayfeatures');

        <?php
          $account = user_load($user->uid);

          if (isset($account->og_user_node['und'][0]['target_id'])){
            $organizationId = $account->og_user_node['und'][0]['target_id'];
          }

          if(isset($GLOBALS['user']->roles[6])){
            $visitorType = $GLOBALS['user']->roles[6];
          }

          if(isset($account->field_title['und'][0]['value'])) {
            $visitorTitle = $account->field_title['und'][0]['value'];
          }

        ?>

        ga('set', 'dimension1', '<?php print str_replace('-', '', $account->uuid); ?>');
        ga('set', 'dimension2', '<?php print isset($organizationId) ? $organizationId : ''; ?>');
        ga('set', 'dimension3', '<?php print isset($visitorType) ? $visitorType : ''; ?>');
        ga('set', 'dimension4', '<?php print isset($visitorTitle) ? $visitorTitle : ''; ?>');
        ga('set', 'dimension5', '');
        ga('set', 'dimension6', '<?php print isset($account->uid) ? $account->uid : ''; ?>');


        <?php
          $alias_parts = explode('/', drupal_get_path_alias());
          if (count($alias_parts) > 1) {
            switch ($alias_parts[0]) {
              case 'checkout':
                if (end($alias_parts) == 'complete') {
        ?>
                  ga('require', 'ecommerce');
                  ga('ecommerce:addTransaction', {
                    'id': '<?php print $ga_order; ?>',
                    'affiliation': '<?php print $ga_org_name; ?>',
                    'revenue': '<?php print $ga_prod_cost; ?>'
                  });
                  ga('ecommerce:addItem', {
                    'id': '<?php print $ga_order; ?>',
                    'name': '<?php print $ga_prod_name; ?>',
                    'price': '<?php print $ga_prod_cost; ?>',
                    'sku': '<?php print $ga_prod_name; ?>'
                  });
                  ga('ecommerce:send');
        <?php
                }
            }
          }
        ?>
        ga('send', 'pageview');
    </script>

    <!-- Facebook Pixel Code -->
    <script>
    !function(f,b,e,v,n,t,s)
    {if(f.fbq)return;n=f.fbq=function(){n.callMethod?
    n.callMethod.apply(n,arguments):n.queue.push(arguments)};
    if(!f._fbq)f._fbq=n;n.push=n;n.loaded=!0;n.version='2.0';
    n.queue=[];t=b.createElement(e);t.async=!0;
    t.src=v;s=b.getElementsByTagName(e)[0];
    s.parentNode.insertBefore(t,s)}(window, document,'script',
    'https://connect.facebook.net/en_US/fbevents.js');
    fbq('init', '980191578716378');
    fbq('track', 'PageView');
    </script>
    <noscript><img height="1" width="1" style="display:none"
    src="https://www.facebook.com/tr?id=980191578716378&ev=PageView&noscript=1"
    /></noscript>
    <!-- End Facebook Pixel Code -->

</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

    <div class="userID"><?php if (user_is_logged_in()) { print str_replace('-', '', $account->uuid); } else { print"Not Logged In"; } ?></div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>

</html>
