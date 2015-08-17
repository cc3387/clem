#include <string>
#include <iostream>

class Shape{

protected:
	double height;
	double width;
	double base;
	double radius;
	double side;

public:
	virtual double Area() = 0;
};


class Square : public Shape{
public:

	void set_side(double a){
	side = a;
	};

	double Area(){
	return side * side;
	};

};


class Circle : public Shape{

public:
	
	void set_radius(double r){
	radius = r;
	};

	double Area(){
	return 3.14159265*radius*radius;
	};

};

class Triangle : public Shape{

public:
	
	void set_bh(double b, double h){
	base = b;
	height = h;
	};

	double Area(){
	return (base*height/2);
	};

};

class Rectangle : public Shape{
public:

	void set_side(double h, double w){
	height = h;
	width = w;
	};

	double Area(){
	return height * width;
	};

};