#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
namespace SavitchEmployees
{
	class Employee
	{
	protected:
		std::string name;
		std::string ssn;
		double netPay;
		
	public:
		Employee();
		Employee(std::string theName, std::string theSsn);
		std::string getName() const;
		std::string getSsn() const;
		double getNetPay() const;
		void setName(std::string newName);
		void setSsn(std::string newSsn);
		void setNetPay(double newNetPay);
		void printCheck() const;
	};
} //SavitchEmployees

#endif

