<?php

include_once(realpath(dirname(__FILE__)).'/database.php');
include_once(realpath(dirname(__FILE__)).'/users.php');

$BDD = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);

function exec_db($query, $bdd) {
	try {
		$bdd->exec($query);
	} catch(PDOException $e) {
		print("Erreur EXEC ! ". $e->getMessage() ."<br />");
		print($e."<br />");
		die();
	}
}

function query_db($query, $bdd) {
	try {
		$res = $bdd->query($query);
		return $res->fetchAll();
	} catch(PDOException $e) {
		print("Erreur QUERY ! ". $e->getMessage() ."<br />");
		die();
	}
}

function redirect($filename) {
	if (!headers_sent())
		@header('Location: '.$filename);
	else {
		echo '<script type="text/javascript">window.location.href="'.$filename.'";</script>';
		echo '<noscript><meta http-equiv="refresh" content="0;url='.$filename.'" /></noscript>';
	}
}

?>
