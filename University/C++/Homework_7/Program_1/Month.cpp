#include <iostream>
#include "Month.h"
using namespace std;

Month::Month(){
cout << "This is default Constructor.." << endl;
month = 0;
}

Month::Month(char*a){
cout<<"This is parameterized constructor with month names.." <<endl;
map_int(a);
}

Month::Month(int a){
cout<<"This is parameterized constructor with month as int.. " << endl;
month = a;
}

char* Month::map_char(int a){

char* month_name;

if(a == 1){
month_name = "Jan";
}
else if(a == 2){
month_name = "Feb";
}
else if(a == 3){
month_name = "Mar";
}
else if(a == 4){
month_name = "Apr";
}
else if(a == 5){
month_name = "May";
}
else if(a == 6){
month_name = "Jun";
}
else if(a == 7){
month_name = "Jul";
}
else if(a == 8){
month_name = "Aug";
}
else if(a == 9){
month_name = "Sep";
}
else if(a == 10){
month_name = "Oct";
}
else if(a == 11){
month_name = "Nov";
}
else if(a == 12){
month_name = "Dec";
}

return month_name;
}

void Month::map_int(char* a){

if(a == "Jan"){
month = 1;
}
else if(a == "Feb"){
month = 2;
}
else if(a == "Mar"){
month = 3;
}
else if(a == "Apr"){
month = 4;
}
else if(a == "May"){
month = 5;
}
else if(a == "Jun"){
month = 6;
}
else if(a == "Jul"){
month = 7;
}
else if(a == "Aug"){
month = 8;
}
else if(a == "Sep"){
month = 9;
}
else if(a == "Oct"){
month = 10;
}
else if(a == "Nov"){
month = 11;
}
else if(a == "Dec"){
month = 12;
}

}

void Month::input_month(int i){
month = i;
}

void Month::output_month(){
cout<<"The month in integer is: "<< month << endl;
}

void Month::output_month_name(){
char* month_name = map_char(month);
cout<<"The month name is: " << month_name << endl;
}

int Month::NextMonth(const Month &p){
Month Temp;
Temp.month = (p.month + 1) % 12;
cout<<"This is next month function, the next month is: " << endl;
Temp.output_month();
Temp.output_month_name();
return Temp.month;
}



int main(){

	//Initializing constructors
    Month M("Dec"), M1(5);

	//Output Month and Names
	M.output_month();
	M.output_month_name();
	M1.output_month();
	M1.output_month_name();
	
	//Defining next Month
	M.NextMonth(M);
	M1.NextMonth(M1);
}