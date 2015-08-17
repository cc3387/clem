#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

namespace SavitchEmployees
{
	class SalariedEmployee : public Employee
	{
	
	protected:
		double salary; //weekly
		
	public:
		SalariedEmployee();
		SalariedEmployee(std::string theName, std::string theSsn);
		SalariedEmployee(std::string theName, std::string theSsn, double theWeeklySalary);
		double getSalary() const;
		void setSalary(double newSalary);
		void printCheck();
	};
} 
#endif

