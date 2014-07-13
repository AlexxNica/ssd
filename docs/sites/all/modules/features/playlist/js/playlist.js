window.onunload=function(){};
// @bug @todo https://stackoverflow.com/questions/7248111/how-to-prevent-content-being-displayed-from-back-forward-cache-in-firefox
Drupal.behaviors.playlist = {
  attach: function (context, settings) {
    
    // Get permlink info from Drupal.settings.
    var hashLinks = Drupal.settings.playlist.hashLinks;
    var indexes = Drupal.settings.playlist.indexes;
    (function ($) {

      // Figure out which slide to load based on hash.
      var hash = document.URL.split('#')[1];
      var index = indexes[hash];
      if (index == null) {
        index = 0;
      }

      // Load flexslider with default settings.
      $('.flexslider').flexslider({
        animation: "fade",
        controlNav: false,
        directionNav: false,
        slideshow: false,
        animationSpeed: 0,
        startAt: index,
        after:function(slider){
          // Change the hash to a slide's permlink on after sliding.
          window.location.hash = hashLinks[slider.currentSlide];
        },
      });
      
      // Flexslider custom controls.
      $('.flexslider-prev').on('click', function(){
        $('.flexslider').flexslider('prev');
        return false;
      })
      $('.flexslider-next').on('click', function(){
        $('.flexslider').flexslider('next')
          return false;
      });

      // This uses the hashchange plugin to support changing slides when using
      // the back button. Without it, navigation is unsatisfactory.
      $(window).hashchange( function(){
        hash = document.URL.split('#')[1];
        index = indexes[hash];
        if (index == null) {
          index = 0;
        }
        $('.flexslider').flexslider(index);
      });

    })(jQuery);
  }
};
