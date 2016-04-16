<?php

function get_login_from_id($id, $bdd) {
	try {
		$query = "SELECT * FROM user WHERE id = ". $id;
		$res = $bdd->query($query)->fetchAll();
		if (empty($res))
			return FALSE;
		else
			return $res[0]['login'];
	} catch(PDOException $e) {
		print("Erreur ! ". $e->getMessage() ."<br />");
		die();
	}
}

function check_password($login, $pass, $bdd) {
	try {
		$query = "SELECT * FROM user WHERE login = ". $login;
		$res = $bdd->query($query)->fetchAll();
		if (empty($res))
			return FALSE;
		else {
			if ($res[0]['password'] === $pass)
				return $res[0];
			else
				return FALSE;
		}
	} catch(PDOException $e) {
		print("Erreur ! ". $e->getMessage() ."<br />");
		die();
	}
}

function user_already_exists($login, $bdd) {
	try {
		$query = "SELECT * FROM user WHERE login = ". $login;
		$res = $bdd->query($query)->fetchAll();
		if (empty($res))
			return FALSE;
		else
			return TRUE;
	} catch(PDOException $e) {
		print("Erreur ! ". $e->getMessage() ."<br />");
		die();
	}
}

?>
