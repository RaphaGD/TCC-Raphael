<?php
	
	include('conexao_rt.php');

	$amm = $_GET['amm'];
	$bmm = $_GET['bmm'];
	$cmm = $_GET['cmm'];
	$dmm = $_GET['dmm'];
	$emm = $_GET['emm'];
	$fmm = $_GET['fmm'];

	$sql = "INSERT INTO ensaio_ml_movel (amm, bmm, cmm, dmm, emm, fmm) VALUES (:amm, :bmm, :cmm, :dmm, :emm, :fmm)";

	$stmt = $PDO->prepare($sql);

	$stmt->bindParam(':amm', $amm);
	$stmt->bindParam(':bmm', $bmm);
	$stmt->bindParam(':cmm', $cmm);
	$stmt->bindParam(':dmm', $dmm);
	$stmt->bindParam(':emm', $emm);
	$stmt->bindParam(':fmm', $fmm);

	if($stmt->execute()){
		echo "salvo_com_sucesso";
	} else{
		echo "erro_ao_salvar";
	}

	$sql = "UPDATE ensaio_ml_movel SET amm, bmm, cmm, dmm, emm, fmm";

?>
