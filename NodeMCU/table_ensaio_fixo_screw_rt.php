<?php

	include('conexao_rt.php');

	$sql = "SELECT * FROM ensaio_ml_fixo_screw";
		$result = mysqli_query($conn, $sql);
		if (mysqli_num_rows($result) > 0) {
			while ($row = mysqli_fetch_assoc($result)) {
				echo "<div style='border:1'>";
				echo "Id :" . $row["ID"]. " | Reference :" . $row["Reference"]. " | P1 :" . $row["P_1"]. " | P2 :" . $row["P_2"]. " | P3 :" .$row["P_3"]. " | P4 :" .$row["P_4"]. " | P5 :" .$row["P_5"]. " | P6 :" .$row["P_6"]. " | P7 :" .$row["P_7"]." | P8 :" .$row["P_8"]." | P9 :" .$row["P_9"]." | P10 :" .$row["P_10"]." | P11 :" .$row["P_11"]." | Fim :" .$row["Fim"] . " | Date: " .$row["Date"] . "<br>";
				echo "</div>";
			}
		}	
		else {
		echo "0 results";
		}

?>