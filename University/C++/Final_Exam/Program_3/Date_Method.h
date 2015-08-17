#include "Date.h"

//Constructors and Destructors

//Default Constructors
Date::Date(){
day = 0;
month = 0;
year = 0;

date = new int[3];
for(int i=0; i<3; i++){
date[i] = 0;
}


}

//Parameterized Constructors
Date::Date(int a, int b, int c){
cout<<"This is Parameterized Constructors..."<<endl;
date = new int[3];

for(int i=0; i<3; i++){
date[i] = 0;
}

if(b > daysMonth[a-1] || a > monthsYear || a < 0){
cout<<"The values entered were not in the calendar.."<<endl;
}

month = a;
day = b;
year = c;
}

//Destructors
Date::~Date(){
cout<<"This is Destructor.."<<endl;
delete[] date;
}

//Copy Constructors
Date::Date(const Date &D){
day = D.day;
month = D.month;
year = D.year;

for(int i=0; i<3; i++){
date[i] = D.date[i];
}
}

//Mutators and Accessors
int Date::getDays()const{
return day;
}

int Date::getMonth()const{
return month;
}

int Date::getYear()const{
return year;
}

void Date::DisplayDate()const{
cout << getMonth() << "/" << getDays() << "/" << getYear() << endl;
}

//Operator overload
Date& Date::operator=(const Date &D){
day = D.getDays();
month = D.getMonth();
year = D.getYear();
return *this;
}

int Date::calcDiff(const Date &Today){
Date temp;
int month;
int day;
int year;
temp.month = (getMonth() + 9) % 12;
temp.year = (getYear() - getMonth()/10);
temp.day = 365*temp.getYear() + temp.getYear()/4 - temp.getYear()/400 +(temp.getMonth()*306 +5)/10 +(temp.getDays()-1);
month = (Today.getMonth() + 9) % 12;
year = (Today.getYear() - Today.getMonth()/10);
day = 365*year+year/4-year/400+(month*306+5)/10+(Today.getDays()-1);
temp.day -= day;
return temp.getDays();
}

