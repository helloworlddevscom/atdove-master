<!--Main Navigation-->

<div class="header-top">

  <a class="logo-link" href="/"><img class="menu-logo" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>

  <a href="#" class="hamburger">
    <div class="beef-patty"></div>
    <div class="beef-patty"></div>
    <div class="beef-patty"></div>
  </a>

  <div class="sign-up-menu">
    <?php print theme('links', array('links' => menu_navigation_links('menu-sign-up-menu'), 'attributes' => array('class'=> array('links', 'menu-sign-up-menu')) ));
    ?>

    <div class="clearit"></div>
    <div class="site-search">
      <?php
        $blocksearch = module_invoke('search', 'block_view', 'search');
        print render($blocksearch);
      ?>
    </div>
  </div>
  <div class="clearit"></div>
</div>

<nav id="navigation" role="navigation">

  <?php $menu = menu_tree('main-menu');
    $menuhtml = drupal_render($menu);
    print $menuhtml;
  ?>

  <div class="clearit"></div>

</nav>

<?php if (user_is_logged_in() && ($isBillingPage!=true)) : ?>

  <div class="user-menu">

      

    <?php if ($assignmentNotification > 0) : ?>
      <a href="/my-account/my-assignments">
        <span class="assignment-notification-count">You Have
          <span class="assignment-count">
            <?php print $assignmentNotification; ?>
          </span> Assignment<?php print $assignmentNotification > 1 ? "s" : ''; ?>
        </span>
      </a>
    <?php endif; ?>

    <?php $user_menu = menu_tree('user-menu');
      $menuuser = drupal_render($user_menu);
      print $menuuser;
    ?>

    <div class="suggest-content-link">

      <?php print theme('links', array('links' => menu_navigation_links('menu-recommend-content'), 'attributes' => array('class'=> array('links', 'menu-recommend-content')) ));
      ?>

    </div>
    <div class="clearit"></div>

  </div>
<?php endif; ?>

<!-- /Main Navigation -->
<a id="totop"></a>
