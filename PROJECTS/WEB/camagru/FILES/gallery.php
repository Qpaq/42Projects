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
					<button class="like" value="<?php echo $photo['id']; ?>">LIKE</button>
					<textarea class="comment_text" name="<?php echo $photo['id']; ?>" placeholder="Enter comment here"></textarea><br />
					<button class="comment_button" value="<?php echo $photo['id']; ?>">COMMENT</button>
				</td>
			</tr>
		<?php } ?>
	</table>
</section>
