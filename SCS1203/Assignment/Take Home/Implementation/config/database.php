<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 3:53 PM
 */
require_once 'config.php';

class Database
{
    private $conn;
    private $user = 'root';

    public function __construct($user) {
        if (isset($user))
            $this->user = $user;
        $this->conn = new mysqli(DB_HOST, $this->user, '', DB_NAME);

        // Error handling
        if(mysqli_connect_error()) {
            trigger_error("Failed to conencto to MySQL: " ,E_USER_ERROR);
        }
    }

    public function query($sql) {
        return $this->conn->query($sql);
    }

    public function __destruct()
    {
        $this->conn->close();
    }
}