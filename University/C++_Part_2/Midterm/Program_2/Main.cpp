#include "Point.h"
#include "Person.h"

void foo(const Point &X, const Point Y){

cout << "X coordinate in Point X is: " << X.getX() << endl;
cout << "Y coordinate in Point X is: " << X.getY() << endl;
cout << "X coordinate in Point Y is: " << Y.getX() << endl;
cout << "Y coordinate in Point Y is: " << Y.getY() << endl;

}

int main(){

	Point X(3,4), Y(10,40), Z;
	double dist = Y - X;
	cout<<"The distance between X and Y is: " << dist << endl;

	//scalar multiplier test
	Z = X * 10;
	cout<<Z;
	X.reset_location(3,4);
	Z = 10 * X;
	cout<<Z;
	X.reset_location(3,4);

	//Perform get functions
	int x = X.getX();
	int y = X.getY();

	cout<<"The X coordinate in X is: " << x << endl;
	cout<<"The Y coordinate in X is: " << y << endl;

	cout<< X << endl;

	//Passing function foo
	foo(X,Y);
	
	/*****************************Method Through Composition ************************/
	Person X1("Joe Doe", 33);
	Person Y1("Mary Joe", 22);

	X1.gps_setloc(10,15);
	Y1.gps_setloc(20,30);

	dist = X1.get_distance(X1,Y1);

	cout<< " " <<endl;
	cout<<"The name of the first person is : " << X1.getname() << " and the age is: " << X1.getage()<<endl;
	cout<<"The name of the second person is : " << Y1.getname() << " and the age is: " << Y1.getage()<<endl;
	cout<<"The distance between X1 and Y1 (Composition) is: " << dist << endl;
	cout<< " " <<endl;
	
	/*****************Method through Inheritance **************************/
	//Initializing Person
	Person X_1("Joe Doe", 33, 10,15);
	Person Y_1("Mary Joe", 22, 20, 30);

	//Finding the distance between Joe Doe and Mary Joe
	dist = Y_1 - X_1;

	cout<< " " <<endl;
	cout<<"The name of the first person is : " << X_1.getname() << " and the age is: " << X_1.getage()<<endl;
	cout<<"The name of the second person is : " << Y_1.getname() << " and the age is: " << Y_1.getage()<<endl;
	cout<<"The distance between X_1 and Y_1 (Inheritance) is: " << dist << endl;
	cout<< " " <<endl;

	return 0;

}