<?php
session_start();
if (!isset($_SESSION['user_id'])) redirect('index.php?page=gallery&error');
include_once('config/header.php');

if (isset($_GET['action']) && isset($_GET['id']) && $_GET['action'] != "" && $_GET['id'] != "") {
	$photoId = $BDD->quote($_GET['id']);

	if ($_GET['action'] == 'like') {

		$res = query_db("SELECT * FROM likes WHERE id_user = '{$_SESSION['user_id']}' AND id_photo = {$photoId}", $BDD);
		if (empty($res))
			$BDD->exec("INSERT INTO likes (id_user, id_photo, date_and_time) VALUES('{$_SESSION['user_id']}', {$photoId}, NOW())");
		redirect('index.php?page=gallery');

	}
	else if ($_GET['action'] == 'comment' && isset($_GET['message']) && $_GET['message'] != "") {

		$message = $BDD->quote($_GET['message']);
		$BDD->exec("INSERT INTO comments (id_user, id_photo, message, date_and_time) VALUES('{$_SESSION['user_id']}', {$photoId}, {$message}, NOW())");
		redirect('index.php?page=gallery');

	}
	else if ($_GET['action'] == 'del') {
		$res = query_db("SELECT id_user FROM photos WHERE id={$photoId}", $BDD);
		if (!empty($res) && $res[0]['id_user'] == $_SESSION['user_id'])
			$BDD->exec("DELETE FROM photos WHERE id={$photoId}");
		redirect('index.php?page=gallery');
	}
	else redirect('index.php?page=gallery&error');
}
else redirect('index.php?page=gallery&error');
?>
