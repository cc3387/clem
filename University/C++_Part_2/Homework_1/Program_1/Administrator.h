#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "SalariedEmployee.h"

namespace SavitchEmployees
{
	class Administrator : public SalariedEmployee
	{
	
	private:
		std::string Admin_Title;
		std::string Response;
		std::string Supervisor;

	public:

		Administrator();
		Administrator(std::string theName, std::string theSsn, std::string theAdmin_Title, std::string theResponse, std::string theSupervisor, double thesalary);
		
		void setName();
		void setAdminTitle();
		void setSalary();
		void setSupervisor();
		void setResponse();
		void setssn();
		
		std::string getSupervisor();
		std::string getAdminTitle();
		std::string getResponse();

		void print();
		void printCheck();
	};
} 
#endif

