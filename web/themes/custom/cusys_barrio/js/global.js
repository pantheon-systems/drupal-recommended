/**
 * @file
 * Global utilities.
 *
 */
(function ($, Drupal, once) {

  'use strict';

  Drupal.behaviors.cusys_barrio = {
    attach: function (context, settings) {

      once('linkFormatter', 'body', context).forEach( function () {
        $('#main-wrapper a[href]:not([href=""],[href^="/"],[href^="mailto:"],[href^="tel:"],[href^="#"],[href*="cu.edu"],[href*="colorado.edu"],[href*="uccs.edu"],[href*="ucdenver.edu"],[href*="cuanshutz.edu"],[href*="ddev.site"])').attr("target", "_blank");
      });
    }
  };

})(jQuery, Drupal, once);
