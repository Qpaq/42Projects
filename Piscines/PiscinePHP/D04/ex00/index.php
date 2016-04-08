<?php

if (isset($_GET['submit']) && $_GET['submit'] == 'OK')
{
	session_start();
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<style>
			form {
				text-align: center;
			}
		</style>
	</head>
	<body>
		<form action="index.php" method="get">
			<input type="text" name="login" value="<?php echo $_SESSION['login']; ?>" /><br />
			<input type="password" name="passwd" value="<?php echo $_SESSION['passwd']; ?>" /><br />
			<input type="submit" name="submit" value="OK">
		</form>
	</body>
</html>
