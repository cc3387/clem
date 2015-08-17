#include<iostream>
#include<cmath>
using namespace std;

class MyInteger{

private:
	int *x;
	int units;
	int number;

public:
	void set_number(int);
	void set_units(int);
	int get_number();
	int get_units();
	int get_x(int);
	int operator[](int);
};