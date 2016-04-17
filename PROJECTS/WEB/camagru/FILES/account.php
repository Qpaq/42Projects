<?php
if (isset($_POST['submit']) && $_POST['submit'] == 'Confirm') {

	$id = $BDD->quote(trim($_SESSION['user_id']));
	$log = get_login_from_id($id, $BDD);

	if (isset($_POST['oldpw']) && $_POST['oldpw'] != '') {
		$oldpw = hash("sha256", trim($_POST['oldpw']));

		if (isset($_POST['newpw']) && trim($_POST['newpw']) != '') {
			$newpw = hash("sha256", trim($_POST['newpw']));
		}
		if (isset($_POST['newemail']) && trim($_POST['newemail']) != '') {
			$email = $BDD->quote(trim($_POST['newemail']));
		}

		if ((isset($newpw) || isset($email)) && check_password($BDD->quote($log), $oldpw, $BDD) !== FALSE) {
			$q = "";
			if (isset($newpw)) $q .= "password='{$newpw}'";
			if (isset($email)) $q .= "email={$email}";
			$BDD->exec("UPDATE user SET {$q} WHERE id='{$_SESSION['user_id']}'");
			echo "CHANGED !";
		} else {
			echo "Wrong password or Empty fields";
		}
	} else echo "Don't forget your password !";
}
?>

<form action='index.php?page=account' method='post'>

<input type='text' name='newemail' placeholder='Change email?' /><br />
<input type='text' name='newpw' placeholder='Change password?' />
<p><input type='text' name='oldpw' placeholder='Old password to confirm' /></p>
<input type='submit' name='submit' value='Confirm' />

</form>
