Drupal.behaviors.playlist = {
  attach: function (context, settings) {
    // Get permlink info from Drupal.settings.
    var hashLinks = Drupal.settings.playlist.hashLinks;
    var indexes = Drupal.settings.playlist.indexes;
    
    // Figure out which slide to load based on hash.
    function playlistGetIndex() {
      var hash = document.URL.split('#')[1];
      var index = indexes[hash];
      if (index == null) {
        index = 0;
    
      }
      return index;
    }
    
    (function ($) {
      // Load flexslider with default settings.
      $('.flexslider').flexslider({
        animation: "fade",
        controlNav: false,
        directionNav: false,
        slideshow: false,
        animationSpeed: 0,
        startAt: playlistGetIndex(),
        after:function(slider){
          // Change the hash to a slide's permlink on after sliding.
          window.location.hash = hashLinks[slider.currentSlide];
        },
      });
      
      // This uses the hashchange plugin to support changing slides when using
      // the back button. Without it, navigation is unsatisfactory.
      $(window).hashchange( function(){
        $('.flexslider').flexslider(playlistGetIndex());
      });

    })(jQuery);
  }
};
