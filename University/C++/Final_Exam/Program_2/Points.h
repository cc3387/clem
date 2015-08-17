#include <iostream>
#include <cmath>
using namespace std;

class Point{

private:
	int *x;
	int *y;
	int *distance;
	
public:

	//Constructors and Destructors

	Point(); //Default Constructor
	Point(int, int); //Parametric Constructor
	Point(const Point &p); //Copy Constructor
	~Point(); //Destructor
	
	//Mutators and Accessors
	void reset_location(int, int);
	void set_distance(int);
	int getX() const;
	int getY() const;
	int getdistance() const;

	//Operator Overloading
	Point &operator = (const Point &p);
	Point operator - (Point &p); 
	bool operator == (const Point &p);
	Point operator * (const int scale);
	friend const Point operator *(const int scale, const Point &P);
	friend ostream &operator << (ostream &out, const Point &rhs);

};