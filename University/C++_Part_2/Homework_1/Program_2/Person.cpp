#include "Person.h"

Person::Person(){
name = "Name Not Set";
}

Person::Person(std::string theName){
name = theName;
}

Person::Person(const Person& theObject){
name = theObject.name;
}

std::string Person::getName() const{
return name;
}

Person &Person::operator=(const Person& rtSide){
name = rtSide.name;
return *this;
}

std::istream& operator >> (std::istream& inStream, Person& personObject){
	std::string Person_Name;
	std::cout <<" " << std::endl;
	std::cout <<"Please enter the Owner's name: " << std::endl;
	inStream  >> Person_Name;
    personObject.name = Person_Name;
}

std::ostream& operator << (std::ostream& outStream, const Person& personObject){
	std::cout <<" " << std::endl;
	std::cout << "The name of the person entered is: " << std::endl;
	outStream << personObject.name; 
    return outStream;
}