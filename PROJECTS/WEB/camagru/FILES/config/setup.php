<?php
include_once('database.php');

try {
	$bdd = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$bdd->exec("DROP TABLE IF EXISTS user");
	$bdd->exec("CREATE TABLE user (id INT PRIMARY KEY AUTO_INCREMENT NOT NULL, email varchar(100) NOT NULL, login varchar(40) NOT NULL, password char(128) NOT NULL)");
	$bdd->exec("DROP TABLE IF EXISTS photos");
	$bdd->exec("CREATE TABLE photos (id INT PRIMARY KEY AUTO_INCREMENT NOT NULL, id_user smallint(1) NOT NULL, path text(300) NOT NULL, date_creation datetime NOT NULL)");
	$bdd->exec("DROP TABLE IF EXISTS comments");
	$bdd->exec("CREATE TABLE comments (id INT PRIMARY KEY AUTO_INCREMENT NOT NULL, id_user smallint(1) NOT NULL, id_photo smallint(1) NOT NULL, message text(1000) NOT NULL, date_and_time datetime NOT NULL)");
	$bdd->exec("DROP TABLE IF EXISTS likes");
	$bdd->exec("CREATE TABLE likes (id INT PRIMARY KEY AUTO_INCREMENT NOT NULL, id_user smallint(1) NOT NULL, id_photo smallint(1) NOT NULL, date_and_time datetime NOT NULL)");
	$bdd = null;
} catch(PDOException $e) {
	print("Erreur ! ". $e->getMessage() ."<br />");
	print($e);
	die();
}

if (!file_exists("../img/photos")) mkdir("../img/photos");

header('Location: ../index.php');

?>
