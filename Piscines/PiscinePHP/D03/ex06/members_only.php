<?php
session_start();

$user = 'zaz';
$pass = 'jaimelespetitsponeys';
header('Content-Type: text/html');

//curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

if (!isset($_SERVER['PHP_AUTH_USER']))
{
    header('WWW-Authenticate: Basic realm="My Realm"');
    header('HTTP/1.0 401 Unauthorized');
    echo '<html><body>Cette zone est accessible uniquement aux membres du site</body></html>';
    exit();
}
else
{
	if (USEROK)
	{
		header('WWW-Authenticate: Basic '. base64_encode($user.":".$pass));
	    echo "<p>Bonjour, {$_SERVER['PHP_AUTH_USER']}.</p>";
	    echo "<p>Votre mot de passe est {$_SERVER['PHP_AUTH_PW']}.</p>";
	}
	else
	{
	}
}

?>
