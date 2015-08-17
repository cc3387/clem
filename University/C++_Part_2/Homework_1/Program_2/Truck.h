#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Vehicle.h"

class Truck : public Vehicle{

protected:
	  double load_capacity;
	  int towing_capacity;

public:
	  Truck(); //Default Constructor
	  Truck(std::string themanufactname, int thenumofcylinders, double theloadcapacity, int thetowingcapacity); //Parameterized Constructor
	  Truck(const Truck& T); // Copy Constructors
	  
	  //Setter
	  void setloadcap(double theloadcap);
	  void settowingcap(int thetowingcap);
	  
	  //Getter
	  double getloadcap() const;
	  int gettowingcap() const;
	  	  
	  //Print details and operator overloading
	  void printTruckDetails(const Person &P);
	  Truck& operator = (const Truck& rhs);

};

#endif

