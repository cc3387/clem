#include "Shape.h"

Shape :: Shape(){
std::cout << "This is Shape Default Constructor ... " << std::endl;
X = 0;
Y = 0; 
Area = 0;
shapetype = "Shape" ;
}

Shape :: ~Shape(){
std::cout << "This is Shape Default Destructor ... " << std::endl;
}


void Shape :: setX(int deltaX){
X = deltaX;
}

void Shape :: setY(int deltaY){
Y = deltaY;
}

void Shape :: setshapetype(std::string shape){
shapetype = shape;
}

int Shape :: getX() const{
return X;
}

int Shape :: getY() const{
return Y;
}

//Shape and reset location
void Shape :: ResetLocation(int deltaX, int deltaY){
X = deltaX;
Y = deltaY;
}

float Shape :: getArea()const {
return Area;
}


void Shape :: DrawObject(){
std::cout << "Drawing : " << shapetype << std::endl;
}


//Setting the static shape count to 0;
int Shape :: shapecount = 0;

void Shape :: displaytotalshapecount(){
std::cout <<"The number of shapes created is: " << shapecount << std::endl;
std::cout << " " << std::endl;
}

//Setting color code
void Shape :: setColor (int i){
color = i;
}

void Shape :: ShowColor()const{

	if(color == 0){
	std::cout << "The Color of Shape is Red." << std::endl;
	}
	else if(color == 1){
	std::cout << "The Color of Shape is Orange." << std::endl;
	}
	else if(color == 2){
	std::cout << "The Color of Shape is Yellow." << std::endl;
	}
	else if(color == 3){
	std::cout << "The Color of Shape is Green." << std::endl;
	}
	else if(color == 4){
	std::cout << "The Color of Shape is Blue." << std::endl;
	}
	else if(color == 5){
	std::cout << "The Color of Shape is Indigo." << std::endl;
	}
	else if(color == 6){
	std::cout << "The Color of Shape is Violet." << std::endl;
	}
	else{
	std::cout << "Color Not Set." << std::endl;
	}
}

float Shape :: get_distance(const Shape *S1, const Shape *S2){
return sqrt((S1->getX() - S2->getX())*(S1->getX() - S2->getX()) - (S1->getY() - S2->getY()));
}