#include "DayOfYear.h"

DayOfYear::DayOfYear() : day(0), month(0), year(0), day_of_year(0) {

	  //Initializing the array with all the days in the months 
	  days_in_month = new int[12];

	  for(int i=0; i<12; i++){
	  days_in_month[i] = 0;
	  }
}

DayOfYear :: DayOfYear(int Day, int Month, int Year) : day(Day), month(Month), year(Year), day_of_year(0){
	  //Initializing the array with all the days in the months 
	  days_in_month = new int[12];
	  for(int i=0; i<12; i++){
	  days_in_month[i] = 0;
	  }

	  	  
	  days_in_month[0] = 31; //Jan
	  if(leapyearcheck() == 0){ //Feb
	  days_in_month[1] = 28;
	  }else{
	  days_in_month[1] = 29;
	  }
	  days_in_month[2] = 31; //March
	  days_in_month[3] = 30; //April
	  days_in_month[4] = 31; //May
	  days_in_month[5] = 30; //June
	  days_in_month[6] = 31; //July
	  days_in_month[7] = 31; //August
	  days_in_month[8] = 30; //September
	  days_in_month[9] = 31; //October
	  days_in_month[10] = 30; //November
	  days_in_month[11] = 31; //December

	  if(month > 12 || month < 0){
	  std::cout<< "Month cannot be more than 12 or less than 0..." << std::endl;
	  exit(1);
	  }
	  
	  if(day > days_in_month[month-1]){
	  std::cout<< "The Day entered exceed maximum days in the month..."<<std::endl;
	  exit(1);
	  }
}

DayOfYear::DayOfYear(const DayOfYear &rhs){ // Copy Constructor
	std::cout<<"This is Copy Constructor ... " << std::endl;
	day_of_year = rhs.day_of_year;
	day = rhs.day;
	month = rhs.month;
	year = rhs.year;

	days_in_month = new int[12];
	
	for(int i=0; i<12; i++){
	days_in_month[i] = 0;
	}
	
	for(int i=0; i<12; i++){
	days_in_month[i] = rhs.days_in_month[i];
	}
}

DayOfYear& DayOfYear::operator = (const DayOfYear &rhs){ //Assignment operator
    std::cout<<"Using assignment operator ... " << std::endl;
	day = rhs.day;
	month = rhs.month;
	year = rhs.year;

	delete[] days_in_month;
	days_in_month = new int[12];
	
	for(int i=0; i<12; i++){
	days_in_month[i] = 0;
	}
	
	for(int i=0; i<12; i++){
	days_in_month[i] = rhs.days_in_month[i];
	}

    return *this;
}


bool DayOfYear::leapyearcheck(){

	 if(year%4 == 0){
	 return true;
	 }else{
	 return false;
	 }
}


void DayOfYear::calcdoy(){
	 
     for(int i=0; i<(month-1); i++){
	 day_of_year += days_in_month[i]; //adding number of days each month passed by
	 }

	 day_of_year += day; //adding the additional days
}



//Getters
const int DayOfYear::getday(){
return day;
}

const int DayOfYear::getmonth(){
return month;
}

const int DayOfYear::getyear(){
return year;
}

const int DayOfYear::getdoy(){
return day_of_year;	
}


DayOfYear::~DayOfYear(){
std::cout<<"Calling DayOfYear Destructor.."<<std::endl;
delete[] days_in_month;
}