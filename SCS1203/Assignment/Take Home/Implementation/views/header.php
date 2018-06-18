<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>University</title>
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <link rel="stylesheet" href="<?php $_SERVER['DOCUMENT_ROOT']?>/Projects/Implementation/css/bootstrap.css">
</head>
<body>
<nav class="navbar navbar-dark bg-dark">
    <span class="navbar-brand mb-0 h1">University</span>
    <span class="navbar-text">
        <?php if (isset($_SESSION['user'])) echo 'Selected User: ' . ucfirst($_SESSION['user']); ?>
    </span>
    <?php if (isset($_SESSION['user'])) { ?>
    <nav class="nav nav-inline justify-content-end">
        <li class="nav-item">
            <a class="nav-link active" href="<?php $_SERVER['DOCUMENT_ROOT']?>/Projects/Implementation/components/auth/logout.php">Logout</a>
        </li>
    </nav>
    <?php } ?>
</nav>
<div class="container">