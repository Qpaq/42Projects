<?php
session_start();
include_once('config/header.php');

if (isset($_SESSION['user_id']))
	redirect('index.php');

function check_email($str) {
	$pattern = "/^[A-Z0-9._-]+@[A-Z0-9-]+\.[A-Z0-9]{2,4}(\.[A-Z0-9]{2,4})?$/i";
	if (preg_match($pattern, $str))
		return TRUE;
	return FALSE;
}

function check_login_or_pw($str) {
	$pattern = "/^[A-Z0-9]{1,40}$/i";
	if (preg_match($pattern, $str))
		return TRUE;
	return FALSE;
}


if (isset($_POST['submit']) && $_POST['submit'] == 'Register') {
	if (isset($_POST['login']) && trim($_POST['login']) != "" && isset($_POST['pass']) && trim($_POST['pass']) != "" && isset($_POST['email']) && trim($_POST['email']) != "") {
		if (!check_email(trim($_POST['email'])) || !check_login_or_pw(trim($_POST['login'])) || !check_login_or_pw(trim($_POST['pass']))) {
			echo "Wrong input";
		} else {
			$log = $BDD->quote(trim($_POST['login']));
			$email = $BDD->quote(trim($_POST['email']));
			$pass = hash("sha256", trim($_POST['pass']));
			if (user_already_exists($log, $BDD))
				echo "Username already taken";
			else {
				$query = "INSERT INTO user (email, login, password) VALUES({$email}, {$log}, '{$pass}')";
				exec_db($query, $BDD);
				$_SESSION['user_id'] = $BDD->lastInsertId();
				$email =  "Hello {$_POST['login']},\nWe are extremely happy to welcome you on Camagru !\n";
				mail(trim($_POST['email']), "Welcome to Camagru !", $email);
				redirect("index.php");
			}
		}
	} else {
		echo "Error<br />";
	}
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>
		<h1>Register</h1>
		<form action="register.php" method="post">
			<input type="email" name="email" placeholder="Email" maxlength='100' autofocus />
			<input type="text" name="login" placeholder="Username" maxlength='40' />
			<input type="password" name="pass" placeholder="Password" />
			<input type="submit" name="submit" value="Register" />
		</form>
		<p><a href="login.php">Already have an account ?</a></p>
	</body>
</html>
