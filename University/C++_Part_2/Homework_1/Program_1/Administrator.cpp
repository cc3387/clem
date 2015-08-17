#include <string>
#include <cstdlib>
#include <iostream>
#include "Administrator.h"

namespace SavitchEmployees
{
	Administrator::Administrator() : SalariedEmployee(), Admin_Title("No Title yet"), Response("No Response yet"), Supervisor("No Supervisor yet")
	{
	//deliberately empty
	}

	Administrator::Administrator(std::string theName, std::string theSsn, std::string theAdmin_Title, std::string theResponse, std::string theSupervisor, double thesalary) : SalariedEmployee(theName, theSsn, thesalary), Admin_Title(theAdmin_Title), Response(theResponse), Supervisor(theSupervisor)
	{
	//deliberately empty
	}

	void Administrator::setName()
	{
	std::string admin_name;
	std::cout<<"Please enter the admin's name: " << std::endl;
	std::cin >> admin_name;
	name = admin_name;
	}

	void Administrator::setSupervisor()
	{
	std::string name_supervisor;
	std::cout<<"Please enter the admin's supervisor name: " << std::endl;
	std::cin >> name_supervisor;
	Supervisor = name_supervisor;
	}

	std::string Administrator::getSupervisor()
	{
	return Supervisor;
	}

	void Administrator::setSalary()
	{
	double newSalary;
	std::cout<<"Please enter the admin's salary: " << std::endl;
	std::cin >> newSalary;
	salary = newSalary;
	}

	void Administrator::setAdminTitle()
	{
	std::string admintitle;
	std::cout<<"Please enter the admin's title: " << std::endl;
	std::cin >> admintitle;
	Admin_Title= admintitle;
	}

	std::string Administrator::getAdminTitle()
	{
	return Admin_Title;
	}

	void Administrator::setResponse()
	{
	std::string Responsibility;
	std::cout<<"Please enter the admin's responsibility: " << std::endl;
	std::cin >> Responsibility;
	Response = Responsibility;
	}

	std::string Administrator::getResponse()
	{
	return Response;
	}
	

	void Administrator::setssn()
	{
	std::string theSsn;
	std::cout<<"Please enter the admin's Ssn: " << std::endl;
	std::cin >> theSsn;
	ssn = theSsn;
	}

	void Administrator::print(){
	std::cout <<" " << std::endl;
	std::cout <<"---------------------------------Summary of Admin --------------------" << std::endl;
	std::cout <<"The Name of the Administrator is: " << getName() << std::endl;
	std::cout <<"The Name of the Supervisor is: " << getSupervisor() << std::endl;
	std::cout <<"The Admin's SSN is: " << getSsn() << std::endl;
	std::cout <<"The Name of the Admin's Salary is: " << getSalary() << std::endl;
	std::cout <<"The Name of the Admin's Title is: " << getAdminTitle() << std::endl;
	std::cout <<"The Name of the Admin's Responsibility is: " << getResponse() << std::endl;
	}

	void Administrator::printCheck(){
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