#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;

const float pounds_in_kilos = 2.2046;
const float g_in_kg = 1000;
const float ounces_in_pound = 16;

//Function Prototypes
void InputWeight(float &pounds, float &ounces);
void ConvertWeight(float &pounds, float &ounces, float &kilos, float &grams);
void Output(float &pounds, float &ounces, float &kilos, float &grams);

//Main Class
int main(){

	float pounds, ounces, kilos, grams;
	char ans;

	do{
    InputWeight(pounds, ounces);
	ConvertWeight(pounds, ounces, kilos, grams);
	Output(pounds, ounces, kilos, grams);
	cout<<"Do you want to continue (y/n)?"<<endl;
	cin >> ans;
	} while (ans == 'Y' || ans == 'y');
	
	cout<<"Exiting Program..."<<endl;
	return 0;
}

//Function Definitions
void InputWeight(float &pounds, float &ounces)
{
	cout << "Enter Pounds: "<<endl;
	cin >> pounds;
	cout << "Enter Ounces: "<<endl;
	cin >> ounces;
	if (pounds < 0 || ounces > 16 || ounces < 0){
	printf("Inputs entered exceed value.");
	exit(0);
	}

}

void ConvertWeight(float &pounds, float &ounces, float &kilos, float &grams)
{  
	float o_to_k;
	o_to_k =(ounces / (ounces_in_pound)) / pounds_in_kilos;
	kilos = (pounds / pounds_in_kilos) + o_to_k;
	grams = (kilos-floor(kilos));
	grams = grams*1000;
}

//Output of Day_Night
void Output(float &pounds, float &ounces, float &kilos, float &grams)
{
 cout<< "From " << pounds << " pounds and " << ounces << " ounces to " << endl; 
 cout.precision(2);
 cout<< kilos << "kgs and " << endl;
 cout.precision(3);
 cout<< grams << "grams." << endl; 
}