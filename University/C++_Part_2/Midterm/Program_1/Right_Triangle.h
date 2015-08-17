#ifndef RTriangle_H
#define RTriangle_H

#include "Shape.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

class RTriangle : public Shape{

private:
	double Base;
	double Height;

public:

	RTriangle(); //Default Constructors
	RTriangle(double, double, int, int); //Parameterized Constructor that sets radius
	RTriangle(double, double, int, int, int);
	~RTriangle(); //Destructor
	RTriangle(const RTriangle &rhs);
	RTriangle &operator = (const RTriangle &rhs);

	//Setters and Getters
	float CalcArea();
	void DrawObject();
	double getBase() const;
	double getHeight() const;
	void setbase_height(double, double);


	RTriangle &operator *(double scalar);
	friend const RTriangle operator *(const RTriangle &rtri, const double scalar);
	friend const RTriangle  operator *(const double scalar,const RTriangle &rtri);

};

#endif