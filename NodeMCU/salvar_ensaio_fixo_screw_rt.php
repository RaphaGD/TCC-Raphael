<?php
	
	include('conexao_rt.php');

	$Reference = $_GET['Reference'];
	$P_1 = $_GET['P_1'];
	$P_2 = $_GET['P_2'];
	$P_3 = $_GET['P_3'];
	$P_4 = $_GET['P_4'];
	$P_5 = $_GET['P_5'];
	$P_6 = $_GET['P_6'];
	$P_7 = $_GET['P_7'];
	$P_8 = $_GET['P_8'];
	$P_9 = $_GET['P_9'];
	$P_10 = $_GET['P_10'];
	$P_11 = $_GET['P_11'];
	$Fim = $_GET['Fim'];
	
	$sql = "INSERT INTO ensaio_ml_fixo_screw (Reference, P_1, P_2, P_3, P_4, P_5, P_6, P_7, P_8, P_9, P_10, P_11, Fim) VALUES (:Reference, :P_1, :P_2, :P_3, :P_4, :P_5, :P_6, :P_7, :P_8, :P_9, :P_10, :P_11, :Fim)";

	$stmt = $PDO->prepare($sql);

	$stmt->bindParam(':Reference', $Reference);
	$stmt->bindParam(':P_1', $P_1);
	$stmt->bindParam(':P_2', $P_2);
	$stmt->bindParam(':P_3', $P_3);
	$stmt->bindParam(':P_4', $P_4);
	$stmt->bindParam(':P_5', $P_5);
	$stmt->bindParam(':P_6', $P_6);
	$stmt->bindParam(':P_7', $P_7);
	$stmt->bindParam(':P_8', $P_8);
	$stmt->bindParam(':P_9', $P_9);
	$stmt->bindParam(':P_10', $P_10);
	$stmt->bindParam(':P_11', $P_11);
	$stmt->bindParam(':Fim', $Fim);

	if($stmt->execute()){
		echo "salvo_com_sucesso";
	} else{
		echo "erro_ao_salvar";
	}

	$sql = "UPDATE ensaio_ml_fixo_screw SET Reference, P_1, P_2, P_3, P_4, P_5, P_6, P_7, P_8, P_8, P_9, P_10, P_11, Fim";

?>
