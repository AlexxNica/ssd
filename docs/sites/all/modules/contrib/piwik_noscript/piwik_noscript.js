(function ($) {

Drupal.behaviors.piwikNoscript = {
  attach: function (context, settings) {
    $('#piwik-noscript', context).once('piwik-noscript', function() {
      var image = $(settings.piwikNoscript.image);
      image.attr('src', image.attr('src') + '&urlref=' + encodeURIComponent(document.referrer) + '&action_name=' + encodeURIComponent(document.title));
      $(this).html(image);
    });
  }
};

}(jQuery));
