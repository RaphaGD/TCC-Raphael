<?php
	
	include('conexao.php');

	$Reference = $_GET['Reference'];
	$Object_1 = $_GET['Object_1'];
	$Object_2 = $_GET['Object_2'];
	$Object_3 = $_GET['Object_3'];
	$Object_4 = $_GET['Object_4'];

	$sql = "INSERT INTO ensaio_ml_fixo (Reference, Object_1, Object_2, Object_3, Object_4) VALUES (:Reference, :Object_1, :Object_2, :Object_3, :Object_4)";

	$stmt = $PDO->prepare($sql);

	$stmt->bindParam(':Reference', $Reference);
	$stmt->bindParam(':Object_1', $Object_1);
	$stmt->bindParam(':Object_2', $Object_2);
	$stmt->bindParam(':Object_3', $Object_3);
	$stmt->bindParam(':Object_4', $Object_4);

	if($stmt->execute()){
		echo "salvo_com_sucesso";
	} else{
		echo "erro_ao_salvar";
	}
?>
