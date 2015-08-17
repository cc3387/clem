#include "DayOfYear.h"

int main(){
	
	DayOfYear DOY(15,12,2016), DOY1(15,12,2015), DOY2;
	DOY.calcdoy(); //Non-Leap Year
	DOY1.calcdoy(); //Leap Year
	std::cout<<"The number of days for " << DOY.getday()<<"/"<<DOY.getmonth()<<"/"<<DOY.getyear()<< " is " << DOY.getdoy() << std::endl;
	std::cout<<"The number of days for " << DOY1.getday()<<"/"<<DOY1.getmonth()<<"/"<<DOY1.getyear()<< " is " << DOY1.getdoy() << std::endl;
	
	//Check on assignment operators
	DOY2 = DOY;
	DayOfYear DOY3(DOY1);
	DOY2.calcdoy();	
	std::cout<<"The number of days for (assignment operator) " << DOY2.getday()<<"/"<<DOY2.getmonth()<<"/"<<DOY2.getyear()<< " is " << DOY2.getdoy() << std::endl;
	std::cout<<"The number of days for (copy constructor) " << DOY3.getday()<<"/"<<DOY3.getmonth()<<"/"<<DOY3.getyear()<< " is " << DOY3.getdoy() << std::endl;
	
	return 0;
}