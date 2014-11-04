Drupal.behaviors.ssd_modules = {
  attach: function (context, settings) {
    (function ($) {
      // Used this example: http://stackoverflow.com/questions/7968303/wrapping-a-series-of-elements-between-two-h2-tags-with-jquery
      $("div.node-article div.wrap-module-sections h2").each(function(){
        var $set = $(this).nextUntil("h2").addBack();
        $set.wrapAll('<section class="module-section"><div class="container"> </div></section>');
      });
      $("div.node-article div.wrap-module-sections div.field-name-body").each(function(){
        $(this).find("div.field-item p:first").nextUntil("section.module-section").addBack().wrapAll('<section class="module-section"><div class="container"> </div></section>');
      });
      // Set popover titles to data-title.  This allows for graceful js degradation.
      $(".glossify-link").attr("title", function() {
        return $(this).attr('data-title');
      });
      // Apply popover
      $(".glossify-link").popover();
      // Show the feedback form.
      $(".feedback-link").mouseup(function (e) {
        if (e.which != 1) return false;
        $("#feedback-form", context).slideToggle();
      });
      // Hide Controller Table on click outside of controller
      $(document, context).mouseup(function (e) {
        if (e.which != 1) return false;
        // Make sure a click wasn't within one of these containers.
        var playlistController = $("#playlist-controller", context);
        var feedBackController = $("#feedback-controller", context);
        var feedbackForm = $("#block-feedback-form", context);
        if (!playlistController.is(e.target) && playlistController.has(e.target).length === 0) {
          if (!feedBackController.is(e.target) && feedBackController.has(e.target).length === 0) {
            if (!feedbackForm.is(e.target) && feedbackForm.has(e.target).length === 0) {
              $("#feedback-form", context).slideUp();
              $("#playlist-controller .playlist-table", context).hide(100);
              $('#playlist-controller', context).removeClass('expanded', 100);
            }
          }
        }
      });
      // Hide Controller on esc keypress
      $(document).keyup(function(e) {
        if (e.keyCode == 27) {
          $("#feedback-form", context).slideUp();
          $("#playlist-controller .playlist-table", context).hide(100);
          $('#playlist-controller', context).removeClass('expanded', 100);
        }
      });
    })(jQuery);
  }
}
