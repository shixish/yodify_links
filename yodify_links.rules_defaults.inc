<?php
/**
 * Implements hook_default_rules_configuration().
 */
function yodify_links_default_rules_configuration() {
  $rules = array();
  
  $rule = rules_reaction_rule();
  $rule->label = 'Yodify download links';
  $rule->active = TRUE;
  $rule->event('yodify_count_file_download')
       ->condition('yodify_count_file_download_check', array('limit' => 5))
       ->action('yodify_count_file_download_redirect');

  $rules['rules_yodify_download_links_example'] = $rule;
  return $rules;
}