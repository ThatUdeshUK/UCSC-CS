<?php
/**
 * Created by PhpStorm.
 * User: udesh
 * Date: 6/15/18
 * Time: 7:38 PM
 */

class Model
{
    // Users
    public static function getUsers(Database $db)
    {
        $result = $db->query("select user from mysql.db where Db = 'university' group by user");
        return self::getAssocArray($result);
    }

    // Department
    public static function getDepartments(Database $db)
    {
        $result = $db->query("select * from department");
        return self::getAssocArray($result);
    }

    public static function getDepartment(Database $db, $d_code)
    {
        $result = $db->query("select * from department where d_code = " . $d_code );
        return $result->fetch_assoc();
    }


    public static function addDepartment(Database $db, $name, $phone, $location, $head)
    {
        if ($head)
            $sql = "insert into department (d_name, phone, d_location, head) values ('". $name ."','". $phone ."','". $location ."','". $head ."')";
        else
            $sql = "insert into department (d_name, phone, d_location) values ('". $name ."','". $phone ."','". $location ."')";
        $result = $db->query($sql);
        return $result;
    }

    public static function updateDepartment(Database $db, $code, $name, $phone, $location, $head)
    {
        if ($head)
            $sql = "update department set d_name = '". $name ."', phone = '". $phone ."', d_location = '". $location ."', head = ". $head ." where d_code = " . $code;
        else
            $sql = "update department set d_name = '". $name ."', phone = '". $phone ."', d_location = '". $location ."' where d_code = " . $code;
        $result = $db->query($sql);
        return $result;
    }

    public static function deleteDepartment(Database $db, $code)
    {
        $sql = "delete from department where d_code = " . $code;
        $result = $db->query($sql);
        return $result;
    }

    private static function getAssocArray(mysqli_result $result) {
        $items = array();
        if ($result->num_rows > 0)
            while($row = $result->fetch_assoc())
                $items[] = $row;
        return $items;
    }
}