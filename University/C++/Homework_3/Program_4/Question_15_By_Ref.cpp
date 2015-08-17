#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;


//Function Prototypes
void GCD(int &numerator, int &denominator, int &gcdvalue);
void ConvertToLowest(int &numerator, int &denominator, int &gcdvalue);
void Output(int &numerator, int &denominator, int &gcdvalue);

//Main Class
int main(){
	int numerator, denominator;
	int gcdvalue = 0;
	GCD(numerator, denominator, gcdvalue);
	ConvertToLowest(numerator, denominator, gcdvalue);
	Output(numerator, denominator, gcdvalue);
  	cout<<"Exiting Program..."<<endl;
	return 0;
}

//Function Definitions
void GCD(int &numerator, int &denominator, int &gcdvalue)
{
	//variables definition
	int n, nmod, dmod;
	bool CheckValue;

	cout << "Enter numerator: "<<endl;
	cin >> numerator;
	cout << "Enter denominator: "<<endl;
	cin >> denominator;

	if(denominator == 0){
	CheckValue = true;
	printf("Denominator cannot be zero.");
	exit(0);
	}
	else
	{
	CheckValue = false;
	}
	
	if(CheckValue == 0 && numerator > denominator){
	n = numerator; 
	}
	
	if(CheckValue == 0 && numerator < denominator){
	n = denominator; 
	}

	for (int i; i<=n; i++){
	nmod = numerator % i;
	dmod = denominator % i;
	if(nmod == 0 && dmod == 0){
    gcdvalue = i;
	}
	if(i == n && gcdvalue == 0){
	printf("There is no common divisor between numerator and denominator...");
	exit(0);
	}
	}
}

void ConvertToLowest(int &numerator, int &denominator, int &gcdvalue)
{  
  numerator = numerator/gcdvalue;
  denominator = denominator/gcdvalue;
}

//Output Function
void Output(int &numerator, int &denominator, int &gcdvalues)
{
 cout << "Numerator (Lowest Converted) Output: " << numerator << endl;
 cout << "Denominator (Lowest Convereted) Output: " << denominator << endl;
 cout << "GCD value is: " << gcdvalues << endl;
}