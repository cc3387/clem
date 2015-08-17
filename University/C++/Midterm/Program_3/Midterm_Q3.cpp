#include <iostream>
#include "Midterm_Q3.h"
using namespace std;

//Method definitions in Header files

Point::Point(){
cout<<"This is Default Constructor"<<endl;
x = new int;
y = new int;

*x=0;
*y=0;

}


Point::Point(int a, int b){
cout<<"This is Parametarized Constructor"<<endl;
x = new int;
y = new int;

*x=a;
*y=b;
}


Point::Point(const Point &p){
cout<<"This is the Copy Constructor"<<endl;
x = new int;
y = new int;

*x=*p.x;
*y=*p.y;
}

void Point::reset_location(int value_x, int value_y){
x = new int;
y = new int;
	
*x=value_x;
*y=value_y;
}

void Point::move(int delta_x, int delta_y){
*x += delta_x;
*y += delta_y;
}

void Point::set(int a, int b){
*x = a;
*y = b;
}


int Point::getX(){
return *x;
}

int Point::getX() const{
return *x;
}

int Point::getY(){
return *y;
}

int Point::getY() const{
return *y;
}

void Point::pass_x(){
cout << *x << endl;
}

void Reverse(Point &p1, Point p2){
p1.pass_x();
cout<<p2.getY()<<endl;
}



Point::~Point(){
cout<<"Here is the destructor." << endl;
delete[] x;
delete[] y;
}



int main(){

	const int Size = 5;
	Point P1,P2(3,4);
	const Point P3(10,4);
	P2.move(5,10);
	cout<<"After moving 5 units, P2's x value is: " << P2.getX()<<endl;
    cout<<"P3's y value is: "<< P3.getY() <<endl;
	//Getting the array of straight Line
	Point PointArray[5];
	for(int i = 0; i < Size; i++){
	PointArray[i].set(1,i);
	cout<<"The x value is: " << PointArray[i].getX()<<" The y value is: " <<PointArray[i].getY() << endl;
	}
	//Reverse Function
	Reverse(P1,P2);

}