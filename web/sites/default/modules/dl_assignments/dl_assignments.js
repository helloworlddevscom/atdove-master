/**
 * @file dl_assignments.js
 * This js script provides support for atDove's assignment features
*/


(function ($) {
  Drupal.behaviors.dl_assignments = {
    attach: function (context, settings) {
    
      //Start chosen
      if($('#edit-people').length){
          $('#edit-people').chosen();
      }
      if($('#dl-assignments-assign-to-group-form #edit-groups').length){
        $('#dl-assignments-assign-to-group-form #edit-groups').chosen();
      }  
      ////** Add a close To Modal Pop-Up **////
      if($('a.close-person-modal-window').length){
        $('a.close-person-modal-window').click(function(e) {
          e.preventDefault();
          $('.assign-to-person-modal').removeClass('showModalWindow');
        });      
      }
        //populate the assignment modal with the correct data
        $("a.person").click(function(e) {
        
            //Expose the Modal
            e.preventDefault();
            $('.assign-to-person-modal').addClass('showModalWindow');
          //only try to get the data if they are a subscriber. Typically we don't do these checks based on client size role eval but even if they did spoof the css they form would be valueless.  So I will allow it. 
          if($('#dl-assignments-assign-to-person-form').length){     
            var contentID = $(this).attr("data-id");

            //get this user specific people data
            $.getJSON( "/assignments/mymembers/autocomplete/"+contentID).done(function( userList ) {
              //populate the select field with options
              //Convert the object to an array (to sort) then html options
              var options = '<option></option>';
              var userArray = [];
              for (var user in userList)
                userArray.push([user, userList[user]])
              userArray.sort(function(a, b) {
                // Trying to mimic the user sort order used when assigning training plans 
                if (a[1]['name'].toLowerCase().replace(/[^\w\s]/gi, '') < b[1]['name'].toLowerCase().replace(/[^\w\s]/gi, '')) return -1;
                if (a[1]['name'].toLowerCase().replace(/[^\w\s]/gi, '') > b[1]['name'].toLowerCase().replace(/[^\w\s]/gi, '')) return 1;
                return 0;
              });
              $.each(userArray, function(index, value) {
                options += '<option value="' + value[0];
                if(value[1]['status']==1){
                  options += '">' + value[1]['name'] + '</option>';
                }
                else{
                  options += '" disabled=\'disabled\' >' + value[1]['name'] + ' - ' + value[1]['msg'] + '</option>';
                }
              }); 
              //add the options to the select field
              $("#edit-people").html(options);

              //updating chosen cause css issues so we destroy and rebuild
              if(typeof $("#edit-people").data("chosen") != 'undefined') {
                $("#edit-people").data("chosen").destroy().chosen({
                  width: "100%",
                });
              }
              //add the assignment too
              $("#contentid").val(contentID);
            });
            //get this user specific group data
            $.getJSON( "/orggroup/autocomplete").done(function( groupList ) {
              //populate the select field with options
              //Convert the object to html options
              var options = '<option></option>';
              $.each(groupList, function(index, value) {
                options += '<option value="' + index + '">' + value + '</option>';
              }); 
              //add the options to the select field
              $("#edit-groups").html(options);

              //updating chosen cause css issues so we destroy and rebuild
              if(typeof $("#edit-groups").data("chosen") != 'undefined') {
                $("#edit-groups").data("chosen").destroy().chosen({
                  width: "100%",
                });
              }

              //add the assignment too
              $("#groupcontentid").val(contentID);
            });
          }//end if they have the proper role
        });
            
      
    }
  };
}(jQuery));

