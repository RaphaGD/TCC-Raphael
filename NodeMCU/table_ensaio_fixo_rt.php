<?php

	include('conexao_rt.php');

	$sql = "SELECT * FROM ensaio_ml_fixo";
		$result = mysqli_query($conn, $sql);
		if (mysqli_num_rows($result) > 0) {
			while ($row = mysqli_fetch_assoc($result)) {
				echo "<div style='border:1'>";
				echo "Id :" . $row["ID"]. " | Reference :" . $row["Reference"]. " | Object_1 :" . $row["Object_1"]. " | Object_2 :" . $row["Object_2"]. " | Object_3 :" .$row["Object_3"]. " | Object_4 :" .$row["Object_4"]. " | Fim :" .$row["Fim"] . " | Date: " .$row["Date"] . "<br>";
				echo "</div>";
			}
		}	
		else {
		echo "0 results";
		}

?>