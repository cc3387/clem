#ifndef Point_H
#define Point_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point{

protected:

	int x;
	int y;
	double distance;

public:
	Point(); //Default Constructor
	Point(int, int); //Parameterized Constructor
	Point(const Point &rhs); //Copy Constructor
	~Point(); //Destructor
	Point &operator =(const Point &rhs); //Assignment Operator
	Point &operator == (const Point &rhs); 
	
	//Setters and Getters	
	void reset_location(int,int);
	int getX() const;
	int getY() const;
	double getdistance() const;
		
	Point &operator*(int scalar); //To Perform Point * scalar
	friend const Point operator *(const int scalar, const Point &P); //To Perform Scalar * Point
	friend double operator-(const Point &rhs, const Point &lhs); //Distance between Points
	friend ostream &operator << (ostream &Oustream, const Point &P);
};

#endif