#ifndef Doughnut_H
#define Doughnut_H

#include "Circle.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

class Doughnut : public Circle{

protected:

	double radius1; //Entering the Larger Radius that covers the smaller radius
	int color_2;

public:

	Doughnut(double the_radius, double the_radius_1, int the_x, int the_y); //Default Constructors
	Doughnut(double the_radius, double the_radius_1, int the_x, int the_y, int the_color_code, int the_color_code_2); //Default Constructors
	~Doughnut(); //Destructor
	Doughnut(const Doughnut &rhs);
	Doughnut &operator = (const Doughnut &rhs);

	//Setters and Getters
	float CalcArea();
	void DrawObject();
	double getRadius1() const;
	double getRadius2() const;
	void set_radius(double, double);


	Doughnut &operator *(double scalar);
	friend const Doughnut operator *(const Doughnut &circ, const double scalar);
	friend const Doughnut operator *(const double scalar,const Doughnut &circ);


};

#endif