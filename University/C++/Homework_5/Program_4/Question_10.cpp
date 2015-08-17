#include<iostream>
#include<cstdio>
using namespace std;

class Temperature{

private: 
	
	double Kelvin;

public:

	void setTempKelvin(double);
	void setTempFahrenheit(double);
	void setTempCelsius(double);
	void ShowResult();
	
};


void Temperature::setTempKelvin(double a){
     Kelvin = a;       
}

void Temperature::setTempFahrenheit(double b){
	double Fahrenheit = b;
	Kelvin = (50/9)*(Fahrenheit - 32) + 273.15;
}

void Temperature::setTempCelsius(double c){
	double Celsius = c;
	Kelvin = Celsius + 273.15;
}

void Temperature::ShowResult(){
cout<< "The Temperature in Kelvin is: " << Kelvin << endl;
}


int main(){
    
	char unit;
	double temp;
	char ans;
	Temperature T;

	do{
	cout << "Please enter the temperature unit (Celsius = C, Kelvin = K, Fahrenheit = F): " << endl;
	cin >> unit;
	cout << "Please enter the temperature given the unit you entered previously: " << endl;
	cin>>temp;
	if (unit == 'C' || unit == 'c')
	{T.setTempCelsius(temp);}
	if (unit == 'F' || unit == 'F')
	{T.setTempFahrenheit(temp);}
	if (unit == 'K' || unit == 'K')
	{T.setTempKelvin(temp);}
	
	T.ShowResult();
	cout << "Re-calculate?" <<endl;
	cin>>ans;
	}while(ans=='Y'|| ans =='y');
	

}



