<?php

	include('conexao_rt.php');

	$sql = "SELECT * FROM ensaio_ml_movel";
		$result = mysqli_query($conn, $sql);
		if (mysqli_num_rows($result) > 0) {
			while ($row = mysqli_fetch_assoc($result)) {
				echo "<div style='border:1'>";
				echo "Id :" . $row["ID"]. " | amm :" . $row["amm"]. " | bmm :" . $row["bmm"]. " | cmm :" . $row["cmm"]. " | dmm :" .$row["dmm"]. " | emm :" .$row["emm"]. " | fmm :" .$row["fmm"]. " | Date: " .$row["Date"] . "<br>";
				echo "</div>";
			}
		}	
		else {
		echo "0 results";
		}

?>