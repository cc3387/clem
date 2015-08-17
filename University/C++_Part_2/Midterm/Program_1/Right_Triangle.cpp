#include "Right_Triangle.h"

RTriangle :: RTriangle(){
std::cout << "This is RTriangle Constructor ... " << std::endl;
std::cout << " " << std::endl;
Base = 0;
Height = 0;
setX(0);
setY(0);
setshapetype("RTriangle");
shapecount += 1;
}

RTriangle :: RTriangle(double b, double h, int x, int y){
std::cout << "This is RTriangle Constructor ... " << std::endl;
std::cout << " " << std::endl;
Base = b;
Height = h;
setX(x);
setY(y);
setshapetype("RTriangle");
shapecount += 1;
}

RTriangle :: RTriangle(double b, double h, int x, int y, int color_code){
std::cout << "This is RTriangle Constructor ... " << std::endl;
std::cout << " " << std::endl;
Base = b;
Height = h;
setColor(color_code);
setX(x);
setY(y);
setshapetype("RTriangle");
shapecount += 1;
}


//Copy Constructor
RTriangle :: RTriangle(const RTriangle &rhs){
Base = rhs.getBase();
Height = rhs.getHeight();
Area = rhs.getArea();
X = rhs.getX();
Y = rhs.getY();
}

//Assignment Operator
RTriangle &RTriangle :: operator = (const RTriangle &rhs){
Base = rhs.getBase();
Height = rhs.getHeight();
Area = rhs.getArea();
X = rhs.getX();
Y = rhs.getY();
return *this;
}

//Destructor
RTriangle :: ~RTriangle(){
std::cout << "This is RTriangle Destructor ... " << std::endl;
}

//Setting Method for virtual class
double RTriangle :: getBase()  const{
return Base;
}

double RTriangle :: getHeight()  const{
return Height;
}

float RTriangle :: CalcArea(){
Area = (Base * Height)/2;
return Area;
}

void RTriangle :: DrawObject(){
std::cout << "Drawing : " << shapetype << std::endl;
}

void RTriangle :: setbase_height (double b, double h){
Base = b;
Height = h;
}


//Scaled Shape Operator
RTriangle &RTriangle :: operator *(double scalar){
Base*= scalar;
Height *= scalar;
Area = (Base * Height)/2;
return *this;
}

const RTriangle operator *(const RTriangle &RTri, const double scalar){
RTriangle RTri1 = RTri;
RTri1.Base = scalar * RTri.Base;
RTri1.Height = scalar * RTri.Height;
RTri1.Area = (RTri1.Base * RTri1.Height) / 2; 
return RTri1;
}

const RTriangle operator *(const double scalar, const RTriangle &RTri){
RTriangle RTri1 = RTri;
RTri1.Base = scalar * RTri.Base;
RTri1.Height = scalar * RTri.Height;
RTri1.Area = (RTri1.Base * RTri1.Height) / 2;
return RTri1;
}