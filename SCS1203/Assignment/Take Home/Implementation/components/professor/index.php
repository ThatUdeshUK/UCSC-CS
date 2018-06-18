<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 6:36 PM
 */

session_start();
if (isset($_SESSION['user']) && $_SESSION['user'] == 'professor') {
    require_once '../../views/header.php';
    echo "Professor";
    require_once '../../views/footer.php';
} else header('Location: ' . '../../index.php');
