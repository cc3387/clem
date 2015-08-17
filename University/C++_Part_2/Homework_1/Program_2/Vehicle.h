#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Person.h"

class Vehicle{

protected:
	  std::string manufact_name;
	  int number_of_cylinders;
	  Person Owner;
public:
	  Vehicle();
	  Vehicle(std::string themanufactname, int thenumofcylinders);
	  std::string getownerName(const Person &P) const;
	  
	  //Setter and Getter for manufacturer_name
	  void set_manufact_name(std::string manufactory_name);
	  std::string get_manufact_name() const;

	  //Setter and Getter for number of cylinders
	  void set_number_of_cylinders(int num_cylinders);
	  int get_num_of_cylinders() const;
};




#endif

