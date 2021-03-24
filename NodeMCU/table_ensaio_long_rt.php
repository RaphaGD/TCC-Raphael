<?php

	include('conexao_rt.php');

	$sql = "SELECT * FROM ensaio_long";
		$result = mysqli_query($conn, $sql);
		if (mysqli_num_rows($result) > 0) {
			while ($row = mysqli_fetch_assoc($result)) {
				echo "<div style='border:5'>";
				echo "Id :" . $row["ID"]. " | Medida :" . $row["Medida"] . " | Date :" . $row["Date"] . "<br>";
				echo "</div>";
			}
		}	
		else {
		echo "0 results";
		}

?>