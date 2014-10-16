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
  $items['ssd_import_csv_headers'] = array(
    'callback' => '_ssd_import_csv_headers',
    'description' => 'View a CSV\'s headers.',
    'arguments' => array(
      'csv_path' => 'The CSV data file',
    ),
    'aliases' => array('ssdch'),
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

    // Set non-dynamic vars.
    $term = new stdClass();
    $term->vid = 2;
    $term->vocabulary_machine_name = 'terms';
    
    // English
    $term->name = $row[0];
    $term->description = $row[3];
    
    $term->name_field['en'][0]['value'] = $row[9];
    $term->field_synonym['en'][0]['value'] = $row[1];
    $term->description_field['en'][0]['value'] = $row[3];
    /*
    $term->name_field['es'][0]['value'] = $row[9];
    $term->field_synonym['es'][0]['value'] = $row[11];
    $term->description_field['es'][0]['value'] = $row[10];
    
    $term->name_field['ar'][0]['value'] = $row[8];
    $term->field_synonym['ar'][0]['value'] = $row[7];
    $term->description_field['ar'][0]['value'] = $row[6];
    */
    $es_trans = array(
      'translate' => 0,
      'status' => 1,
      'language' => 'es',
      'source' => 'en',
    );
    $es_vals = array(
      'name_field' => array (
        'es' => array(
          '0' => array(
            'value' => $row[9],
           ),
         ),
       ),
      'description_field' => array (
        'es' => array(
          '0' => array(
            'value' => $row[10],
           ),
         ),
       ),
      'field_synonym' => array (
        'es' => array(
          '0' => array(
            'value' => $row[11],
           ),
         ),
       ),
    );
    
    $ar_trans = array(
      'translate' => 0,
      'status' => 1,
      'language' => 'ar',
      'source' => 'en',
    );
    $ar_vals = array(
      'name_field' => array (
        'ar' => array(
          '0' => array(
            'value' => $row[8],
           ),
         ),
       ),
      'description_field' => array (
        'ar' => array(
          '0' => array(
            'value' => $row[6],
           ),
         ),
       ),
      'field_synonym' => array (
        'ar' => array(
          '0' => array(
            'value' => $row[7],
           ),
         ),
       ),
    );
        
    // Set Translations
    $handler = entity_translation_get_handler('taxonomy_term', $term);
    $handler->setTranslation($es_trans, $es_vals);
    $handler->setTranslation($ar_trans, $ar_vals);
    // Save
    taxonomy_term_save($term);

    // Update Aliases
    pathauto_taxonomy_term_update_alias($term, 'update', $values = array ('language' => 'es'));
    pathauto_taxonomy_term_update_alias($term, 'update', $values = array ('language' => 'ar'));
    
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

function _ssd_import_csv_headers($arg_path = '') {
  $csv_path = _resolve_path($arg_path);
  if (is_null($csv_path)) {
    drush_print("Please provide the path to a valid CSV for import/translation.");  
    return;
  }
  $csv = _ssd_get_csv($csv_path);
  drush_print_r($csv[0]);
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
