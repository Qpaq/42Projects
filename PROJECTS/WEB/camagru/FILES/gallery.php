<?php
$photosCount = $BDD->query("SELECT COUNT(*) FROM photos")->fetch()[0];
$nbOfPages = ceil($photosCount / 3);
if (isset($_GET['nb'])) {
	$currentPage = intval($_GET['nb']);
	if ($currentPage < 1 || $currentPage > $nbOfPages) $currentPage = 1;
} else $currentPage = 1;

$offset = ($currentPage - 1) * 3;
$photos = query_db("SELECT * FROM photos ORDER BY date_creation DESC LIMIT 3 OFFSET {$offset}", $BDD);
if (empty($photos)) {
	echo "No photos yet !";
	die();
}

if (isset($_GET['error'])) {
?>
<script>alert("You need to be logged in to like, comment, or delete a photo !");</script>
<?php } ?>

<div id="pages">
	Pages:<br/>
	<?php
		for ($i = 1; $i <= $nbOfPages; $i++) {
			echo "<a href='index.php?page=gallery&nb={$i}'> - {$i} - </a>";
		}
	?>
</div>

	<table id="gallery">
		<?php foreach($photos as $photo) { ?>
			<tr>
				<td>
					<img src="img/photos/<?php echo $photo['path']; ?>" />
				</td>
				<td>
					<p>
						Likes:
						<?php
							$nb_likes = query_db("SELECT COUNT(*) FROM likes WHERE id_photo='{$photo['id']}'", $BDD);
							echo $nb_likes[0][0];
						?><br />
						<button class="like" onclick="likePhoto(this);" value="<?php echo $photo['id']; ?>">&#9829;</button>
					</p>
					<?php if (isset($_SESSION['user_id']) && $_SESSION['user_id'] == $photo['id_user']) { ?>
					<button class="like" onclick="removePhoto(this);" value="<?php echo $photo['id']; ?>">X</button>
					<?php } ?>
					<p>
						<textarea class="comment_text" maxlength="500" name="<?php echo $photo['id']; ?>" placeholder="Enter comment here"></textarea><br />
						<button class="comment_button" onclick="commentPhoto(this);" value="<?php echo $photo['id']; ?>">COMMENT</button>
					</p>
				</td>
				<td>
					<h4>Comments</h4>
					<?php
					$q = "SELECT user.login AS user_login, comments.message AS message, DATE_FORMAT(comments.date_and_time, '%b %e %Y, %H:%i') AS date_message FROM comments INNER JOIN user ON comments.id_user = user.id WHERE comments.id_photo ='{$photo['id']}' ORDER BY comments.date_and_time DESC";
					$comments = query_db($q, $BDD);
					if (!empty($comments)) {
						foreach ($comments as $comment) {
							echo "<p>";
							echo "[{$comment['date_message']}] {$comment['user_login']}: ";
							echo $comment['message'];
							echo "</p>";
						}
					}
					?>
				</td>
			</tr>
		<?php } ?>
	</table>

<script type="text/javascript">
function likePhoto(obj) {
	window.location.href = "like_comment.php?action=like&id=" + obj.value;
}
function removePhoto(obj) {
	window.location.href = "like_comment.php?action=del&id=" + obj.value;
}
function commentPhoto(obj) {
	var comment = document.querySelector("textarea[name='"+ obj.value +"']");
	window.location.href = "like_comment.php?action=comment&id=" + obj.value + "&message=" + comment.value;
}
</script>
