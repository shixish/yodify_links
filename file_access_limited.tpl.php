<?php
 global $user;
 $tid = variable_get('yodify_links_category_tid', 0);
 $points = format_plural(userpoints_get_current_points($user->uid, $tid), '1 file', '@count files');
?>

<h2>Unable to access the requested file at this time</h2>
The system limits the number of files that can be downloaded per month.<br>
You have downloaded <strong><?php echo $points ?></strong> this month. Please try again at a later date.<br>