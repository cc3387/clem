#include "Vehicle.h"

Vehicle::Vehicle(): manufact_name("No_Name_yet"), number_of_cylinders(0){
//Constructor, Empty
}

Vehicle::Vehicle(std::string themanufactname, int thenumofcylinders): manufact_name(themanufactname), number_of_cylinders(thenumofcylinders){
//Parameterized Constructor, Empty
}

std::string Vehicle::getownerName(const Person &P) const{
	return P.getName();
}

void Vehicle::set_manufact_name(std::string manufactory_name){
manufact_name = manufactory_name;
}

std::string Vehicle::get_manufact_name() const{
return manufact_name;
}

void Vehicle::set_number_of_cylinders(int num_cylinders){
number_of_cylinders = num_cylinders;
}

int Vehicle::get_num_of_cylinders() const{
return number_of_cylinders;
}