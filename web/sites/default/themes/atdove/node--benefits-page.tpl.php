    <?php print $user_picture; ?>
    <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; ?>

    <section class="node-content">
        
        <?php
            // Hide comments, tags, and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_tags']);
            hide($content['field_blog_image']);
            //print render($content);
        ?>
        <?php if (isset($content['field_benefits_text_1']) || isset($content['field_benefits_image_1']) || isset($content['field_benefits_video_1'])) : ?>
            <div class="lblue-bg">
                <div class="benefit-wrapper">
                    <?php if (isset($content['field_benefits_text_1'])) { print render($content['field_benefits_text_1']); } ?>
                    <?php if (isset($content['field_benefits_image_1'])) { print render($content['field_benefits_image_1']); } ?>
                    <?php if (isset($content['field_benefits_video_1'])) : ?>
                        <div class="benefits-video-wrapper">
                            <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                            <div class="benefits-video-inner-wrapper">
                                <?php print render($content['field_benefits_video_1']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if (isset($content['field_benefits_text_2']) || isset($content['field_benefits_image_2']) || isset($content['field_benefits_video_2'])) : ?>
            <div class="">
                <div class="benefit-wrapper">
                    <?php if (isset($content['field_benefits_text_2'])) { print render($content['field_benefits_text_2']); } ?>
                    <?php if (isset($content['field_benefits_image_2'])) { print render($content['field_benefits_image_2']); } ?>
                    <?php if (isset($content['field_benefits_video_2'])) : ?>
                        <div class="benefits-video-wrapper">
                            <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                            <div class="benefits-video-inner-wrapper">
                                <?php print render($content['field_benefits_video_2']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if (isset($content['field_benefits_text_3']) || isset($content['field_benefits_image_3']) || isset($content['field_benefits_video_3'])) : ?>
            <div class="green-bg">
                <div class="benefit-wrapper">
                    <?php if (isset($content['field_benefits_text_3'])) { print render($content['field_benefits_text_3']); } ?>
                    <?php if (isset($content['field_benefits_image_3'])) { print render($content['field_benefits_image_3']); } ?>
                    <?php if (isset($content['field_benefits_video_3'])) : ?>
                        <div class="benefits-video-wrapper">
                            <div class="benefits-video-inner-wrapper">
                                <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                                <?php print render($content['field_benefits_video_3']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if (isset($content['field_benefits_text_4']) || isset($content['field_benefits_image_4']) || isset($content['field_benefits_video_4'])) : ?>
            <div class="">
                <div class="benefit-wrapper benefit-small">
                    <?php if (isset($content['field_benefits_text_4'])) { print render($content['field_benefits_text_4']); } ?>
                    <?php if (isset($content['field_benefits_image_4'])) { print render($content['field_benefits_image_4']); } ?>
                    <?php if (isset($content['field_benefits_video_4'])) : ?>
                        <div class="benefits-video-wrapper">
                            <div class="benefits-video-inner-wrapper">
                                <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                                <?php print render($content['field_benefits_video_4']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if (isset($content['field_benefits_text_5']) || isset($content['field_benefits_image_5']) || isset($content['field_benefits_video_5'])) : ?>
            <div class="dark-bg">
                <div class="benefit-wrapper benefit-small">
                    <?php if (isset($content['field_benefits_text_5'])) { print render($content['field_benefits_text_5']); } ?>
                    <?php if (isset($content['field_benefits_image_5'])) { print render($content['field_benefits_image_5']); } ?>
                    <?php if (isset($content['field_benefits_video_5'])) : ?>
                        <div class="benefits-video-wrapper">
                            <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                            <div class="benefits-video-inner-wrapper">
                                <?php print render($content['field_benefits_video_5']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if (isset($content['field_benefits_text_6']) || isset($content['field_benefits_image_6']) || isset($content['field_benefits_video_6'])) : ?>
            <div class="">
                <div class="benefit-wrapper">
                    <?php if (isset($content['field_benefits_text_6'])) { print render($content['field_benefits_text_6']); } ?>
                    <?php if (isset($content['field_benefits_image_6'])) { print render($content['field_benefits_image_6']); } ?>
                    <?php if (isset($content['field_benefits_video_6'])) : ?>
                        <div class="benefits-video-wrapper">
                            <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                            <div class="benefits-video-inner-wrapper">
                                <?php print render($content['field_benefits_video_6']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if (isset($content['field_benefits_text_7']) || isset($content['field_benefits_image_7']) || isset($content['field_benefits_video_7'])) : ?>
            <div class="lblue-bg">
                <div class="benefit-wrapper benefit-small">
                    <?php if (isset($content['field_benefits_image_7'])) { print render($content['field_benefits_image_7']); } ?>
                    <?php if (isset($content['field_benefits_text_7'])) { print render($content['field_benefits_text_7']); } ?>
                    <?php if (isset($content['field_benefits_video_7'])) : ?>
                        <div class="benefits-video-wrapper">
                            <img src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-imac-blank.png" />
                            <div class="benefits-video-inner-wrapper">
                                <?php print render($content['field_benefits_video_7']); ?>
                            </div>
                            <div class="clearit"></div>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif; ?>

    </section>

    <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
        <footer>
            <?php print render($content['field_tags']); ?>
            <?php //print render($content['links']); ?>
        </footer>
    <?php endif; ?>