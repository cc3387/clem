#include "Circle.h"

Circle :: Circle(){
std::cout << "This is Circle Constructor ... " << std::endl;
std::cout << " " << std::endl;
radius = 0;
setX(0);
setY(0);
setshapetype("Circle");
shapecount += 1;
}

Circle :: Circle(double r, int x, int y){
std::cout << "This is Circle Constructor ... " << std::endl;
std::cout << " " << std::endl;
radius = r;
setX(x);
setY(y);
setshapetype("Circle");
shapecount += 1;
}

Circle :: Circle(double r, int x, int y, int color_code){
std::cout << "This is Circle Constructor ... " << std::endl;
std::cout << " " << std::endl;
radius = r;
setColor(color_code);
setX(x);
setY(y);
setshapetype("Circle");
shapecount += 1;
}

//Copy Constructor
Circle :: Circle(const Circle &rhs){
radius = rhs.getRadius();
Area = rhs.getArea();
X = rhs.getX();
Y = rhs.getY();
}

//Assignment Operator
Circle &Circle :: operator = (const Circle &rhs){
radius = rhs.getRadius();
Area = rhs.getArea();
X = rhs.getX();
Y = rhs.getY();
return *this;
}

//Destructor
Circle :: ~Circle(){
std::cout << "This is Circle Destructor ... " << std::endl;
}

//Setting Method for virtual class
double Circle :: getRadius() const{
return radius;
}

float Circle :: CalcArea(){
float pi = 3.14159265359;
Area = pi * radius * radius;
return pi * radius * radius;
}

void Circle :: DrawObject(){
std::cout << "Drawing : " << shapetype << std::endl;
}


void Circle :: setradius(double rad){
radius = rad;
}

//Scaled Shape Operator
Circle &Circle :: operator *(double scalar){
float pi = 3.14159265359;
radius *= scalar;
Area = pi * radius * radius; //The Scalar only changes radius. When multiplied, the area should show changes
return *this;
}

const Circle operator *(const Circle &circ, const double scalar){
Circle circ1 = circ;
float pi = 3.14159265359;
circ1.radius = scalar * circ.radius;
circ1.Area = pi * circ1.radius * circ1.radius; //The Scalar only changes radius. When multiplied, the area should show changes
return circ1;
}

const Circle operator *(const double scalar, const Circle &circ){
Circle circ1 = circ;
float pi = 3.14159265359;
circ1.radius = scalar * circ.radius;
circ1.Area = pi * circ1.radius * circ1.radius; //The Scalar only changes radius. When multiplied, the area should show changes
return circ1;
}
