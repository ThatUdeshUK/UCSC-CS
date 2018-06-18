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
    $items = array();
    $db = new Database('director');
    require_once '../../../views/header.php';
    ?>
    <a href="../index.php" class="btn btn-dark" style="margin-top: 2rem; margin-bottom: 2rem;">Go back</a>
    <a href="addEdit.php" class="btn btn-dark" style="margin-top: 2rem; margin-bottom: 2rem;">Add</a>
    <?php
    $departments = Model::getDepartments($db);
    ?>
    <table class="table">
        <thead>
        <tr>
            <th>Code</th>
            <th>Name</th>
            <th>Phone</th>
            <th>Location</th>
            <th>Head</th>
            <th>Action</th>
        </tr>
        </thead>
        <tbody>
        <?php foreach ($departments as $department) { ?>
            <tr>
                <td scope="row"><?php echo $department['d_code']?></td>
                <td><?php echo $department['d_name']?></td>
                <td><?php echo $department['phone']?></td>
                <td><?php echo $department['d_location']?></td>
                <td><?php echo "Head"?></td>
                <td>
                    <a href="addEdit.php?code=<?php echo $department['d_code'] ?>" class="btn btn-danger">Update</a>
                    <a href="delete.php?code=<?php echo $department['d_code'] ?>" class="btn btn-danger">Delete</a>
                </td>
            </tr>
        <?php } ?>
        </tbody>
    </table>
    <?php
    require_once '../../../views/footer.php';
} else header('Location: ' . '../../index.php');