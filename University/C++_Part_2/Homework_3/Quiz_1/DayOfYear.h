#ifndef DayOfYear_H
#define DayOfYear_H

#include <iostream>

class DayOfYear{

private:
	int day;
	int month;
	int year;
	int day_of_year;
	int *days_in_month;

public:
	DayOfYear(); //Default Constructor
    DayOfYear(int Day, int Month, int Year); //Parameterized Constructor
	bool leapyearcheck();
    ~DayOfYear(); //Destructor
	DayOfYear(const DayOfYear &rhs); //Copy Constructor
	DayOfYear& operator = (const DayOfYear &rhs);

	//Calculate day of year
	void calcdoy();

	//Getters
	const int getday();
	const int getmonth();
	const int getyear();
	const int getdoy();
};

#endif

