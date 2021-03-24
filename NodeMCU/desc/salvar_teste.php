<?php
	
	include('conexao.php');

	$MEASURE = $_GET['Measure'];
	$AVERAGE = $_GET['Average'];
	$SD = $_GET['SD'];

	$sql = "INSERT INTO tb_dados (Measure, Average, SD) VALUES (:Measure, :Average, :SD)";

	$stmt = $PDO->prepare($sql);

	$stmt->bindParam(':Measure', $MEASURE);
	$stmt->bindParam(':Average', $AVERAGE);
	$stmt->bindParam(':SD', $SD);

	if($stmt->execute()){
		echo "salvo_com_sucesso";
	} else{
		echo "erro_ao_salvar";
	}

?>
