#include <string>
#include <cstdlib>
#include <iostream>
#include "SalariedEmployee.h"

namespace SavitchEmployees
{
	SalariedEmployee::SalariedEmployee() : Employee(), salary(0)
	{
	//deliberately empty
	}

	SalariedEmployee::SalariedEmployee(std::string theName, std::string theNumber) : Employee(theName, theNumber)
	{
	//deliberately empty
	}
	
	SalariedEmployee::SalariedEmployee(std::string theName, std::string theNumber, double theWeeklySalary) : Employee(theName, theNumber), salary(theWeeklySalary)
	{
	//deliberately empty
	}

	double SalariedEmployee::getSalary() const
	{
	return salary;
	}

	void SalariedEmployee::setSalary(double newSalary)
	{
	salary = newSalary;
	}

	void SalariedEmployee::printCheck(){
	setNetPay(salary);
	std::cout<< "\n____________________________________\n";
	std::cout<< "Pay to the order of " << getName() << std::endl;
	std::cout<< "The sum of " << getNetPay() << " Dollars\n" ;
	std::cout<< "____________________________________\n";
	std::cout<< "Check Stub Not Negotiable \n";
	std::cout<< "Employee Number: " << getSsn() << std::endl;
	std::cout<< "Salaried Employee. Regular Pay: " << getSalary() << std::endl;
	std::cout<< "____________________________________\n";
	std::cout<< "\n";
	}
}