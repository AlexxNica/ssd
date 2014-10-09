<?php
/**
 * @file
 * ssd_library.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function ssd_library_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ssd_library_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
