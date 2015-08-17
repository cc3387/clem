#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <cstdlib>

class Person{

private:
	std::string name;

public:
	Person(); //Default Constructor
	Person(std::string theName);//Parameterized Constructor
	Person(const Person& theObject);//Copy Constructor
	std::string getName() const;
	Person &operator=(const Person& rtSide); //operator overloading
	friend std::istream& operator >> (std::istream& inStream, Person& personObject);
	friend std::ostream& operator << (std::ostream& outStream, const Person& personObject);
};

#endif

