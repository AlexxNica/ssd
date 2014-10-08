Drupal.behaviors.ssd_modules = {
  attach: function (context, settings) {    
    (function ($) {
      
      // Used this example: http://stackoverflow.com/questions/7968303/wrapping-a-series-of-elements-between-two-h2-tags-with-jquery
      $("div.node-article div.wrap-module-sections h2").each(function(){
        var $set = $(this).nextUntil("h2").addBack();
        $set.wrapAll('<section class="module-section"><div class="container"> </div></section>');
      });
      $("div.node-article div.wrap-module-sections div.field-name-body div.field-item p:first").nextUntil("section.module-section").addBack().wrapAll('<section class="module-section"><div class="container"> </div></section>');

    })(jQuery);
  }
}
