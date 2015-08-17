#include "Truck.h"

Truck::Truck() : Vehicle(), load_capacity(0), towing_capacity(0){
//Default Constructors
}

Truck::Truck(std::string themanufactname, int thenumofcylinders, double theloadcapacity, int thetowingcapacity) : Vehicle(themanufactname, thenumofcylinders), load_capacity(theloadcapacity), towing_capacity(thetowingcapacity){
//Parameterized Constructors
}

Truck::Truck(const Truck& T){
	  //Copy Constructors
      manufact_name = T.get_manufact_name();
	  number_of_cylinders = T.get_num_of_cylinders();
	  load_capacity = T.getloadcap();
	  towing_capacity = T.gettowingcap();
}

//Operator "=" overloading
Truck& Truck::operator = (const Truck& rhs){
	  manufact_name = rhs.get_manufact_name();
	  number_of_cylinders = rhs.get_num_of_cylinders();
	  load_capacity = rhs.getloadcap();
	  towing_capacity = rhs.gettowingcap();
	  return *this;
}

//Setter
void Truck :: setloadcap(double theloadcap){
load_capacity = theloadcap;
}

void Truck :: settowingcap(int thetowingcap){
towing_capacity = thetowingcap;
}

//Getter
double Truck :: getloadcap() const{
return load_capacity;
}

int Truck :: gettowingcap() const{
return towing_capacity;
}

void Truck :: printTruckDetails(const Person &P){
std::cout << "---------------- Truck Information And Output -----------------------" << std::endl;
std::cout << "The Owner of the Truck is: " << getownerName(P)<< std::endl;
std::cout << "The Truck's Manufacturer is: " << get_manufact_name() << std::endl;
std::cout << "The number of cylinders of the Truck is: " << get_num_of_cylinders() << std::endl;
std::cout << "The loading capacity of the Truck is: " << getloadcap() << std::endl;
std::cout << "The towing capacity of the Truck is: " << gettowingcap() << std::endl;
std::cout << "---------------------------------------------------------------------" << std::endl;
}