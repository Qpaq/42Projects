<?php

function check_email($str) {
	$pattern = "/^[A-Z0-9._-]+@[A-Z0-9-]+\.[A-Z0-9]{2,4}(\.[A-Z0-9]{2,4})?$/i";
	if (preg_match($pattern, $str))
		return TRUE;
	return FALSE;
}

echo check_email("ama@student.42.fr");
echo check_email("ama@student.42.fr.test");

?>
