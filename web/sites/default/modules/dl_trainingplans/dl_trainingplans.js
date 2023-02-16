/**
 * @file dl_trainingplans.js
 * This js script provides support for atDove's training plan features
*/


(function ($) {
  Drupal.behaviors.dl_trainingplans = {
    attach: function (context, settings) {

      //Start chosen
      if($('#edit-plans').length){
          $('#edit-plans').chosen();
      }
      if($('#edit-tppeople').length){
          $('#edit-tppeople').chosen();
      }
      if($('#edit-tpgroups').length){
          $('#edit-tpgroups').chosen();
      }

      if($('#dl-trainingplans-assign-to-group-form #edit-groups').length){
        $('#dl-trainingplans-assign-to-group-form #edit-groups').chosen();
      }

      ////** Add a close To Modal Pop-Up **////
      if($('a.close-training-modal-window').length){
        $('a.close-training-modal-window').click(function(e) {
            e.preventDefault();
            $('.assign-to-training-plan-modal').removeClass('showModalWindow');
        });
      }
      ////** Add a close To Modal Pop-Up **////
      if($('a.close-tpperson-modal-window').length){
        $('a.close-tpperson-modal-window').click(function(e) {
            e.preventDefault();
            $('.assign-tp-modal').removeClass('showModalWindow');
        });
      }
      ////** Add a close To Modal Pop-Up **////
      if($('a.close-training-create-modal-window').length){
          $('a.close-training-create-modal-window').click(function(e) {
              e.preventDefault();
              $('.create-training-plan-modal').removeClass('showModalWindow');
          });
      }



      //populate the add content to a training plan modal with the correct data
      if($('a.training').length){
        $("a.training").click(function(e) {
          //Expose the Modal
          e.preventDefault();
          $('.assign-to-training-plan-modal').addClass('showModalWindow');
          if($('#dl-trainingplans-add-and-create-tp-form').length){
            var contentID = $(this).attr("data-id");
            //get this content specific training plan  data
            //There may not be an edit plans if there are zero plans created.
            if($('#edit-plans').length){
              $.getJSON( "/trainingplans/myplans/autocomplete/"+contentID).done(function( planList ) {
                //populate the select field with options
                //Convert the object to html options
                var options = '<option></option>';
                $.each(planList, function(index, value) {
                  options += '<option value="' + index;
                  if(value['status']==1){
                    options += '">' + value['name'] + '</option>';
                  }
                  else{
                    options += '" disabled=\'disabled\' >' + value['name'] + ' - ' + value['msg'] + '</option>';
                  }
                });
                //add the options to the select field
                $("#edit-plans").html(options);
                //updating chosen cause css issues so we destroy and rebuild
                if ($("#edit-plans").data("chosen") !== undefined) {
                  $("#edit-plans").data("chosen").destroy().chosen({
                    width: "100%",
                  });
                }
                //add the content id
                $("#tpcontentid").val(contentID);
              });
            }
          }
          //add the content id to the new content field too
          $("#tpnewcontentid").val(contentID);
        });
      }

        //populate the add content to a training plan modal with the correct data
        if($('a.createtraining').length){
            $("a.createtraining").click(function(e) {
                //Expose the Modal
                e.preventDefault();
                $('.create-training-plan-modal').addClass('showModalWindow');
            });
        }

        //populate the assigna training plan modal with the correct data
        $("a.assigntraining").click(function(e) {
            //Expose the Modal
            e.preventDefault();
            $('.assign-tp-modal').addClass('showModalWindow');
          //only try to get the data if they are a subscriber. Typically we don't do these checks based on client size role eval but even if they did spoof the css they form would be valueless.  So I will allow it.
          if($('#dl-trainingplans-assign-to-person-form').length){
            var contentID = $(this).attr("data-id");
            //get this user specific people data
            $.getJSON("/memberfn/autocomplete").done(function( userList ) {
              //populate the select field with options
              //Convert the object to html options
              var options = '<option></option>';
              $.each(userList, function(index, value) {
                options += '<option value="' + index + '">' + value + '</option>';
              });
              //add the options to the select field
              $("#edit-tppeople").html(options);
              //updating chosen cause css issues so we destroy and rebuild
              var test = $("#edit-tppeople").data("chosen");
              if ($("#edit-tppeople").data("chosen") !== undefined) {
                $("#edit-tppeople").data("chosen").destroy().chosen({
                  width: "100%",
                });
              }
              //add the assignment too
              $("#tpcontentid").val(contentID);
            });
            //get this user specific group data
            $.getJSON("/orggroup/autocomplete").done(function( groupList ) {

              //populate the select field with options
              //Convert the object to html options
              var options = '<option></option>';
              $.each(groupList, function(index, value) {
                options += '<option value="' + index + '">' + value + '</option>';
              });
              //add the options to the select field
              $("#edit-tpgroups").html(options);
              //updating chosen cause css issues so we destroy and rebuild
              if ($("#edit-tpgroups").data("chosen") !== undefined) {
                $("#edit-tpgroups").data("chosen").destroy().chosen({
                  width: "100%",
                });
              }
            });
            //add the assignment too
            $("#tpgroupcontentid").val(contentID);
          }//end if they have the proper role
        });

    }
  };
}(jQuery));

