jQuery(document).ready(function($) {
  var permLink = document.URL.split('#')[1];
  // @todo Should make sure permLink is in bounds, otherwise set to zero.
  
  $('.flexslider').flexslider({
    animation: "fade",
    controlNav: false,
    directionNav: false,
    slideshow: false,
    animationSpeed: 0,
    startAt: permLink,
    after:function(slider){
      // Change the hash to a slide's permlink on after sliding.
      window.location.hash = slider.currentSlide;
    },
  });
  
  $('.flexslider-prev').on('click', function(){
    $('.flexslider').flexslider('prev');
    return false;
  })

  $('.flexslider-next').on('click', function(){
    $('.flexslider').flexslider('next')
    return false;
  });
});
