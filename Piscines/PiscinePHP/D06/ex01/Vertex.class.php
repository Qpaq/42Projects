class Vertex {

	private $_x;
	private $_y;
	private $_z;
	private $_w = 1.0;
	private $_color = new Color(array("red" => 0, "green" => 0, "blue" => 0));

	public static $verbose = False;

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function getColor() { return $this->_color; }
	public function setX($val) { $this->_x = $val; }
	public function setY($val) { $this->_y = $val; }
	public function setZ($val) { $this->_z = $val; }
	public function setW($val) { $this->_w = $val; }
	public function setColor($val) { $this->_color = clone $val; }

	public function doc() {
		echo file_get_contents("Vertex.doc.txt");
	}

	public function __construct(array $kwargs) {
		if (!($kwargs['x'] && $kwargs['y'] && $kwargs['z']))
			die("Error Vertex");
		$this->_x = $kwargs['x'];
		$this->_y = $kwargs['y'];
		$this->_z = $kwargs['z'];

		if ($kwargs['w'])
			$this->_w = $kwargs['w'];
		if ($kwargs['color'])
			$this->_color = clone $kwargs['color'];
	}

	public function __destruct() {
		return;
	}

	public function __toString() {
		echo "x: {$this->_x}, y: {$this->_y}, z: {$this->_z}";
	}
}
