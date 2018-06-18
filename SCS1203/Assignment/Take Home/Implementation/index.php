<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 2:46 PM
 */

session_start();
if (isset($_SESSION['user'])) {
    $path = 'components/' . $_SESSION['user'] . '/index.php';
    if (file_exists($path)) {
        header('Location: ' . $path);
    } else header('Location: ' . 'auth/logout.php');
} else {
    header('Location: ' . 'components/auth/index.php');
}