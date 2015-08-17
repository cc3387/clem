class Point{

private:
	int *x;
	int *y;
	
public:
	Point(); //Default Constructor
	Point(int, int); //Parametric Constructor
	Point(const Point &p); //Copy Constructor
	~Point(); //Destructor
	void reset_location(int, int);
	void move(int, int);
	void set(int, int);
	int getX();
	int getX() const;
	int getY();
	int getY() const;
	void pass_x(); //For void Reverse use later on
};