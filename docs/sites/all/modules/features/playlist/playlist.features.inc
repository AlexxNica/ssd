<?php
/**
 * @file
 * playlist.features.inc
 */

/**
 * Implements hook_node_info().
 */
function playlist_node_info() {
  $items = array(
    'playlist' => array(
      'name' => t('Playlist'),
      'base' => 'node_content',
      'description' => t('A collection of a training modules.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
