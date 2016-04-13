class Vector {

	private $_x;
	private $_y;
	private $_z;
	private $_w = 0.0;

	public static $verbose = False;

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }

	public static function doc() {
		echo file_get_contents("Vector.doc.txt");
	}

	public function __construct(array $kwargs) {
		if (array_key_exists($kwargs['dest']) && array_key_exists($kwargs['orig']))
	}
	public function __destruct() {
		if (self::$verbose)
			printf("", $this);
	}

	public function __toString() {
		return sprintf("", );
	}

	public function magnitude() {
		// returns a FLOAT
	}

	public function normalize() {
		// returns a VECTOR
	}

	public function add ($rhs) {
	}

	public function sub($rhs) {
	}

	public function opposite() {
	}

	public function scalarProduct($k) {
	}

	public function dotProduct($rhs) {
		// float
	}

	public function cos($rhs) {
		// float
	}

	public function crossProduct($rhs) {
	}
}
