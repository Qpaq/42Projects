<?php
$photos = query_db("SELECT * FROM photos ORDER BY date_creation DESC", $BDD);
if (empty($photos)) {
	echo "No photos yet !";
	//die();
}
?>
<section>
	<table>
		<?php foreach($photos as $photo) { ?>
			<tr>
				<td>
					<img src="<?php echo $photo['path']; ?>" />
				</td>
				<td>
					<p>
						<button class="like" onclick="likePhoto(this);" value="<?php echo $photo['id']; ?>">&#9829;</button>
					</p>
					<p>
						<textarea class="comment_text" name="<?php echo $photo['id']; ?>" placeholder="Enter comment here"></textarea><br />
						<button class="comment_button" onclick="commentPhoto(this);" value="<?php echo $photo['id']; ?>">COMMENT</button>
					</p>
				</td>
			</tr>
		<?php } ?>
	</table>
</section>

<script type="text/javascript">
function likePhoto(obj) {
	console.log(obj.value);
}
function commentPhoto(obj) {
	var comment = document.querySelector("textarea[name='"+ obj.value +"']");
	console.log(comment.value);
}
</script>
