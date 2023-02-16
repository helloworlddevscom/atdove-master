(function($) {

$(document).ready(function() {

    ////** Mobile Menu Button To Show and Hide **////
    var hamburger = $('a.hamburger');
    var pageWrapper = $('#page-wrapper');
    var homePageWrapper = $('#home-page-wrapper');
    hamburger.click(function() {
        if (pageWrapper.hasClass('move-body')) {
            pageWrapper.removeClass('move-body');
        }
        else {
            pageWrapper.addClass('move-body')
        }
        if (homePageWrapper.hasClass('move-body')) {
            homePageWrapper.removeClass('move-body');
        }
        else {
            homePageWrapper.addClass('move-body')
        }
    });

    ////** Remove billing user account info from checkout complete page **////
    $('.pane.account').hide();

    ////** Add tooltips to the browse page buttons **////
    $('a.user-button-browse').each(function() {
        var titleText = $(this).attr('title');
        $(this).append('<span class="tooltip">' + titleText + '</span>');
    });

    $('a.training-plan-clone-button').each(function() {
        var titleText = $(this).attr('title');
        $(this).append('<span class="tooltip">' + titleText + '</span>');
    });

    $('span.bookmark-span').each(function() {
        var titleText = $(this).attr('title');
        $(this).append('<span class="tooltip">' + titleText + '</span>');
    });

    $('span.bookmark-icon').each(function() {
        var titleText = $(this).attr('title');
        $(this).append('<span class="tooltip">' + titleText + '</span>');
    });

    ////** Close the featured video on the browse pages **////
    $('a.close-featured-video').click(function() {
        $('.view-highlighted-video').slideUp();
    });

    ////** Confirm account non-renewal **////
    $('.why-not').hide();
    $('#dont-renew-final').hide();
    $('#dont-renew').click(function(e) {
      e.preventDefault();
      $('#dont-renew').hide();
      $('.why-not').show();
      $('#dont-renew-final').show();
    });

    ////** Remove text from the browse page bookmark button **////
    var flagWrapper = $('.view-content-for-users .flag-wrapper a');
    var fakeFlagWrapper = $('.redTooltip');
    var fieldOps = $('.view-highlighted-video .views-field-ops a');
    flagWrapper.empty();
    fieldOps.empty();

    flagWrapper.each(function() {
        if ($(this).hasClass('unflag-action')) {
            $(this).parent().siblings('span.tooltip').text('REMOVE FROM BOOKMARKS');
        }
        if ($(this).hasClass('flag-action')) {
            $(this).parent().siblings('span.tooltip').text('BOOKMARK THIS CONTENT');
        }
    });

    $(document).ajaxComplete(function(){
        var flagWrapper = $('.view-content-for-users .flag-wrapper a');
        var fieldOps = $('.view-highlighted-video .views-field-ops a');
        flagWrapper.empty();
        fieldOps.empty();

        flagWrapper.each(function() {
            if ($(this).hasClass('unflag-action')) {
                $(this).parent().siblings('span.tooltip').text('REMOVE FROM BOOKMARKS');
            }
            if ($(this).hasClass('flag-action')) {
                $(this).parent().siblings('span.tooltip').text('BOOKMARK THIS CONTENT');
            }
        });

    });

    ////** Remove text from the browse page bookmark button **////
    var flagWrapper = $('.view-blog-bookmark-button .flag-wrapper a');
    var fakeFlagWrapper = $('.redTooltip');
    flagWrapper.empty();

    flagWrapper.each(function() {
        if ($(this).hasClass('unflag-action')) {
            $(this).parent().siblings('span.tooltip').text('REMOVE FROM BOOKMARKS');
        }
        if ($(this).hasClass('flag-action')) {
            $(this).parent().siblings('span.tooltip').text('BOOKMARK THIS CONTENT');
        }
    });

    $(document).ajaxComplete(function(){
        var flagWrapper = $('.view-blog-bookmark-button .flag-wrapper a');
        flagWrapper.empty();

        flagWrapper.each(function() {
            if ($(this).hasClass('unflag-action')) {
                $(this).parent().siblings('span.tooltip').text('REMOVE FROM BOOKMARKS');
            }
            if ($(this).hasClass('flag-action')) {
                $(this).parent().siblings('span.tooltip').text('BOOKMARK THIS CONTENT');
            }
        });

    });

    ////** Remove text from the browse page bookmark button **////
    var flagWrapper = $('.view-video-page-bookmark-button .flag-wrapper a');
    var fakeFlagWrapper = $('.redTooltip');
    flagWrapper.empty();

    flagWrapper.each(function() {
        if ($(this).hasClass('unflag-action')) {
            $(this).parent().siblings('span.tooltip').text('REMOVE FROM BOOKMARKS');
        }
        if ($(this).hasClass('flag-action')) {
            $(this).parent().siblings('span.tooltip').text('BOOKMARK THIS CONTENT');
        }
    });

    $(document).ajaxComplete(function(){
        var flagWrapper = $('.view-video-page-bookmark-button .flag-wrapper a');
        flagWrapper.empty();

        flagWrapper.each(function() {
            if ($(this).hasClass('unflag-action')) {
                $(this).parent().siblings('span.tooltip').text('REMOVE FROM BOOKMARKS');
            }
            if ($(this).hasClass('flag-action')) {
                $(this).parent().siblings('span.tooltip').text('BOOKMARK THIS CONTENT');
            }
        });

    });


    fakeFlagWrapper.text('BOOKMARKING IS A PREMIUM FEATURE');

    ////** Show Suggest Content Pop-up **////
    var block393 = $('#block-webform-client-block-393');
    $('ul.menu-recommend-content li a').click(function(e) {
        e.preventDefault();
        block393.fadeIn('fast');
    });
//    $('ul.menu-contact li.last a').click(function(e) {
//        e.preventDefault();
//        block393.fadeIn('fast');
//    });
    $('#block-webform-client-block-393 .webform-component-markup').click(function() {
        block393.fadeOut('fast');
    });

    ////** Show hide the help center content on click **////
    $('.help-topic-content').hide();
    $('.view-help-cnter h2').click(function() {
        $(this).next('.help-topic-content').slideToggle();
        $(this).parent('.views-row').siblings().children('.help-topic-content').slideUp();
    });

    ////** Rotate carrot on help center **////
    if ($('.view-help-cnter').length) {
        $('h2.Help, h2.FAQ').click(function () {
            if ($(this).children('.help-carrot').hasClass('help-carrot-down')) {
                $(this).children('.help-carrot').removeClass('help-carrot-down');
            } else {
                $(this).children('.help-carrot').addClass('help-carrot-down');
                $(this).parent('.views-row').siblings().find('.help-carrot').removeClass('help-carrot-down');
            }
        });
    }

    ////** Fix "Clear Filter" links on views with exposed filters and displayed as blocks **////
        //Views implemented as Blocks that have exposed filters have an error when using the reset button.
        //See https://www.drupal.org/project/views/issues/1109980
        //This implements: https://www.drupal.org/project/views/issues/1109980#comment-10421063
        //Currently this bug is only found on the Admin Training Plans (stock). I will fence in the JS to that form. (views-exposed-form-admin-training-plans-stock-plans-block)
    $(document).on('click','#views-exposed-form-admin-training-plans-stock-plans-block #edit-reset', function (event) {
        //take away the form action
        event.preventDefault();
        //reset form values
        $('#views-exposed-form-admin-training-plans-stock-plans-block').each(function(){
            $('#views-exposed-form-admin-training-plans-stock-plans-block select option').removeAttr('selected');
            $('#views-exposed-form-admin-training-plans-stock-plans-block input[type=text]').attr('value', '');
            this.reset();
        });
        //resubmit the form with the reset values.
        $('#views-exposed-form-admin-training-plans-stock-plans-block .views-submit-button .form-submit').click();
    });
    $(document).on('click','#views-exposed-form-my-assignments-block-1 #edit-reset', function (event) {
        //take away the form action
        event.preventDefault();
        //reset form values
        $('#views-exposed-form-my-assignments-block-1').each(function(){
            $('#views-exposed-form-my-assignments-block-1 select option').removeAttr('selected');
            $('#views-exposed-form-my-assignments-block-1 input[type=text]').attr('value', '');
            this.reset();
        });
        //resubmit the form with the reset values.
        $('#views-exposed-form-my-assignments-block-1 .views-submit-button .form-submit').click();
    });

    ////** Sync Height **////
    $('.manager-grid').syncHeight({ 'updateOnResize': true});

    $('.people-wrapper').syncHeight({ 'updateOnResize': true});
    $('.blogs-wrapper').syncHeight({ 'updateOnResize': true});

    $(window).load(function () {
        var minWidth = 800;
        if ($(window).width() > minWidth) {
            $('.view-id-home_page_assignments_view .views-row').syncHeight({ 'updateOnResize': true });
            $('.node-type-news-room-page .views-row').syncHeight({ 'updateOnResize': true });
            $('.news-events-wrapper').syncHeight({ 'updateOnResize': true });
            $('.home-page-video').syncHeight({ 'updateOnResize': true });
        }
    });

    /* Let's turn off sync height for small viewports */
    $(window).resize(function () {
        var minWidth = 800;
        if ($(window).width() <= minWidth) {
            $('.view-id-home_page_assignments_view .views-row').unSyncHeight();
            $('.node-type-news-room-page .views-row').unSyncHeight();
            $('.news-events-wrapper').unSyncHeight();
            $('.home-page-video').unSyncHeight();
        } else if ($(window).width() > minWidth) {
            $('.view-id-home_page_assignments_view .views-row').syncHeight({ 'updateOnResize': true });
            $('.node-type-news-room-page .views-row').syncHeight({ 'updateOnResize': true });
            $('.news-events-wrapper').syncHeight({ 'updateOnResize': true });
            $('.home-page-video').syncHeight({ 'updateOnResize': true });
        }
    });

    if ($('.view-content-for-users select').length) {
        $('#edit-type-1').attr('data-placeholder', 'Content Type');
        $('#edit-type-1')[0][0]['textContent'] = 'Medical Articles';
        $('#edit-type-1')[0][1]['textContent'] = 'Personal Blogs';
        $('#edit-type-1')[0][2]['textContent'] = 'Videos';
        $('#edit-field-content-category-tid').attr('data-placeholder', 'Content Category');
    }

    function applyChosen () {
        var deviceTest = (/android|webos|iphone|ipad|ipod|blackberry|iemobile|opera mini/i.test(navigator.userAgent.toLowerCase()));
        if (deviceTest == false) {
            ////** Start chosen **////
            if ($('select').length) {
                $('.views-exposed-form select').chosen();
                $('#-atdove-member-cert-form select').chosen();
                $('.adminSelectGroup').chosen();
                $('.page-my-organization-organization-manage .vbo-views-form #edit-operation').chosen();


            }
        }
        if (deviceTest == true) {
            $('.view-content-for-users .views-exposed-form label').css('display', 'block');
        }
    }

    applyChosen();

    //reapply chosen after ajax (for forms with exposed filters and displayed as blocks
    $(document).ajaxComplete(function(){
        applyChosen();
    });

    ////** comment Subscribe/Unsubscribe alter displayed link **////
    $('.subscribe').children().html('Follow this discussion');
    $('.unsubscribe').children().html('Unfollow this discussion');

    ////** login alter displayed link **////
    $('.menu-sign-up-menu').find('a').html(function() {
      switch($(this).html()) {
        case 'Logout':
          return 'Scrub Out';
        case 'Login':
          return 'Scrub In';
        default:
          break;
      }
    });

    ////** Responsive Tables **////
    $('.view-assignments-admin table').wrap('<div class="table-wrapper"></div>');
    $('.view-my-assignments table').wrap('<div class="table-wrapper"></div>');
    $('.view-admin-training-plans-all-plans table').wrap('<div class="table-wrapper"></div>');
    $('#-atdove-member-cert-form table').wrap('<div class="table-wrapper"></div>');

    ////** Smooth Scroll on click **////
    var scrollButton = $("a.to-top-arrow");
    if (scrollButton.length) {
        scrollButton.hide();
    }

    scrollButton.click(function() {
        $("html, body").animate({ scrollTop: 0 }, "slow");
        return false;
    });

    $(window).scroll(function () {
        var scrollPos = $(window).scrollTop();
        ////** Show/Hide scroll button on scroll **////
        if (scrollPos > 600) {
            scrollButton.fadeIn();
        } else {
            scrollButton.hide();
        }
    });

    ////** Add poster image to hero video **////
    if ($('.hero').length) {
        $('.hero').find('video').attr('poster', 'https://embed-ssl.wistia.com/deliveries/b4cc1ec60fcb890beb621343197a99813ca703b8.jpg');
    }

    ////** Print Stuff **////
    $('a.printthisbutton').click(function (e) {
        e.preventDefault();
        var left  = ($(window).width()),
            top   = ($(window).height());
        //Use this stylesheet link for Production
        var styleSheet = '<link rel="stylesheet" href="https://www.atdove.org/sites/atdove.org/themes/atdove/print-styles.css" type="text/css" />';
        //Use this stylesheet link for local dev
//        var styleSheet = '<link rel="stylesheet" href="http://local.atdove.org/sites/atdove.org/themes/atdove/print-styles.css" type="text/css" />';
        var printFont = '<link href="https://fonts.googleapis.com/css?family=Roboto:100" rel="stylesheet" type="text/css">';
        var prtContent = document.getElementById("printthis");
        var WinPrint = window.open('');
        WinPrint.document.write('<html><head>' +
                                styleSheet +
                                printFont +
                                '</head><body>' +
                                prtContent.innerHTML +
                                '</body></html>');
        WinPrint.document.close();
        WinPrint.focus();
        setTimeout(function(){ WinPrint.print(); },500);
        setTimeout(function() { WinPrint.close(); },500);
    });

    //Set Height of Page Wrapper for Mobile Menu
    var fromTop = $(".header-top").height() + 40;
    if ($(window).width() < 801) {
        $('#page-wrapper, #home-page-wrapper').css('top', fromTop);
    }

    //add note to csv field in checkout page
    var csvField = $('.form-item-commerce-payment-payment-details-credit-card-code');
    csvField.append('<img class="csvIcon" src="/sites/atdove.org/themes/atdove/images/icons/csv-icon.png" />');

    //Slick Slider
    $('.slick-slider-view-block-wrapper .testimonials-slider-wrapper').slick({
        autoplay: true,
        arrows: true,
        autoplaySpeed: 3000,
    });

    $('.view-partners .view-content').slick({
        slidesToShow: 5,
        slidesToScroll: 1,
        autoplay: true,
        autoplaySpeed: 3000,
    });

  // Handle R.A.C.E. form element visibility.
  if ($('form#user-profile-form').length) {
    // Set initial visibility.
    if (!$('select[name="field_license_type[und]"] option[selected]').length) {
      $('div#edit-field-license-state').hide();
      $('div#edit-field-license-id-number').hide();
    }
    // Change visibility based on license type.
    $('select[name="field_license_type[und]"]').change(function(){
      if (this.value == '_none') {
        $('div#edit-field-license-state').hide();
        $('div#edit-field-license-id-number').hide();
      }
      else {
        $('div#edit-field-license-state').show();
        $('div#edit-field-license-id-number').show();
      }
    });
  }
});

$(window).resize(function () {
    var fromTop = $(".header-top").height() + 40;
    if ($(window).width() < 801) {
         $('#page-wrapper, #home-page-wrapper').css('top', fromTop);
    }
});

/**
 * AtDove custom login form toggle functionality.
 * See: docroot/sites/atdove.org/modules/dl_openid/templates/blocks/block--atdove-custom-login-form.tpl.php
 */
var loginToggle = false;
Drupal.behaviors.loginToggle = {
  attach: function(context, settings) {
    // Attempt to resolve behavior being called multiple times per page load.
    if (context !== document) {
      return;
    }
    if (!loginToggle) {
      loginToggle = true;
    }
    else {
      return;
    }

    // Check if login form exists.
    if ($('#block--atdove-custom-login-form').length) {
      $('.normal-login-toggle').on('click tap touch', function(e) {
        e.preventDefault();
        e.stopPropagation();
        $(this).next('.login-form').toggleClass('active');
      });
    }
  }
};

}(jQuery));
