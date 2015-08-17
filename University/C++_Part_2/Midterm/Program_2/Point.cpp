//Method Class for Point class
#include "Point.h"

Point :: Point() : x(0), y(0){
std::cout << "This is Default Constructor ... " <<std::endl;
}

Point :: Point(int X, int Y) : x(X), y(Y){
std::cout << "This is Parameterized Constructor ... " <<std::endl;
}

Point :: Point(const Point &rhs){
x = rhs.getX();
y = rhs.getY();
}

Point &Point::operator = (const Point &rhs){

x = rhs.getX();
y = rhs.getY();

return *this;
}

Point :: ~Point(){
std::cout << "This is Destructor..." << std::endl;
}


//Setters and Getters

void Point :: reset_location(int X, int Y){
x = X;
y = Y;
}

int Point :: getX() const{
return x;
}

int Point :: getY() const{
return y;
}

double Point :: getdistance() const{
return distance;
}


Point &Point :: operator * (int scalar){
x *= scalar;
y *= scalar;
return *this;
}

const Point operator * (const int scalar, const Point &P){
Point P1 = P;
P1.x *= scalar;
P1.y *= scalar;
return P1;
}


double operator-(const Point &rhs, const Point &lhs){
double dist;
dist = sqrt((rhs.getX() - lhs.getX())*(rhs.getX() - lhs.getX()) + (rhs.getY() - lhs.getY())*(rhs.getY() - lhs.getY()));
return dist;
}

ostream& operator << (ostream &Outstream, const Point &P){
Outstream << "The X co-ordinate is: " << P.getX() <<endl;
Outstream << "The Y co-ordinate is: " << P.getY() <<endl;
return Outstream;
}

