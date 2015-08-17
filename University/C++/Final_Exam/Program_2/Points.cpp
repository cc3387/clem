#include "Points.h"

//Method definitions in Header files

Point::Point(){
cout<<"This is Default Constructor"<<endl;
x = new int;
y = new int;
distance = new int;

*x=0;
*y=0;
*distance=0;

}


Point::Point(int a, int b){
cout<<"This is Parametarized Constructor"<<endl;
x = new int;
y = new int;
distance = new int;

*x=a;
*y=b;
*distance=0;
}


Point::Point(const Point &p){
cout<<"This is the Copy Constructor"<<endl;
x = new int;
y = new int;
distance = new int;

*x= *p.x;
*y= *p.y;
*distance = *p.distance;
}

void Point::reset_location(int value_x, int value_y){
*x=value_x;
*y=value_y;
}

void Point::set_distance(int dist){
*distance = dist;
}

int Point::getX() const{
return *x;
}


int Point::getY() const{
return *y;
}

int Point::getdistance()const{
return *distance;
}

Point::~Point(){
cout<<"Here is the destructor." << endl;
delete[] x;
delete[] y;
delete[] distance;
}


/***********************Operator Overload *******************************/

//Assignment Operator
Point &Point::operator=(const Point &p){
if(this != &p){
reset_location(p.getX(), p.getY());
set_distance(p.getdistance());
}
return *this;
}

//Boolean Operator
bool Point::operator==(const Point &p){
return true; 
}

Point Point::operator-(Point &p){
Point P = *this;
*P.x = P.getX()*p.getX();
*P.y = P.getY()*p.getY();
*P.distance = int(sqrt(*P.x + *P.y));
return P;
}

Point Point::operator*(const int scale){
Point P = *this;
*P.x *= scale;
*P.y *= scale;
P.reset_location(*P.x, *P.y);
return P;
}

const Point operator*(const int scale, const Point &P){
*P.x *= scale;
*P.y *= scale;
return P;
}


ostream &operator << (ostream &out, const Point &rhs){

out << "The x coordinate of X is: ";
out << rhs.getX() << endl;
out << "The y coordinate of X is: ";
out << rhs.getY() << endl;
out << "The distance is: ";
out << rhs.getdistance() << endl;

return out;
}


void foo(Point &p, Point p1){

int x = p.getX();
int y = p1.getY();

Point temp(x,y);

cout << "x coordinate from Point X is:" << temp.getX()<< endl;
cout << "y coordinate from Point Y is:" << temp.getY()<< endl;
}




/********************* Main class to display ******************/

int main(){

Point X(3,4), Y(10,40), Z, K;
int distance = (X-Y).getdistance();
cout<<"The distance between X and Y is: " <<distance<<endl;

X.reset_location(3,4);
Z = 10 * X;
cout << "X coordinate of 10*X is: " << Z.getX() << endl;
cout << "Y coordinate of 10*X is: " << Z.getY() << endl;

X.reset_location(3,4);
Z = X*10;
cout << "X coordinate of X*10 is: " << Z.getX() << endl;
cout << "Y coordinate of X*10 is: " << Z.getY() << endl;

X.reset_location(3,4);
int x = X.getX();
int y = X.getY();
cout << "x coordinate in X is: " << x << endl;
cout << "y coordinate in Y is: " << y << endl;

cout << X;
Z = X-Y;
cout << Z;


//Use foo to display the combinations of coordinates
foo(X,Y);



return 0;


}