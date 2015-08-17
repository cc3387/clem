#ifndef Person_H
#define Person_H

#include "Point.h"

class Person : public Point{

protected:

	char* name;
	int age;
	Point gps_loc;

public:
	Person(); //Default Constructor
	Person(char*, int);
	Person(char*, int, int, int); //Parameterized Constructor
	~Person(); //Destructor

	//Setters and Getters
	char* getname() const;
	int  getage() const;
	void gps_setloc(int, int);
	int get_gps_X() const;
	int get_gps_Y() const;
	double get_distance(const Person &rhs, const Person &lhs);
};

#endif