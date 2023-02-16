<div class="home-node-wrapper">

    <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    //print render($content);
    ?>

    <?php if (!user_is_logged_in()) : ?>

        <div class="hero">
            <?php print render($content['field_wistia_iframe_anonymous']); ?>

            <div class="overlay"></div>
            <div class="intro">
                <?php if ($title): ?><h1 class="title"><?php print $title; ?></h1><?php endif; ?>
                <p><?php print isset($field_hero_intro_text[0]['value']) ? $field_hero_intro_text[0]['value'] : ''; ?></p>
                <div class="hero-buttons">
                    <a class="hero-cta-link two" href="<?php print isset($field_hero_cta_location_2[0]['value']) ? $field_hero_cta_location_2[0]['value'] : ''; ?>"><?php print isset($field_hero_cta_text_2[0]['value']) ? $field_hero_cta_text_2[0]['value'] : ''; ?></a>
                </div>
            </div>
        </div>

        <p class="after-hero-message"><?php print isset($field_after_hero_message[0]['value']) ? $field_after_hero_message[0]['value'] : ''; ?></p>

        <?php if (!empty($field_4x1_body)) : ?>
            <div class="home-section-wrapper home-video">
                <div class="home-content-wrapper">
                    <?php if (!empty($field_4x1_image)) : ?>
                        <img src="/<?php print variable_get('file_public_path', conf_path() . '/files'); ?>/<?php print ($field_4x1_image[0]['filename']); ?>" />
                    <?php endif; ?>
                    <div class="home-page-card">
                        <?php if (!empty($field_4x1_h2)) { print "<h2>".($field_4x1_h2[0]['value'])."</h2>"; }?>
                        <?php if (!empty($field_4x1_body)) { print ($field_4x1_body[0]['value']); } ?>
                    </div>
                    <div class="clearit"></div>
                </div>
            </div>
        <?php endif; ?>

        <?php if (!empty($field_4x2_h2)) : ?>
            <div class="home-section-wrapper home-dog">
                <div class="home-content-plain">
                    <?php if (!empty($field_4x2_image)) : ?>
                        <img src="/<?php print variable_get('file_public_path', conf_path() . '/files'); ?>/<?php print ($field_4x2_image[0]['filename']); ?>" />
                    <?php endif; ?>
                    <div class="home-box-text home-box-text-right">
                        <h2><?php print ($field_4x2_h2[0]['value']); ?></h2>
                        <?php if (!empty($field_4x2_body)) { print ($field_4x2_body[0]['value']); } ?>
                    </div>
                    <div class="clearit"></div>
                </div>
            </div>
        <?php endif; ?>

        <?php if (!empty($field_4x3_h2)) : ?>
            <div class="home-section-wrapper white-bg">
                <div class="home-content-wrapper">
                    <?php if (!empty($field_4x3_image)) : ?>
                        <img src="/<?php print variable_get('file_public_path', conf_path() . '/files'); ?>/<?php print ($field_4x3_image[0]['filename']); ?>" />
                    <?php endif; ?>
                    <div class="home-page-card">
                        <h2><?php print ($field_4x3_h2[0]['value']); ?></h2>
                        <?php if (!empty($field_4x3_body)) { print ($field_4x3_body[0]['value']); } ?>
                    </div>
                    <div class="clearit"></div>
                </div>
            </div>
        <?php endif; ?>

        <?php if (!empty($field_4x4_h2)) : ?>
            <div class="home-section-wrapper home-community">
                <div class="home-content-wrapper-plain">
                    <?php if (!empty($field_4x4_image)) : ?>
                        <img src="/<?php print variable_get('file_public_path', conf_path() . '/files'); ?>/<?php print ($field_4x4_image[0]['filename']); ?>" />
                    <?php endif; ?>
                    <div class="home-box-text home-box-text-left">
                        <h2><?php print ($field_4x4_h2[0]['value']); ?></h2>
                        <?php if (!empty($field_4x4_body)) { print ($field_4x4_body[0]['value']); } ?>
                    </div>
                    <div class="clearit"></div>
                </div>
            </div>
        <?php endif; ?>

        <?php if (!empty($field_4x5_h2)) : ?>
            <div class="home-section-wrapper white-bg">
                <div>
                    <div class="home-page-card ">
                        <h2 class="home-trusted"><?php print ($field_4x5_h2[0]['value']); ?></h2>
                        <div class="home-trusted"><?php if (!empty($field_4x5_body)) { print ($field_4x5_body[0]['value']); } ?></div>
                    </div>
                    <?php if (!empty($field_4x5_image)) : ?>
                        <img src="/<?php print variable_get('file_public_path', conf_path() . '/files'); ?>/<?php print ($field_4x5_image[0]['filename']); ?>" />
                    <?php endif; ?>
                    <div class="clearit"></div>
                </div>
            </div>
        <?php endif; ?>

        <?php if (!empty($field_4x6_h2)) : ?>
            <div class="home-section-wrapper lgreen-bg">
                <div class="home-headshot">
                    <div class="home-page-card">
                        <?php if (!empty($field_4x6_image)) : ?>
                            <img src="/<?php print variable_get('file_public_path', conf_path() . '/files'); ?>/<?php print ($field_4x6_image[0]['filename']); ?>" />
                        <?php endif; ?>
                        <blockquote><?php print ($field_4x6_h2[0]['value']); ?>
                            <cite><?php if (!empty($field_4x6_body)) { print ($field_4x6_body[0]['value']); } ?></cite>
                        </blockquote>
                    </div>
                    <div class="clearit"></div>
                </div>
            </div>
        <?php endif; ?>


        <section class="story-content">
            <div class="section-wrapper">

                <div class="overlay"></div>
                <img class="dove-logo" src="/<?php print drupal_get_path('theme', 'atdove'); ?>/images/dove-logo.jpg" />
                <h2><?php print ($field_dove_story_h2[0]['value']); ?></h2>
                <p><?php print ($field_dove_story_body[0]['value']); ?></p>
            </div>
        </section>

        <div class="home-accred white-bg">
            <?php if (!empty($field_home_logos_body)) { print ($field_home_logos_body[0]['value']); } ?>
        </div>

    <?php endif; ?>
    <?php if (user_is_logged_in()) : ?>

        <div class="home-page-section">
            <?php
            $block = module_invoke('views', 'block_view', 'home_page_assignments_view-block');
            print render($block['content']);
            ?>
            <div class="clearit"></div>
        </div>

        <div class="home-page-section">
            <hr/>
            <?php
            $block = module_invoke('views', 'block_view', 'news_and_events-block');
            print render($block['content']);
            ?>
        </div>
        <div class="clearit"></div>

        <div class="home-page-section">
            <hr/>
            <?php
            $blockVideo = module_invoke('views', 'block_view', 'home_page_video_view-block');
            print render($blockVideo['content']);
            ?>
            <div class="clearit"></div>
        </div>

    <?php endif; ?>

    <script type="text/javascript" src="//downloads.mailchimp.com/js/signup-forms/popup/unique-methods/embed.js" data-dojo-config="usePlainJson: true, isDebug: false"></script><script type="text/javascript">window.dojoRequire(["mojo/signup-forms/Loader"], function(L) { L.start({"baseUrl":"mc.us5.list-manage.com","uuid":"ffc9fb9d1e048ee09b8eb9ce8","lid":"63cbfeb96f","uniqueMethods":true}) })</script>

    <footer>
        <?php print render($content['field_tags']); ?>
        <?php //print render($content['links']); ?>
    </footer>

</div>
