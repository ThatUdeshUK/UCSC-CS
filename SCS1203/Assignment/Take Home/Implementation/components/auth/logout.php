<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 6:16 PM
 */

session_start();
session_destroy();
header('Location: ' . '../../index.php');