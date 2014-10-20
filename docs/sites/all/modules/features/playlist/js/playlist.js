Drupal.behaviors.playlist = {
  attach: function (context, settings) {
    // Get permlink info from Drupal.settings.
    var hashLinks = Drupal.settings.playlist.hashLinks;
    var indexes = Drupal.settings.playlist.indexes;
    
    // Figure out which slide to load based on hash.
    function playlistGetIndex() {
      var hash = document.URL.split('#')[1];
      var index = decodeURIComponent(indexes[hash]);
      if (index == null) {
        index = 0;
      }
      return index;
    }
    
    (function ($) {
      // Scroll To Top
      function scrollToTop() {
        $("html, body").animate({ scrollTop: $('#navbar').offset().top }, 200);
        return false;
      }
      
      // Load flexslider with default settings.
      $('.flexslider').flexslider({
        smoothHeight: true,
        animation: "fade",
        controlNav: false,
        directionNav: false,
        slideshow: false,
        animationSpeed: 0,
        startAt: playlistGetIndex(),
        after:function(slider){
          // Change the hash to a slide's permlink on after sliding.
          window.location.hash = hashLinks[slider.currentSlide];
          // Hide inactive slides to diminish page whitespace on slide change.
          $('.slides').children('li').css('display', 'none');
          $('.slides .flex-active-slide').css('display', 'block');
        }
      });
      
      // This uses the hashchange plugin to support changing slides when using
      // the back button. Without it, navigation is unsatisfactory.
      $(window).hashchange( function(){
        scrollToTop();
        $('.flexslider').flexslider(playlistGetIndex());
      });
      
      $('#playlist-next').on('click', function(){
        $('.flexslider').flexslider('next')
          return false;
      });
      
      // Hide inactive slides to diminish page whitespace on page load.
      $('.slides').children('li').css('display', 'none');
      $('.slides .flex-active-slide').css('display', 'block');

      // Hide "more" by default.
      $("#playlist-controller #playlist-table").hide();
      // Toggle on click
      $("#playlist-controller #playlist-more").click(function() {
        $("#playlist-controller #playlist-table").toggle();
      });
      
      // Hide Controller Table on click outside of controller
      $(document).mouseup(function (e) {
        var container = $("#playlist-controller");
        if (!container.is(e.target) && container.has(e.target).length === 0) {
          $("#playlist-controller #playlist-table").hide();
        }
      });
      // Hide Controller on esc keypress
      $(document).keyup(function(e) {
        if (e.keyCode == 27) {
          $("#playlist-controller #playlist-table").hide();
        }
      });
    })(jQuery);
  }
};
