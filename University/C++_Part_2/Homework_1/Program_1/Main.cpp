#include "Employee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
using namespace SavitchEmployees;

int main(){
	
	//Check out with Employee and SalariedEmployee Classes
	std::string name;
	std::string SSN;
	name = "Clement Chan";
	SSN = "123";
	Employee EPE(name,SSN);
	SalariedEmployee SEPE(name, SSN, 1100);
	SEPE.printCheck();

	//Check out Administrator class
	Administrator Admin, Admin1("Clement", "1234567", "Vice President", "Accouting", "Anita", 15000);
	Admin1.print();
	Admin1.printCheck();

	//Enter functions to Check with print check
	Admin.setName();
	Admin.setAdminTitle();
	Admin.setssn();
	Admin.setSupervisor();
	Admin.setSalary();
	Admin.setResponse();
	Admin.print();
	Admin.printCheck();
	return 0;
}