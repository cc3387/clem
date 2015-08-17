#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Vector2D{

private:

	int **xycoord;
	int dot_product;
	int max_size;

public:
	Vector2D();
	Vector2D(int,int);
	void init_vector(int);
	void set_x();
	void set_y();
	int get_x(int) const;
	int get_y(int) const;
	int get_maxsize() const;
	int get_dot_product() const;

	//Operator Overloading
	friend const Vector2D operator *(const Vector2D &rhs, const Vector2D &lhs); 

	//Destructor
	~Vector2D();
};