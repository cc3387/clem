//Method Class for Point class
#include "Person.h"

Person :: Person() : Point(), name("No Name Yet"), age(0){
std::cout << "This is Default Constructor ... " <<std::endl;
}

//Parameterized Constructor with just name and age
Person:: Person(char* the_name, int the_age) : name(the_name), age(the_age){
std::cout << "This is Parameterized Constructor (name and age only) ... " <<std::endl;
}


//Setting information using inheritance
Person:: Person(char* the_name, int the_age, int the_X, int the_Y) : Point(the_X, the_Y), name(the_name), age(the_age){
std::cout << "This is Parameterized Constructor (all) ... " <<std::endl;
}

Person:: ~Person(){
std::cout << "This is Destructor..." << std::endl;
}

//Setters and Getters Method

char* Person::getname() const{
return name;
}

int Person::getage() const{
return age;
}	

void Person :: gps_setloc(int X, int Y){
gps_loc.reset_location(X,Y);
}

int Person :: get_gps_X()const{
return gps_loc.getX();
}

int Person :: get_gps_Y()const{
return gps_loc.getY();
}

double Person :: get_distance(const Person &rhs, const Person &lhs){
double dist;
dist = sqrt((rhs.get_gps_X() - lhs.get_gps_X())*(rhs.get_gps_X() - lhs.get_gps_X()) + (rhs.get_gps_Y() - lhs.get_gps_Y())*(rhs.get_gps_Y() - lhs.get_gps_Y()));
return dist;
}