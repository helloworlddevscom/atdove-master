(function ($) {
    Drupal.behaviors.VideoPage = {
        attach: function (context) {
            //console.log("Fix URL: " + Drupal.settings.VideoPage.wistiaId);
            $('.wistia_embed').attr('id', 'wistia_embed');
            window.wistiaInitQueue = window.wistiaInitQueue || [];
            window.wistiaInitQueue.push(function(W) {
                W.options('wistia_embed', {stillUrl: Drupal.settings.VideoPage.wistiaId});
            });
        }
    }
})(jQuery);