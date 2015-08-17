#include "Bond.h"

//Constructors and Destructors

//Default Constructors
Bond::Bond(){
cout<<"This is Default Constructor..."<<endl;
cout<<"Not Enough Information..."<<endl;
exit(0);
}

//Parameterized Constructors
Bond::Bond(char* a, float b, const Date &D1, const Date &D2){
cout<<"This is Parameterized Constructor..."<<endl;
name = a;
value = b;
purchaseDate = D1;
maturityDate = D2;
}

char* Bond::get_name()const{
return name;
}

float Bond::get_price()const{
return value;
}

int Bond::getDays(const Date &D)const{
return D.getDays();
}

int Bond::getMonth(const Date &D)const{
return D.getMonth();
}

int Bond::getYear(const Date &D)const{
return D.getYear();
}

void Bond::Display(const Date&D)const{
D.DisplayDate();
}

void Bond::setToday(Date &hoy){
Today = hoy;
}

//Calculate days to maturity through value 
int Bond::daysToMaturity(Date &D){

int day = getDays(maturityDate);
int month = getMonth(maturityDate);
int year = getYear(maturityDate);
Date mature(month,day,year);

//Implement calcDiff from Date
int diff = mature.calcDiff(D);
return diff;
}

