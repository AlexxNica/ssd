Drupal.behaviors.ssd_mobile = {
  attach: function (context, settings) {
    (function ($) {
    
      function mediaqueryresponse(mql){
        if (mql.matches) {
          $('.playlist-toc-link').click( function() {
            $("#playlist-controller .playlist-table", context).hide(100);
            $('#playlist-controller', context).removeClass('expanded', 100);
          });
        }
        else {

        }
      }
      /**
       * IMPORTANT:
       * If this is changed, the breakpoint in mobile.scss
       * must be changed to match.
       */
      var mql = window.matchMedia("(max-width:767px)");
      mediaqueryresponse(mql);
      mql.addListener(mediaqueryresponse)
    })(jQuery);
  }
}
