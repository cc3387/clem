#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;

const float meters_in_foot = 0.3048;
const float cm_in_m = 100;
const float inches_in_feet = 12;

//Function Prototypes
void InputHeight(float &feet, float &inches);
float ConvertHeightm(float &feet, float &inches);
float ConvertHeightcm(float &feet, float &inches);
void Output(float &feet, float &inches, float &meters , float &centimeters);

//Main Class
int main(){

	float fts, inch, m, cm;
	char ans;

	do{
    InputHeight(fts, inch);
	cm = ConvertHeightcm(fts, inch);
	m = ConvertHeightm(fts, inch);
	Output(fts, inch, m, cm);
	cout<<"Do you want to continue (y/n)?"<<endl;
	cin >> ans;
	} while (ans == 'Y' || ans == 'y');
	
	cout<<"Exiting Program..."<<endl;
	return 0;
}

//Function Definitions
void InputHeight(float &feet, float &inches)
{
	cout << "Enter feet: "<<endl;
	cin >> feet;
	cout << "Enter inches: "<<endl;
	cin >> inches;
	if (inches > 12){
	printf("inches entered exceed value.");
	exit(0);
	}

}

float ConvertHeightcm(float &feet, float &inches)
{  
	float meters;
	float centimeters;
	float i_to_f;

	i_to_f = inches / (inches_in_feet) * meters_in_foot;
	meters = (feet * meters_in_foot) + i_to_f;
	centimeters = (meters - floor(meters)) * 100;
	centimeters = floor(centimeters);
	return centimeters;
}

float ConvertHeightm(float &feet, float &inches)
{  
	float meters;
	float centimeters;
	float i_to_f;

	i_to_f = inches / (inches_in_feet) * meters_in_foot;
	meters = (feet * meters_in_foot) + i_to_f;
	meters = floor(meters);
	return meters;
}

//Output of Day_Night
void Output(float &feet, float &inches, float &meters , float &centimeters)
{
 cout<< "From " << feet << " feet and " << inches << " inches to " << meters << "m and " << centimeters << "cm." << endl; 
}