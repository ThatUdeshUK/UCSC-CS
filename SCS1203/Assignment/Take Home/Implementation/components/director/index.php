<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 5:17 PM
 */

session_start();
if (isset($_SESSION['user']) && $_SESSION['user'] == 'director') {
    require_once '../../views/header.php';
    ?>
    <div class="row">
        <a href="departments/show.php" class="btn btn-outline-dark text-center" style="width: 16rem; margin: 16px;">
            <i class="material-icons" style="margin-top: 4rem; margin-bottom: 2rem; font-size: 72px;">
                business
            </i>
            <div style="margin-bottom: 2.5rem; font-size: 24px;">
                Department
            </div>
        </a>
        <a href="professors/show.php" class="btn btn-outline-dark text-center" style="width: 16rem; margin: 16px;">
            <i class="material-icons" style="margin-top: 4rem; margin-bottom: 2rem; font-size: 72px;">
                person
            </i>
            <div style="margin-bottom: 2.5rem; font-size: 24px;">
                Professors
            </div>
        </a>
    </div>

    <!--    <h2 style="padding-top: 4rem;">Professors</h2>-->
    <!--    <div class="row">-->
    <!--        <a href="departments/show.php?what=professor" class="btn btn-light btn-lg" style="margin-right: 1rem;">Show Professors</a>-->
    <!--        <a class="btn btn-light btn-lg" style="margin-right: 1rem;">Add Professor</a>-->
    <!--        <a class="btn btn-light btn-lg" style="margin-right: 1rem;">Remove Professor</a>-->
    <!--        <a class="btn btn-light btn-lg" style="margin-right: 1rem;">Update Professor</a>-->
    <!--    </div>-->
    <?php
    require_once '../../views/footer.php';
} else header('Location: ' . '../../index.php');
