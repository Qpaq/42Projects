class Color {

	public $red;
	public $green;
	public $blue;

	public static $verbose = False;

	public static function doc() {
		return file_get_contents("Color.doc.txt");
	}

	public function __construct(array $rgb) {
		if ($rgb['rgb']) {
			$this->red = convert_base($rgb['rgb'][0].$rgb['rgb'][1], 16, 10);
			$this->green = convert_base($rgb['rgb'][2].$rgb['rgb'][3], 16, 10);
			$this->blue = convert_base($rgb['rgb'][4].$rgb['rgb'][5], 16, 10);
		} else if ($rgb['red'] && $rgb['green'] && $rgb['blue']) {
				$this->red = $rgb['red'];
				$this->green = $rgb['green'];
				$this->blue = $rgb['blue'];
		} else {
			return die("Error");
		}
		if (self::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.", $this->red, $this->green, $this->blue);
		return;
	}

	public function __destruct() {
		if (self::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.", $this->red, $this->green, $this->blue);
		return;
	}

	public function __toString() {
			return sprintf("Color( red: %3d, green: %3d, blue: %3d ) constructed.", $this->red, $this->green, $this->blue);
	}
	
	public function add($instance) {
		$red  = $this->red + $instance->red;
		$green  = $this->green + $instance->green;
		$blue  = $this->blue + $instance->blue;
		return (new Color(array("red" => $red, "green" => $green, "blue" => $blue)));
	}

	public function sub($instance) {
		$red  = $this->red - $instance->red;
		$green  = $this->green - $instance->green;
		$blue  = $this->blue - $instance->blue;
		return (new Color(array("red" => $red, "green" => $green, "blue" => $blue)));
	}

	public function mult($nb) {
		$red  = $this->red * $nb;
		$green  = $this->green * $nb;
		$blue  = $this->blue * $nb;
		return (new Color(array("red" => $red, "green" => $green, "blue" => $blue)));
	}
}
