<?php

/**
 * @file
 * Rules integration for feedback.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Implements hook_rules_event_info().
 */
function ssd_library_rules_event_info() {
  $defaults = array(
    'group' => t('Feedback'),
    'module' => 'ssd_library',
    'access callback' => 'feedback_rules_integration_access',
  );
  return array(
    'ssd_library_feedback_insert_filtered' => $defaults + array(
      'label' => t('After saving new feedback (filtered)'),
      'variables' => array(
        'feedback' => array('type' => 'feedback', 'label' => t('Feedback message')),
      ),
    ),
  );
}
