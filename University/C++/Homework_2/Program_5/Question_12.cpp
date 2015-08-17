#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

//Function Declarations
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
bool CheckDates (int month, int day);
int getMonthValue(int month, int year);
char* getDayvalue (int day, int monthvalue, int yearvalue, int centuryvalue);

//Functions
bool isLeapYear(int year){

bool Bvalue;
if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))){
return Bvalue = true; 
}
else{
return Bvalue = false;
}

}

int getCenturyValue(int year){
int century = year / 100;
int remainder = century % 4;
int finalcenturyvalue = (3-remainder)*2;
return finalcenturyvalue;
}

int getYearValue(int year){
int lasttwodigit = year % 100;
int b = lasttwodigit / 4;
int finalyearvalue = lasttwodigit + b;
return finalyearvalue;
}

enum MonthLength{
JAN_LENGTH = 31, FEB_LENGTH = 28, MAR_LENGTH = 31, 
APR_LENGTH = 30, MAY_LENGTH = 31, JUN_LENGTH = 30,
JULY_LENGTH = 31, AUG_LENGTH = 31, SEP_LENGTH = 30,
OCT_LENGTH = 31, NOV_LENGTH = 30, DEC_LENGTH = 31
};

bool CheckDates (int month, int day){

	bool RValue;
	if (month = 1 && day > JAN_LENGTH){
	return RValue = true; 
	}
	
	if (month = 2 && day > FEB_LENGTH){
	return RValue = true; 
	}

	if (month = 3 && day > MAR_LENGTH){
	return RValue = true; 
	}

	if (month = 4 && day > APR_LENGTH){
	return RValue = true; 
	}

	if (month = 5 && day > MAY_LENGTH){
	return RValue = true; 
	}

	if (month = 6 && day > JUN_LENGTH){
	return RValue = true; 
	}

	if (month = 7 && day > JULY_LENGTH){
	return RValue = true; 
	}

	if (month = 8 && day > AUG_LENGTH){
	return RValue = true; 
	}

	if (month = 9 && day > SEP_LENGTH){
	return RValue = true; 
	}

	if (month = 10 && day > OCT_LENGTH){
	return RValue = true; 
	}

	if (month = 11 && day > NOV_LENGTH){
	return RValue = true; 
	}

	if (month = 12 && day > DEC_LENGTH){
	return RValue = true; 
	}

}


int getMonthValue(int month, int year){
int monthvalue;
	
	if(isLeapYear(year) == 1){
	if(month == 1){
	return monthvalue = 6;
	}
	if(month == 2){
	return monthvalue = 2;
	}
	}

	if(isLeapYear(year) == 0){
	if(month == 1){
	return monthvalue = 0;
	}
	if(month == 2){
	return monthvalue = 3;
	}
	}
	
	if(month == 3){
	return monthvalue = 3;
	}
	if(month == 4){
	return monthvalue = 6;
	}
	if(month == 5){
	return monthvalue = 1;
	}
	if(month == 6){
	return monthvalue = 4;
	}
	if(month == 7){
	return monthvalue = 6;
	}
	if(month == 8){
	return monthvalue = 2;
	}
	if(month == 9){
	return monthvalue = 5;
	}
	if(month == 10){
	return monthvalue = 0;
	}
	if(month == 11){
	return monthvalue = 3;
	}
	if(month == 12){
	return monthvalue = 5;
	}
}

char* getDayvalue (int day, int monthvalue, int yearvalue, int centuryvalue){

char* DayName;

int corresponding = day + monthvalue + yearvalue + centuryvalue;
int remainder = corresponding % 7;

if (remainder == 0){
return DayName = "Sunday";
}

if (remainder == 1){
return DayName = " Monday";
}

if (remainder == 2){
return DayName = "Tuesday";
}

if (remainder == 3){
return DayName = "Wednesday";
}

if (remainder == 4){
return DayName = "Thursday";
}

if (remainder == 5){
return DayName = "Friday";
}

if (remainder == 6){
return DayName = "Saturday";
}

}



int main(){

int year;
int month;
int day;
char ans;


cout << "Please enter the year: " << endl;
cin >> year;
cout << "Please enter month: " << endl;
cin >> month;
if (month > 12 || month < 0){
printf("Month entered exceed limit. Please re-enter.");
return 0;
}
cout << "Please enter day: " << endl;
cin >> day;


if (CheckDates (month, day) == 1){
printf("Day entered exceeds maximum date. Please Re-enter date.\n");
return 0;
}
else {
cout<< "The Day is: " << getDayvalue (day, getMonthValue(month, year), getYearValue(year), getCenturyValue(year));
cout<< "\n";
cout<<"Exiting Program..."<<endl;
return 0;
}



}