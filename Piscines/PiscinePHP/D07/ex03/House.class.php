<?php

class House {

	public function __construct() {
	}

	public function introduce() {
		printf("House %s of %s : \"%s\"\n", $this->getHouseName(), $this->getHouseSeat(),  $this->getHouseMotto());
	}

}

?>
