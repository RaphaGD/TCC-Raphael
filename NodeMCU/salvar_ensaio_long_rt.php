<?php
	
	include('conexao_rt.php');

	$Medida = $_GET['Medida'];

	$sql = "INSERT INTO ensaio_long (Medida) VALUES (:Medida)";

	$stmt = $PDO->prepare($sql);

	$stmt->bindParam(':Medida', $Medida);

	if($stmt->execute()){
		echo "salvo_com_sucesso";
	} else{
		echo "erro_ao_salvar";
	}

	$sql = "UPDATE ensaio_long SET Medida";
?>
