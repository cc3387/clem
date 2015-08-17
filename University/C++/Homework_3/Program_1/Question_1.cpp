#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

//Function Prototypes
void InputTime(int &hours, int &minutes);
char Day_Night(int &hours, int &minutes);
void TimeConversion(int &hours, int &minutes);
void Output(int &hours, int &minutes, char &am_pm);

//Main Class
int main(){

	int hrs, minutes;
	char am_pm;
	char ans;

	do{
	InputTime(hrs, minutes);
	am_pm = Day_Night(hrs, minutes);
    TimeConversion(hrs, minutes);
	Output(hrs, minutes, am_pm);
	cout<<"Do you want to restart (y/n)?"<<endl;
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	cout<<"Exiting Program..."<<endl;
	return 0;
}

//Function Definitions
void InputTime(int &hrs, int &minutes)
{
	cout << "Enter hours in 24 hours format: "<<endl;
	cin >> hrs;

	if(hrs > 24 || hrs < 0){
	printf("Hours not in 24 hours range.");
	exit(0);
	}
	cout << "Enter minutes: " <<endl;
	cin >> minutes;
	if(minutes > 60 || minutes < 0){
	printf("Minutes not in 60 minutes range.");
	exit(0);
	}
}

char Day_Night (int &hrs, int &minutes)
{   
	char am_pm;
	if(hrs >=12 && hrs < 24){
	am_pm = 'P';
	}
	else{
	am_pm = 'A';
	}
	return am_pm;
}

void TimeConversion(int &hrs, int &minutes)
{  
   if (hrs >= 12){
   hrs = hrs - 12;
   }
   else{
   hrs = hrs;
   }
}

//Output of Day_Night
void Output(int &hours, int &minutes, char &am_pm)
{
	 if (minutes < 10){
     cout << hours << ":0" << minutes << " " << am_pm << endl;
	 } 
	 else{
	 cout << hours << ":" << minutes << " " << am_pm << endl;
	 }
}