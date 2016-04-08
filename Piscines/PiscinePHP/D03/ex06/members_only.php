<?php
session_start();

$user = '';
$pass = '';
header('WWW-Authenticate: Basic '. base64_encode($user.":".$pass));
//curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
if (!isset($_SESSION['']))
{

}

?>
/*
if (!isset($_SERVER['PHP_AUTH_USER'])) {
    header('WWW-Authenticate: Basic realm="My Realm"');
    header('HTTP/1.0 401 Unauthorized');
    echo 'Texte utilisé si le visiteur utilise le bouton d\'annulation';
    exit;
} else {
    echo "<p>Bonjour, {$_SERVER['PHP_AUTH_USER']}.</p>";
    echo "<p>Votre mot de passe est {$_SERVER['PHP_AUTH_PW']}.</p>";
}

*/
