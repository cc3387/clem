#include "Doughnut.h"

Doughnut :: Doughnut(double the_radius, double the_radius_1, int the_x, int the_y) : Circle(the_radius, the_x , the_y), radius1(the_radius_1){
std::cout << "This is Doughnut Constructor ... " << std::endl;
std::cout << " " << std::endl;
setshapetype("Doughnut");
//Left out static shape counter because circle already initialized the shape
}

Doughnut :: Doughnut(double the_radius, double the_radius_1, int the_x, int the_y, int the_color_code, int the_color_code_2) : Circle(the_radius, the_x , the_y, the_color_code), radius1(the_radius_1), color_2(the_color_code_2){
std::cout << "This is Doughnut Constructor ... " << std::endl;
std::cout << " " << std::endl;
setshapetype("Doughnut");
//Left out static shape counter because circle already initialized the shape
}



//Copy Constructor
Doughnut :: Doughnut(const Doughnut &rhs){
radius = rhs.getRadius1();
radius1  = rhs.getRadius2();
Area = rhs.getArea();
X = rhs.getX();
Y = rhs.getY();
}

//Assignment Operator
Doughnut &Doughnut :: operator = (const Doughnut &rhs){
radius = rhs.getRadius1();
radius1  = rhs.getRadius2();
Area = rhs.getArea();
X = rhs.getX();
Y = rhs.getY();
return *this;
}

//Destructor
Doughnut :: ~Doughnut(){
std::cout << "This is Doughnut Destructor ... " << std::endl;
}

void Doughnut :: set_radius(double rad, double rad1){
radius = rad;
radius1 = rad1;
}


//Setting Method for virtual class
double Doughnut :: getRadius1() const{
return radius;
}

double Doughnut :: getRadius2() const{
return radius1;
}

float Doughnut :: CalcArea(){
float pi = 3.14159265359;
Area = (pi * radius1 * radius1) - (pi * radius * radius);
return Area;
}

void Doughnut :: DrawObject(){
std::cout << "Drawing : " << shapetype << std::endl;
}


//Scaled Shape Operator
Doughnut &Doughnut :: operator *(double scalar){
float pi = 3.14159265359;
radius *= scalar;
radius1 *= scalar;
Area = (pi * radius1 * radius1) - (pi * radius * radius); //The Scalar only changes radius. When multiplied, the area should show changes
return *this;
}

const Doughnut operator *(const Doughnut &DN, const double scalar){
Doughnut DN1 = DN;
float pi = 3.14159265359;
DN1.radius = scalar * DN.radius;
DN1.radius1 = scalar * DN.radius1;
DN1.Area = (pi * DN1.radius1 * DN1.radius1) - (pi * DN1.radius * DN1.radius); //The Scalar only changes radius. When multiplied, the area should show changes
return DN1;
}

const Doughnut operator *(const double scalar, const Doughnut &DN){
Doughnut DN1 = DN;
float pi = 3.14159265359;
DN1.radius = scalar * DN.radius;
DN1.radius1 = scalar * DN.radius1;
DN1.Area = (pi * DN1.radius1 * DN1.radius1) - (pi * DN1.radius * DN1.radius); //The Scalar only changes radius. When multiplied, the area should show changes
return DN1;
}
