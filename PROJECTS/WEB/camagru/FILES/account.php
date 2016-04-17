<?php
session_start();
if (!isset($_SESSION['user_id']))
	die();

if (isset($_POST['submit']) && $_POST['submit'] == 'Confirm') {
	if (isset($_POST['oldpw']) && $_POST[''] != '' && check_password($_SESSION[''], $_POST['oldpw'], $BDD))
}
?>

<form action='index.php?page=account' method='post'>
<input type='text' name='newemail' placeholder='Change email?' />
<input type='text' name='newpw' placeholder='Change password?' />
<p><input type='text' name='oldpw' placeholder='Old password to confirm' /></p>
<input type='submit' name='submit' value='Confirm' />
</form>
