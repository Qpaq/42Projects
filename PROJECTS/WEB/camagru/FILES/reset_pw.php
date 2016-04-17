<?php
include_once("config/header.php");

function random_pass() {
	$i = 0;
	$res = "";

	while ($i < 7) {
		if ($i % 2 == 0)
			$char = chr(rand(97, 122));
		else
			$char = rand(0, 9);
		$res = $res.$char;
		$i++;
	}
	return $res;
}

if (isset($_POST['submit']) && $_POST['submit'] == 'Reset') {
	if (isset($_POST['user']) && trim($_POST['user']) != "") {
		$user = $BDD->quote($_POST['user']);
		$q = "SELECT * FROM user WHERE email = {$user} OR login = {$user}";
		$res = query_db($q, $BDD);
		if (empty($res)) {
			echo "This user does not exist";
		} else {
			$new_pass = random_pass();
			$hashed = hash("sha256", $new_pass);
			$message = "Hello {$res[0]['login']},\nYour new password is {$new_pass}\n";
			mail($res[0]['email'], "New Password", $message);
			echo "A new password was sent to your email";
			$q = "UPDATE user SET password='{$hashed}' WHERE id={$res[0]['id']}";
			exec_db($q, $BDD);
			redirect('login.php');
		}
	}
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
	</head>
	<body>
		<form action="reset_pw.php" method="post">
			<input type="text" name="user" placeholder="Email or Username" autofocus /><br />
			<input type="submit" name="submit" value="Reset" />
		</form>
	</body>
</html>
