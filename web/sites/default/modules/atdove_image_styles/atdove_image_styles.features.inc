<?php
/**
 * @file
 * atdove_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function atdove_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 1280px_wide.
  $styles['1280px_wide'] = array(
    'label' => '1280px Wide',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1280,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero.
  $styles['hero'] = array(
    'label' => 'Hero',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_photo.
  $styles['profile_photo'] = array(
    'label' => 'Profile Photo',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 287,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: square400.
  $styles['square400'] = array(
    'label' => 'Square400',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: square800.
  $styles['square800'] = array(
    'label' => 'Square800',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
