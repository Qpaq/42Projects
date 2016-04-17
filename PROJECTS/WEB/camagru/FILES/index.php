<?php
session_start();
include_once('config/header.php');
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Camagru</title>
		<link rel="stylesheet" type="text/css" href="css/main.css" />
	</head>
	<body>
		<header>
			<a href="index.php">Index</a>
			<a href="index.php?page=gallery">Gallery</a>
			<a href="index.php?page=account">My Account</a>
			<?php
				if (isset($_SESSION['user_id']))
					echo "<a href='logout.php'>Logout</a>";
				else
					echo "<a href='login.php'>Login</a>";
			?>
		</header>
<?php
if (isset($_SESSION['user_id']) && $_GET['page'] != 'gallery') {
	if ($_GET['page'] == 'account') {
		include_once('account.php');
	}
	else {
		$users5LastPhotos = query_db("SELECT path AS src FROM photos WHERE id_user='{$_SESSION['user_id']}' ORDER BY date_creation DESC LIMIT 5", $BDD);
?>

<div id="miniatures">
	<?php
		if (!empty($users5LastPhotos)) {
			foreach ($users5LastPhotos as $miniature) {
				echo "<img src='img/photos/{$miniature['src']}' class='miniature' />";
			}
		}
		?>

</div>

<div id="container">
	<video autoplay="true" id="video"> </video>
	<img id="myImg" src="#" />
    <br/><br/>
    <input type='file' id="imgInp" />

    <br/><br/>

    <form method="post" action="upload.php">
		  <label>
		    <input  type="radio" name="choice" value="heart"  onclick="check()"  />
		    <img class="choiceImg"  src="img/heart.png">
		  </label>

		  <label>
		    <input type="radio" name="choice" value="glasses" onclick="check()" />
		    <img class="choiceImg" src="img/glasses.png">
		  </label>

		  <label>
		    <input  type="radio" name="choice" value="hand"  onclick="check()" />
		    <img class="choiceImg" src="img/hand.png">
		  </label>

		  <label>
		    <input  type="radio" name="choice" value="tablet"  onclick="check()" />
		    <img class="choiceImg" src="img/tablet.png">
		  </label>

		   <label>
		    <input  type="radio" name="choice" value="funny-glasses"  onclick="check()" />
		    <img class="choiceImg" src="img/funny-glasses.png">
		  </label>


    	<input type="hidden" name="imgData" id="imgData" />
		<input type="submit" disabled="disabled" value="Choose a picture" id="startbutton" />
	</form>


	<canvas id="canvas"></canvas>
	<?php
	if (file_exists("img/photos/newImg.png"))
		echo "<img src='img/photos/newImg.png' id='photo' alt='photo'>";
	?>

</div>
<script src="webcam.js"> </script>


<?php
	}
} else if ($_GET['page'] == 'gallery') {
	include_once('gallery.php');
}
?>
		<footer>
		</footer>
	</body>
</html>
