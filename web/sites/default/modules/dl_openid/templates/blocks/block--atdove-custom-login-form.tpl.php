<?php
/**
 * Template for AtDove custom login block.
 *
 * Renders default login block plus the OpenID connect module button which links to OpenAthens SSO.
 */
?>

<section id="block--atdove-custom-login-form" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php
  // @TODO: Cannot figure out how to pass title to template.
  ?>
  <h1<?php print $title_attributes; ?>><?php print t('Scrub In'); ?></h1>
  <?php print render($title_suffix); ?>
  <span class="register-link"><?php print t('Not a member yet? '); ?><a href="/user/register"><?php print t('Sign Up') ?></a></span>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      $block_object = block_load('openid_connect', 'openid_connect_login');
      $block = _block_get_renderable_array(_block_render_blocks(array($block_object)));
      $output = drupal_render($block);
      print $output;

    ?>
    <a href="#" class="normal-login-toggle"><?php print t('Email Login'); ?> </a>
    <?php
      $form = drupal_get_form('user_login');
      $output = drupal_render($form);
      print $output;
    ?>
  </div>

</section>
