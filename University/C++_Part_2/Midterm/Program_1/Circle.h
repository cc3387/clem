#ifndef Circle_H
#define Circle_H

#include "Shape.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

class Circle : public Shape{

protected:

	double radius; //Only Circle has Radius

public:

	Circle(); //Default Constructors
	Circle(double, int, int); //Parameterized Constructor that sets radius without color
	Circle(double, int, int, int); //Parameterized Constructor that sets radius with color
	~Circle(); //Destructor
	Circle(const Circle &rhs);
	Circle &operator = (const Circle &rhs);

	//Setters and Getters
	float CalcArea();
	void DrawObject();
	double getRadius() const;
	void setradius(double);

	//Operator Overloading with '*' to Scale the size
	Circle &operator *(double scalar);
	friend const Circle operator *(const Circle &circ, const double scalar);
	friend const Circle operator *(const double scalar,const Circle &circ);
};

#endif