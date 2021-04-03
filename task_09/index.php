<?php
//data base connection
$username = "root";
$password = "";
$host = "localhost";
$dbname = "to-do";
$dsn = "mysql:host=$host;dbname=$dbname";
$pdo = new PDO($dsn, $username, $password);

//if($pdo){
//    echo "You are connected";
//}else{
//    echo "Sorry , You are not connected";
//}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js" integrity="sha384-JEW9xMcG8R+pH31jmWH6WWP0WintQrMb4s7ZOdauHnUtxwoG2vI5DkLtS3qm9Ekf" crossorigin="anonymous">
    </script>
    <style>
        * {
            box-sizing: border-box;
            padding: 0;
            margin: 0;
        }

        #tasks:nth-child(even) {
            background-color: red;
        }

        .tasks {
            font-size: 28px;
        }

        input[type="checkbox"]:checked+label {
            text-decoration: line-through;
            opacity: 0.5;
        }
    </style>
</head>

<body>
    <div class="container-fluid row d-flex justify-content-center mb-3 mt-3">
        <div style="border-radius:10px;" class="col-3  bg-danger">
            <h1 style="text-align:center">To-Do list</h1>
        </div>
    </div>
    <!--task add section-->
    <div class="container-fluid mb-3 p-0 row  d-flex justify-content-center">
        <div class="col-10  d-flex justify-content-center">
            <?php
            if (isset($_GET["id"])) {
                $id=$_GET["id"];
                $tbname = "data";
                $query1 = "SELECT * FROM $tbname WHERE id='$id'"; //fetching tasks from database
                $stmt = $pdo->query($query1);
                $value = $stmt->fetch();
                $task1 = $value["value"];
                echo " <form action='' method='get' class='border-danger'>
                 <input style='width:780px;height:50px;border-radius:10px;font-size:20px;padding:0 0 0 5px;margin:0px;' type='text' value='$task1'
                     name='update_task'>
                <input type='hidden' name='id' value='$id'>
                 <button style='margin-top:-5px;width:100px;height:50px;border-radius:10px' name='update'>update</button>
             </form>";
             if(isset($_GET["update"])){
                $up_task=$_GET["update_task"];
                $id=$_GET["id"];
                $query="UPDATE $tbname SET date=now(), value='$up_task' WHERE id='$id'";
                $stmt=$pdo->prepare($query);
                $execute=$stmt->execute();
                if($execute){
                    //echo "<script> alert('task is updated')</script>";
                    header("location:index.php");
                }
            }
            }else{
                echo " <form action='' method='post' class='border-danger'>
                <input style='width:780px;height:50px;border-radius:10px;font-size:20px;padding:0 0 0 5px;margin:0px;' type='text' placeholder='Add new task..'
                    name='new_task'>
                <button style='margin-top:-5px;width:100px;height:50px;border-radius:10px' name='add'>ADD</button>
            </form>";
            }

            ?>
            <?php

//inserting data into data base
            $tbname = "data";
            if (isset($_POST["add"])) {
                $task = $_POST["new_task"];
                $query = "INSERT INTO $tbname (date,value) VALUES(now(),'$task')"; //inserting new data into the data base
                $stmt = $pdo->prepare($query);
                $execute = $stmt->execute();
                if ($execute) {
                    echo "<script> alert('task is added')</script>";
                } else {
                    echo "<script> alert('error')</script>";
                }
            }
            ?>
        </div>
    </div>
    <?php
    if (isset($_POST["delete"])) {
        if (!empty($_POST["tasks"])) {
            foreach ($_POST['tasks'] as $value2) {
                $query = "DELETE FROM $tbname WHERE value='$value2'"; //delete completed tasks
                $stmt = $pdo->prepare($query);
                $delete = $stmt->execute();
            }
        }
    }
    ?>
    <!--tasks section-->
    <div class="row container-fluid d-flex justify-content-center">
        <div style="border-radius: 10px;" class="col-10 border">
            <form action="" method="post">
                <table class="table table-hover">

                    <?php
                    $query1 = "SELECT * FROM $tbname ORDER BY id DESC"; //fetching tasks from database
                    $stmt = $pdo->query($query1);
                    while ($value = $stmt->fetch()) {
                        $task1 = $value["value"];
                        $date = $value["date"];
                        $id = $value["id"];
                    ?>

                        <tr>
                            <th>
                                <div class="text-wrap tasks form-check">
                                    <input name="tasks[]" class="form-check-input checkbox" type="checkbox" value="<?php echo $task1; ?>" id="flexCheckDefault">
                                    <label style="color: red;" class="form-check-label" for="flexCheckDefault">
                                        
                                        <span style=""><?php echo $task1; ?></span></label>
                                </div>
                            </th>
                            <th style="text-align:center">
                                <?php echo $date; ?>
                            </th>
                            <th>
                                <a href="index.php?id=<?php echo $id; ?>">edit</a>
                            </th>
                        </tr>


                    <?php } ?>
                </table>
                <div style="text-align: center;font-weight:bolder;margin-bottom:5px;">
                    <button style="text-align: center;" name="delete" class="btn btn-danger">Remove Completed
                        Tasks</button>
                </div>
            </form>
        </div>
    </div>
</body>
<script src="jquery.js"></script>
<script>
    $('.checkbox').change(function() {
        if ($(this).is(':checked')) {
            let val = $(this).val();
            console.log(val);
            alert("congratulation you completed the task:"+val);
        } else {
            console.log('Unchecked');
        }
    });
</script>

</html>