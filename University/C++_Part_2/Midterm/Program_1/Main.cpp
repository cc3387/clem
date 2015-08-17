#include "Shape.h"
#include "Circle.h"
#include "Right_Triangle.h"
#include "Doughnut.h"

void SortShape(Shape *arr[], int NumShapes){
	
	std::cout<<"Sorting Objects ... "<< std::endl;
	std::cout<<" "<< std::endl;
	//Recalculate the area after the settings
	for(int i = 0; i < NumShapes; i++){
	arr[i] -> CalcArea();
	}

	for(int i = 1; i < NumShapes; i++){
	   
	   Shape *temp = arr[i];
	   int j = i;
	
	   while(j > 0 && arr[j-1]->getArea() > temp -> getArea()){
	   arr[j] = arr[j-1];
	   j--;
	   arr[j] = temp;
	   }
	}
}

void printsortshape(Shape *arr[], int NumShapes){
	 
	 std::cout << "Sorted Shape order is: " << std::endl;
	 for(int i=0; i<NumShapes; i++){
	 arr[i] -> DrawObject();
	 arr[i] -> ShowColor();
	 std::cout << "The X location is: " << arr[i] -> getX() << std::endl;
	 std::cout << "The Y location is: " << arr[i] -> getY() << std::endl;
	 std::cout << "The Sorted Object's Area is: " << arr[i] -> getArea() << std::endl;
	 std::cout << " " << std::endl;
	 }
	 std::cout << " " << std::endl;
};

//Global Function for GetDistance

float getDistance(Shape *S1, Shape *S2){

	  float dist;
	  dist = sqrt((S1->getX() - S2->getX())*(S1->getX() - S2->getX()) - (S1->getY() - S2->getY()));
	  return dist;
}

int main(){

//Creating 6 derived classes 
int N = 6;

Circle circ(5,30,30,3), circ1(10,50,50,1);
RTriangle RTri(5,10, 150, 150,5), RTri1(10,20, 100, 100,1), RTri2(10, 5, 250, 250,6);
Doughnut DN(5,10,40,70,3,1);


Shape *shapeptr[N]; 
shapeptr[0] = &circ;
shapeptr[1] = &circ1;
shapeptr[2] = &RTri;
shapeptr[3] = &RTri1;
shapeptr[4] = &RTri2;
shapeptr[5] = &DN;

//Show the total shapes being developed using static variable
shapeptr[1]-> displaytotalshapecount();


//Display all the shapes' information
for (int i=0; i < 6; i++){

if (i < 2 || i > 4){
std::cout << "************************This is Shape Number: " << i + 1 << "**************************" << std::endl;
Shape *temp = shapeptr[i];
temp -> CalcArea();
temp -> DrawObject();
std::cout << "The X location is: " << temp -> getX() << std::endl;
std::cout << "The Y location is: " << temp -> getY() << std::endl;

//Use Dynamic Casting to Find Radius, which is information in the derived class
if(i == 0){
Shape *temp1;
temp1 = new Circle(5,30,30,3);
Circle *circptr = dynamic_cast<Circle*>(temp1);
std::cout << "The Radius of the Circle is: " << circptr -> getRadius() << std::endl;
}

else if(i == 1){
Shape *temp1;
temp1 = new Circle(10,50,50,1);
Circle *circptr = dynamic_cast<Circle*>(temp1);
std::cout << "The Radius of the Circle is: " << circptr -> getRadius() << std::endl;
}

else if(i == 5){
Shape *temp1;
temp1 = new Doughnut(5,10,40,70);
Doughnut *DNptr = dynamic_cast<Doughnut*>(temp1);
std::cout << "The Radius of the smaller circle in Doughnut is: " << DNptr -> getRadius1() << std::endl;
std::cout << "The Radius of the larger circle in Doughnut is: " << DNptr -> getRadius2() << std::endl;
}

temp -> ShowColor();
std::cout << "The Area of the Pointed Shape is: " << temp ->getArea()<<std::endl;
std::cout << " " << std::endl;;
}

else{
std::cout << "************************This is Shape Number: " << i + 1 << "**************************" << std::endl;
Shape *temp = shapeptr[i];
temp -> CalcArea();
temp ->DrawObject();
std::cout << "The X location is: " << temp -> getX() << std::endl;
std::cout << "The Y location is: " << temp -> getY() << std::endl;

if(i == 2){
Shape *temp1;
temp1 = new RTriangle(5,10, 150, 150);
RTriangle *rtriptr = dynamic_cast<RTriangle*>(temp1);
std::cout << "The Base of the Right Triangle is: " << rtriptr -> getBase() << std::endl;
std::cout << "The Height of the Right Triangle is: " << rtriptr ->getHeight() << std::endl;
}
else if(i == 3){
Shape *temp1;
temp1 = new RTriangle(10,20, 100, 100);
RTriangle *rtriptr = dynamic_cast<RTriangle*>(temp1);
std::cout << "The Base of the Right Triangle is: " << rtriptr -> getBase() << std::endl;
std::cout << "The Height of the Right Triangle is: " << rtriptr -> getHeight() << std::endl;
}

else if(i == 4){
Shape *temp1;
temp1 = new RTriangle(10, 5, 250, 250);
RTriangle *rtriptr = dynamic_cast<RTriangle*>(temp1);
std::cout << "The Base of the Right Triangle is: " << rtriptr -> getBase() << std::endl;
std::cout << "The Height of the Right Triangle is: " << rtriptr -> getHeight() << std::endl;
}

temp -> ShowColor();
std::cout << "The Area of the Pointed Shape is: " << temp ->getArea()<<std::endl;
std::cout << " " << std::endl;
}
}


std::cout << "*****************************************************************************" << std::endl;

//Testing the multiplication functions
Circle circ3 = circ * 2;
Shape *circtemp = &circ3;
std::cout << "The scaled circle is: " << circtemp -> getArea() << std::endl;
std::cout << " " << std::endl;
circ.setradius(5);

Circle circ4 = 2 * circ;
circtemp = &circ4;
std::cout << "The scaled circle is: " << circtemp -> getArea() << std::endl;
std::cout << " " << std::endl;
circ.setradius(5);

RTriangle RTri3 = RTri * 2;
Shape *tritemp = &RTri3;
std::cout << "The scaled Triangle is: " << tritemp-> getArea() << std::endl;
std::cout << " " << std::endl;
RTri.setbase_height(5,10);

RTriangle RTri4 = 2 * RTri;
tritemp = &RTri4;
std::cout << "The scaled Triangle is: " << tritemp-> getArea() << std::endl;
std::cout << " " << std::endl;
RTri.setbase_height(5,10);

Doughnut DN2 = DN * 2;
Shape *DNtemp = &DN2;
std::cout << "The scaled Dougnut is: " << DNtemp-> getArea() << std::endl;
std::cout << " " << std::endl;
DN.set_radius(5,10);


Doughnut DN3 = 2 * DN;
DNtemp = &DN3;
std::cout << "The scaled Doughnut is: " << DNtemp-> getArea() << std::endl;
std::cout << " " << std::endl;
DN.set_radius(5,10);


std::cout << "*************************************** Question 17-18 *************************************" << std::endl;

/************************************************************************************/
//Question 17-18

//Sorting the last base on area;
SortShape(shapeptr, N);
printsortshape(shapeptr, N);

std::cout << "********************************* Question 19-20 *******************************" << std::endl;

std::cout << "The distance between Circle 1 and Circle 2 is: " << getDistance(shapeptr[2], shapeptr[5]) << std::endl;
std::cout << " " << std::endl;
std::cout << "The distance between Circle 1 and Right Triangle is: " << getDistance(shapeptr[2], shapeptr[0]) << std::endl;
std::cout << " " << std::endl;

float dist = shapeptr[0]->get_distance(shapeptr[2], shapeptr[5]);
std::cout << "The distance between Circle 1 and Circle 2 using operator function is: " << dist << std::endl;
std::cout << " " << std::endl;
dist = shapeptr[0]->get_distance(shapeptr[2], shapeptr[0]);
std::cout << "The distance between Circle 1 and Right Triangle using operator function is: " << dist << std::endl;
std::cout << " " << std::endl;

return 0;
}