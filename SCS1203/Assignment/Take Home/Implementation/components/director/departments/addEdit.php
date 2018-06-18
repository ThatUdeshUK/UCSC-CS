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
if (isset($_SESSION['user']) && $_SESSION['user'] == 'director') {
    $db = new Database('director');
    if (isset($_GET['code']))
        $department = Model::getDepartment($db, $_GET['code']);
    require_once '../../../views/header.php';
    ?>
    <a href="show.php" class="btn btn-dark" style="margin-top: 2rem; margin-bottom: 2rem;">Go back</a>
    <?php
    if (isset($_POST['update']) || isset($_POST['add'])) {
        if (isset($_POST['name']) && isset($_POST['phone']) && isset($_POST['location'])) {
            if (isset($_POST['head'])) {
                $head = $_POST['head'];
            } else {
                $head = null;
            }
            if (isset($_POST['add']))
                $result = Model::addDepartment($db, $_POST['name'], $_POST['phone'], $_POST['location'], $head);
            else if (isset($_POST['update']) && isset($_POST['code']))
                $result = Model::updateDepartment($db, $_POST['code'], $_POST['name'], $_POST['phone'], $_POST['location'], $head);
            if ($result)
                showSuccess();
            else
                showError();
        } else showError();
    } else {
        ?>
        <h4><?php if (isset($department)) echo "Update"; else echo "Add"; ?></h4>
        <form action="addEdit.php" method="post">
            <div class="row">
                <div class="col"><input type="text" class="form-control" placeholder="Name" name="name" value="<?php if (isset($department)) echo $department['d_name']; ?>"></div>
                <div class="col"><input type="text" class="form-control" placeholder="Phone" name="phone" value="<?php if (isset($department)) echo $department['phone']; ?>"></div>
                <div class="col"><input type="text" class="form-control" placeholder="location" name="location" value="<?php if (isset($department)) echo $department['d_location']; ?>"></div>
                <!--                    <div class="col">-->
                <!--                        <select class="form-control" name="user" id="user_select">-->
                <!--                            --><?php //foreach ($users as $user) {?>
                <!--                                <option>--><?php //echo $user['user']; ?><!--</option>-->
                <!--                            --><?php //} ?>
                <!--                        </select>-->
                <!--                    </div>-->
                <input type="hidden" value="<?php if (isset($department)) echo $department['d_code']; ?>" name="code" />
                <button type="submit" class="btn btn-primary" name="<?php if (isset($department)) echo "update"; else echo "add"; ?>">Submit</button>
            </div>
        </form>
        <?php
    }
    require_once '../../../views/footer.php';
} else header('Location: ' . '../../../index.php');

function showSuccess() {
    ?>
    <div class="alert alert-success" role="alert">
        <strong>Successful!</strong>
    </div>
    <?php
}

function showError() {
    ?>
    <div class="alert alert-warning" role="alert">
        <strong>Failed!</strong>
    </div>
    <?php
}