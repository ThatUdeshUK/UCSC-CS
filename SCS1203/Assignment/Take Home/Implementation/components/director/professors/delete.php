<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 7:14 PM
 */
require_once '../../../config/database.php';
require_once '../../../model.php';

session_start();
if (isset($_SESSION['user']) && $_SESSION['user'] == 'director' && isset($_GET['code'])) {
    $db = new Database('director');
    require_once '../../../views/header.php';
    ?>
    <a href="show.php" class="btn btn-dark" style="margin-top: 2rem; margin-bottom: 2rem;">Go back</a>
    <?php
    $result = Model::deleteDepartment($db, $_GET['code']);
    if ($result)
        showSuccess();
    else
        showError();
    require_once '../../../views/footer.php';
} else header('Location: ' . '../../../index.php');

function showSuccess() {
    ?>
    <div class="alert alert-success" role="alert">
        <strong>Delete successful!</strong>
    </div>
    <?php
}

function showError() {
    ?>
    <div class="alert alert-warning" role="alert">
        <strong>Delete failed!</strong>
    </div>
    <?php
}