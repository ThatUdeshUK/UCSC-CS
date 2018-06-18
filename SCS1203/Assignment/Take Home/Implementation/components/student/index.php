<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 6:48 PM
 */

session_start();
if (isset($_SESSION['user']) && $_SESSION['user'] == 'student') {
    require_once '../../views/header.php';
    echo "Student";
    require_once '../../views/footer.php';
} else header('Location: ' . '../../index.php');
