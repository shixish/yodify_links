<?php
/**
 * Implements hook_default_rules_configuration().
 */
function yodify_links_default_rules_configuration() {
  $rules = array();
  
  $rule = rules_reaction_rule();
  $rule->label = 'Yodify download links';
  $rule->active = TRUE;
  $rule ->event('yodify_count_file_download')
        ->condition(
          'userpoints_condition_check_points', array(
            'user:select' => "site:current-user",
            "tid" => "0",
            "threshold" => "10",
            "comparison" => "lt"
          )
        )
        ->action('userpoints_action_grant_points', array(
             "user:select" => "site:current-user",
             "points" => "1",
             "tid" => "0",
             "operation" => "Download",
             "display" => 0,
             "moderate" => "approved",
             "expirydate" => "first day of next month"
           )
         )
        ->action('yodify_count_file_download_redirect');

  $rules['rules_yodify_download_links_example'] = $rule;
  return $rules;
}