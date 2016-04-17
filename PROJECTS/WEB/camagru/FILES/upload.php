<?php
session_start();
header ("Content-type: image/png");
include_once('config/header.php');

function random_name() {
	$i = 0;
	$res = "";

	while ($i < 8) {
		if ($i % 2 == 0)
			$char = chr(rand(97, 122));
		else
			$char = rand(0, 9);
		$res = $res.$char;
		$i++;
	}
	return $res;
}


if ( $_POST['choice'] == "tablet" )
	$source = imagecreatefrompng("img/tablet.png");
else if ( $_POST['choice'] == "glasses" )
	$source = imagecreatefrompng("img/glasses.png");
else if ( $_POST['choice'] == "hand" )
	$source = imagecreatefrompng("hand.png");
else if ( $_POST['choice'] == "funny-glasses" )
	$source = imagecreatefrompng("img/funny-glasses.png");
else if ( $_POST['choice'] == "heart" )
	$source = imagecreatefrompng("img/heart.png");


$destination = imagecreatefrompng($_POST['imgData']);

$largeur_source = imagesx($source);
$hauteur_source = imagesy($source);
$largeur_destination = imagesx($destination);
$hauteur_destination = imagesy($destination);

$x = $largeur_destination/2 - $largeur_source/2;
$y = $hauteur_destination/2 - $hauteur_source/2;


imagecopy($destination, $source, $x, $y, 0 , 0, $largeur_source, $hauteur_source);

$imageName = random_name() .".png";
$fileName = "img/photos/".  $imageName;

$BDD->query("INSERT INTO photos (id_user, path, date_creation) VALUES('{$_SESSION['user_id']}', '$imageName', NOW())");

imagepng($destination , $fileName);

redirect('index.php');

?>
