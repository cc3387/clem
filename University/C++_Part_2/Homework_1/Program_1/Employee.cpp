#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using std::cout;

namespace SavitchEmployees
{
	Employee::Employee() : name("No name yet"), ssn("No number yet"), netPay(0)
	{
	//deliberately empty
	}

	Employee::Employee(std::string theName, std::string theNumber) : name(theName), ssn(theNumber), netPay(0)
	{
	//deliberately empty
	}

	std::string Employee::getName() const
	{
	return name;
	}

	std::string Employee::getSsn() const
	{
	return ssn;
	}

	double Employee::getNetPay() const
	{
	return netPay;
	}

	void Employee::setName(std::string newName)
	{
	name = newName;
	}

	void Employee::setSsn(std::string newSsn){
	ssn = newSsn;
	}

	void Employee::setNetPay(double newNetPay){
	netPay = newNetPay;
	}

	void Employee::printCheck()const{
	cout<<"\nERROR: printCheck function called for an \n"
		<<"Undifferentiated employee. Aborting the program. \n"
		<<"Check with the author of the progress about this bug.\n";
	exit(1);
	}
}