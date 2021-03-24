<?php
	try {
		$HOST = "localhost";
		$BANCO = "BD_NodeMCU";
		$USER = "root";
		$PW = "";

		$conn = mysqli_connect($HOST, $USER, $PW, $BANCO);

		$PDO = new PDO("mysql:host=" . $HOST . "; dbname=" . $BANCO . "; charset=utf8", $USER, $PW);

	} 
	catch(PDOException $erro){

		echo "Erro de conexão, detalhes: " . $echo->getMessage();
	}
?>
