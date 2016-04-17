<?php
session_start();
include_once('config/header.php');

if (isset($_SESSION['user_id']))
	redirect("index.php");

if (isset($_POST['submit']) && $_POST['submit'] == 'Login') {
	if (isset($_POST['login']) && trim($_POST['login']) != "" && isset($_POST['pass']) && trim($_POST['pass']) != "") {
		$log = $BDD->quote(trim($_POST['login']));
		$pass = hash("sha256", trim($_POST['pass']));
		$res = check_password($log, $pass, $BDD);
		if ($res !== FALSE) {
			$_SESSION['user_id'] = $res['id'];
			redirect("index.php");
		} else {
			echo "Wrong LOGIN or PASSWORD!<br />";
		}
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
		<h1>Login</h1>
		<form action="login.php" method="post">
			<input type="text" name="login" placeholder="Username" maxlength='40' autofocus />
			<input type="password" name="pass" placeholder="Password" />
			<input type="submit" name="submit" value="Login" />
		</form>
		<p><a href="register.php">Don't have an account yet ?</a></p>
		<p><a href="reset_pw.php">Forgot your password ?</a></p>
	</body>
</html>
