jQuery(document).ready(function($) {
    
////** Content in this file is for user role behaviors **////
    
    //** Content variables **//
    var noAccessQuizButton = $('.nonMember a.quiz');
    var quizButtonText = '<h2>Quizzes are a premium feature</h2>';
    
    ////Create the modal window
    function noAccessModalMessage(bodyMessage) {
        $('body').append('<div class="no-access-modal"><span class="close-no-access-modal">x</span>' + bodyMessage + '<p>Please visit our <a href="/future-billing">subscriptions page</a> to gain access to atdove.org premium content</p></div>');
    }
    noAccessModalMessage(quizButtonText);
    
    ////Check if user is non-member
    if ($('body').hasClass('nonMember')) {
                        
        ////show no access modal when clicking quiz button
        noAccessQuizButton.click(function (e) {
            e.preventDefault();
            //call no access modal window function and populate the body message
            noAccessModalMessage(quizButtonText);
            $('.no-access-modal').addClass('show-no-access-modal');
            ////Close no access modal window
            $('.close-no-access-modal').click(function () {
                $('.no-access-modal').removeClass('show-no-access-modal');
            });
        });
        
        
                
    }
        
    

});