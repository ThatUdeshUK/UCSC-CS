<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 3:02 PM
 */
require_once '../../config/database.php';
require_once '../../model.php';

session_start();
if (isset($_POST['user'])) {
    $_SESSION['user'] = $_POST['user'];
    header('Location: ' . '../../index.php');
} else {
    if (!isset($_SESSION['user'])) {
        $db = new Database('root');
        $users = Model::getUsers($db);
        require '../../views/header.php'; ?>
        <br>
        <div class="row h-100 justify-content-center align-items-center">
            <div class="card" style="width: 24rem;">
                <div class="card-body">
                    <h5 class="card-title">Login</h5>
                    <form action="" method="post">
                        <div class="form-group">

                            <label for="user_select">Select User</label>
                            <select class="form-control" name="user" id="user_select">
                                <?php foreach ($users as $user) {?>
                                    <option><?php echo $user['user']; ?></option>
                                <?php } ?>
                            </select>
                        </div>
                        <button type="submit" class="btn btn-primary|secondary|success|info|warning|danger">Login</button>
                    </form>
                </div>
            </div>
        </div>
        <?php
        require '../../views/footer.php';
    } else header('Location: ' . '../../index.php');
}
