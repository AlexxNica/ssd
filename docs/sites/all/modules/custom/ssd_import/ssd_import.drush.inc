<?php

function ssd_import_drush_command() {
  $items = array();
  $items['ssd_import_glossary'] = array(
    'callback' => '_ssd_import_glossary',
    'description' => 'Imports glossary terms.',
    'arguments' => array(
      'csv_path' => 'The CSV data file',
    ),
    'aliases' => array('ssdig'),
  );
  $items['ssd_delete_glossary'] = array(
    'callback' => '_ssd_delete_glossary',
    'description' => 'Deletes the glossary.',
    'aliases' => array('ssddg'),
  );
  $items['ssd_view_glossary'] = array(
    'callback' => '_ssd_view_glossary',
    'description' => 'View the glossary as a set of PHP arrays.',
    'aliases' => array('ssdvg'),
  );
  return $items;
}

function _ssd_import_glossary($arg_path = '') {
  $csv_path = _resolve_path($arg_path);
  if (is_null($csv_path)) {
    drush_print("Please provide the path to a valid CSV for import/translation.");  
    return;
  }
  // Get CSV as array and remove header record.
  $csv = _ssd_get_csv($csv_path);
  array_shift($csv);
  
  // Counters
  $term_count = 0;

  // Loop through terms and save.
  foreach ($csv as $row) {    
  
    // Ignore blank or malformed CSV rows.
    if (count($row) != 12) {
      drush_print('Skipped "' . $row[0] . '" - blank or malformed.');
      break;
    }
    // Set non-dynamic vars.
    $term = new stdClass();
    $term->vid = 2;
    $term->vocabulary_machine_name = 'terms';
    
    // English
    $term->name = $row[0];
    $term->description = $row[3];
    $term->name_field['en'][0]['value'] = $row[0];
    $term->field_synonym['en'][0]['value'] = $row[1];
    $term->description_field['en'][0]['value'] = $row[3];
    
    // Arabic
    $term->name_field['ar'][0]['value'] = $row[8];
    $term->description_field['ar'][0]['value'] = $row[6];
    $term->field_synonym['ar'][0]['value'] = $row[7];
    
    // Spanish
    $term->name_field['es'][0]['value'] = $row[11];
    $term->description_field['es'][0]['value'] = $row[9];
    $term->field_synonym['es'][0]['value'] = $row[10];
    
    taxonomy_term_save($term);
    drush_print('Saved ' . $row[0] . ' as tid: ' . $term->tid . ' Row count: ' . count($row));
    $term_count++;
  }
  drush_print('Imported a total of ' . $term_count . ' glossary terms.');
}

function _ssd_delete_glossary() {
  $term_count = 0;
  $rs = db_query('SELECT tid FROM taxonomy_term_data WHERE vid = 2');
  foreach ($rs as $row) {
    taxonomy_term_delete($row->tid);
    drush_print('Deleted term #' . $row->tid);
    $term_count++;
  }
  drush_print('Deleted a total of ' . $term_count . ' glossary terms.');
}

function _ssd_view_glossary() {
  $rs = db_query('SELECT tid FROM taxonomy_term_data WHERE vid = 2');
  foreach ($rs as $row) {
    $term = taxonomy_term_load($row->tid);
    drush_print_r($term);
  }
}

function _ssd_get_csv($filepath) {
  setlocale(LC_ALL, 'en_US.UTF-8');
  $fh = fopen($filepath, 'r');
  while (!feof($fh) ) {
    $text[] = fgetcsv($fh, 0);
  }
  fclose($fh);
  return $text;
}

/**
 * Figure out if a file path is absolute or relative, return working path or NULL for failure.
 */
function _resolve_path($path) {
  if (trim($path) == '') {
    return NULL;
  }
  elseif (file_exists($path)) {
    return $path;
  }
  elseif(file_exists(realpath(drush_cwd() . '/' . $path))) {
    return realpath(drush_cwd() . '/' . $path);
  }
  else {
    return NULL;
  }
}
