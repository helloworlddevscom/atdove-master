    <div id="footer-navigation" role="navigation" class="clearfix">
        <?php print theme('links__system_main_menu', array('links' => $main_menu)); ?>
    </div>

    <div class="section-wrapper">

        <div class="footer-box">
            <h2>Community</h2>
            <?php print theme('links', array('links' => menu_navigation_links('menu-community'), 'attributes' => array('class'=> array('links', 'menu-community')) ));?>
        </div>
        <div class="footer-box">
            <h2>Connect</h2>
            <?php print theme('links', array('links' => menu_navigation_links('menu-connect'), 'attributes' => array('class'=> array('links', 'menu-connect')) ));?>
        </div>
        <div class="footer-box">
            <h2>Contact</h2>
            <?php print theme('links', array('links' => menu_navigation_links('menu-contact'), 'attributes' => array('class'=> array('links', 'menu-contact')) ));?>
        </div>
        
        <div class="clearit"></div>
    </div>

    <p class="copyright">&copy; <?php print date('Y'); ?> DoveLewis - All Rights Reserved | <a href="/node/21113">Terms of Use</a> | <a href="/node/21114">Privacy Policy</a></p>

<?php
    print render($page['pop_notifications_section']);
?>