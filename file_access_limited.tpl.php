<?php
 global $user;
 $file_count = is_array($user->data)&&isset($user->data['file_count'])?$user->data['file_count']:0;
 $formatted_file_count = format_plural($file_count, '1 file', '@count files');
?>

<h2>Unable to access the requested file at this time</h2>
The system limits the number of files that can be downloaded per month.<br>
You have downloaded <strong><?php echo $formatted_file_count ?></strong> this month. Please try again at a later date.<br>