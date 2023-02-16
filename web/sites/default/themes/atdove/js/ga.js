jQuery(document).ready(function ($) {

    var pathName = window.location.pathname;
    var pageTitle = $('h1').text();
    var userID = $('.userID').text();

    //Track Banner Clicks
    $('a.banner').click(function() {
        var bannerCategory = $(this).attr('id');
        ga('send', 'event',  'Banner', 'Clicked', bannerCategory);
    });

    //Track MKBanner Clicks
    $('a.mkbanner').click(function() {
        var mkBannerCategory = $(this).attr('id');
        ga('send', 'event',  'MKBanner', 'Clicked', mkBannerCategory);
    });

    //Track Social Sharing Link Clicks
    $('.addthis_toolbox a').click(function() {
        var socialType = $(this).attr('title');
        if (socialType == "Facebook") {
            ga('send', 'social',  socialType, 'Like', pathName);
        }
        if (socialType == "Tweet") {
            ga('send', 'social',  socialType, 'Tweet', pathName);
        }
        if (socialType == "LinkedIn") {
            ga('send', 'social',  socialType, 'Share on LinkedIn', pathName);
        }
        if (socialType == "Google+") {
            ga('send', 'social',  socialType, 'Share on Google+', pathName);
        }
    });

    //Track PDF Download Clicks
    $('a[href$=".pdf"]').click(function() {
        var filePath = $(this).attr('href');
        ga('send', 'event',  'Download', 'PDF', filePath);
    });
    $('a.print-pdf').click(function() {
        var filePath = $(this).attr('href');
        ga('send', 'event',  'Download', 'PDF', filePath);
    });

    //Track Video Download Content Clicks
    $('.node-type-video a.download').click(function() {
        var filePath = $(this).attr('href');
        ga('send', 'event',  'Download', 'Video Downloads', filePath);
    });

    //Track Article Checklist Download Clicks
    $('a.printthisbutton').click(function() {
        var filePath = $(this).html();
        ga('send', 'event',  'Download', 'Article Checklist', pathName);
    });

    //Track News Room Link Clicks
    $('a.news-room').click(function() {
        var newsPath = $(this).attr('href');
        ga('send', 'event',  'News-Room', 'news', newsPath);
    });

    //Track Quiz Button Clicks
    $('a.quiz').click(function() {
        ga('send', 'event',  'Take Quiz', userID, pathName);
    });

    //Track Assignment Button Clicks
    $('a.person').click(function() {
        ga('send', 'event',  'Assign To Person', userID, pathName);
    });
    $('a.training').click(function() {
        ga('send', 'event',  'Add To Training', userID, pathName);
    });
    $('a.user-button-browse').click(function() {
        var titleText = $(this).attr('title');
        var dataId = $(this).attr('data-id');
        ga('send', 'event',  'Browse Page Assign Buttons', dataId, titleText);
    });

    //Track Bookmark Button Clicks
    $('a.flag-action').click(function() {
        ga('send', 'event',  'Bookmark Button', Bookmarked, pathName);
    });
    $('a.unflag-action').click(function() {
        ga('send', 'event',  'Bookmark Button', 'Un-Bookmarked', pathName);
    });

    //Track Add Comments Button Clicks
    $('li.comment-add a').click(function() {
        ga('send', 'event',  'Add New Comment', userID, pageTitle);
    });

    //Track Comment Subscribe Button Clicks
    $('li.subscribe a').click(function() {
        ga('send', 'event',  'Subscribe To Comments', userID, pageTitle);
    });

    //Track Homepage Hero Button Clicks
    $('a.hero-cta-link').click(function() {
        var buttonText = $(this).text();
        ga('send', 'event',  'Hero CTA Buttons', buttonText, 'Clicked');
    });

    //Track Start Free Trial CTA Button Clicks
    $('a.sign-up-cta-link').click(function() {
        ga('send', 'event',  'Start Free Trial CTA', 'Clicked', pathName);
    });

    //Track Logged In Homepage News Article Button Clicks
    $('.news-events-wrapper a').click(function() {
        var titleText = $(this).text();
        ga('send', 'event',  'Homepage News Articles', userID, titleText);
    });

    //Track Logged In Homepage Latest Video Button Clicks
    $('.home-page-video a').click(function() {
        var titleText = $(this).text();
        ga('send', 'event',  'Homepage Latest Videos', userID, titleText);
    });

    //Track Forward Content by Email Button Clicks
    $('a.forward-page').click(function() {
        var titleText = $(this).text();
        ga('send', 'event',  'Forward Content by Email', titleText, pathName);
    });

});