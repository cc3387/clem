#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

class Shape{

protected:

	int X; 
	int Y;
	int color;
	enum color{Red, Orange, Yellow, Green, Blue, Indigo, Violet};
	float Area;
	std::string shapetype;	
	
public:
	Shape(); //Default Constructor
	~Shape(); // Default Destructor
	static int shapecount; //Shape counters

	//Setters, Getters and 
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
	void displaytotalshapecount();
	void setshapetype(std::string shape);
	void setColor(int);

	//Virtual Functions
	virtual float CalcArea() = 0; 
	virtual void DrawObject(); 
	
	//Other Functions for Color Settings etc
	void ResetLocation(int, int);
	void ShowColor() const;
	float getArea() const;

	//Overloading operator to calculate distance
	float get_distance(const Shape *rhs, const Shape *lhs);
};

#endif