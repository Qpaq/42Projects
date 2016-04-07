<?php
$file = '../img/42.png';

//header('HTTP/1.1 200 OK');
header('Content-Type: image/png');
readfile($file);

?>
