#include "Person.h"
#include "Truck.h"

int main(){
    
	Vehicle V;
	
	//Entering Truck's detail
	Truck T("Honda", 15, 1000, 1500);
	Truck T1;
	
	//Setting Vehicle's detail
	V.set_number_of_cylinders(10);
	V.set_manufact_name("Toyota");
	
	//Enterting Person's information
	Person P;
	std::cin >> P;

	//Getting information from Vehicle
	std::cout << "The owner's name is: " << V.getownerName(P) << std::endl;
	std::cout << "The Manufacturer name is: " << V.get_manufact_name() << std::endl;
	std::cout << "The number of cylinders is: " << V.get_num_of_cylinders() << std::endl;
	
	//Getting information from Trucks
	T.printTruckDetails(P);	
	
	//Testing operator "="
	T1 = T;
	T1.printTruckDetails(P);


	return 0;
}