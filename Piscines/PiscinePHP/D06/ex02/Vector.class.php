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
		if (!array_key_exists('dest', $kwargs))
			die("Error Vector");
		if (array_key_exists('orig', $kwargs))
			$orig = $kwargs['orig'];
		else
			$orig = new Vertex('x' => 0, 'y' => 0, 'z' => 0);
		$dest = $kwargs['dest'];
		$this->_x = $dest->getX() - $orig->getX();
		$this->_y = $dest->getY() - $orig->getY();
		$this->_z = $dest->getZ() - $orig->getZ();

		if (self::$verbose)
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed", $this->_x, $this->_y, $this->_z, $this->_w);
	}
	public function __destruct() {
		if (self::$verbose)
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function __toString() {
		return sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function magnitude() {
		return (sqrt($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z));
	}

	public function normalize() {
		if ($this->magnitude() == 1)
			return (clone $this);
		$new_x = $this=>_x / $this->magnitude;
		$new_y = $this=>_y / $this->magnitude;
		$new_z = $this=>_z / $this->magnitude;
		return (new Vector('dest' => new Vertex('x' => $new_x, 'y' => $new_y, 'z' => $new_z)));
	}

	public function add(Vector $rhs) {
		$new_x = $this->_x + $rhs->getX();
		$new_y = $this->_y + $rhs->getY();
		$new_z = $this->_z + $rhs->getZ();
		return (new Vector('dest' => new Vertex('x' => $new_x, 'y' => $new_y, 'z' => $new_z)));
	}

	public function sub(Vector $rhs) {
		$new_x = $this->_x - $rhs->getX();
		$new_y = $this->_y - $rhs->getY();
		$new_z = $this->_z - $rhs->getZ();
		return (new Vector('dest' => new Vertex('x' => $new_x, 'y' => $new_y, 'z' => $new_z)));
	}

	public function opposite() {
	}

	public function scalarProduct($k) {
		return (new Vector('dest' => new Vertex('x' => $this->_x * $k, 'y' => $this->_y * $k, 'z' => $this->z * $k)));
	}

	public function dotProduct($rhs) {
		return $this->_x * $k->getX() + $this->_y * $k->getY() + $this->z * $k->getZ();
		//return (new Vector('dest' => new Vertex('x' => $this->_x * $k->getX(), 'y' => $this->_y * $k->getY(), 'z' => $this->z * $k->getZ())));
	}

	public function cos($rhs) {
		return ($this->dotProduct($rhs) / ($this->magnitude() * $rhs->magnitude()));
	}

	public function crossProduct($rhs) {
		return $this->magnitude() * $rhs->magnitude() *
	}
}
