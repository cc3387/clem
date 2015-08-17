#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <cstring>

class Student{

private:
	std::string name;
	int numclasses;
	std::string *classlist;

public:

    void input();
	void output();
	void reset();
	Student& operator =(const Student& p);
	~Student();
};