#include <iostream>
#include <cmath>

using namespace std;


//Define a class that includes all the calculations
class Wagecalc{
private:
	float oldsalary;
	float Rate;
public:
	float newretro(float, float);
	float newannual(float, float);
	float newmonthly(float, float);
};

// Methods of the functions included in the class

float Wagecalc::newretro(float a, float b){
double newrwage;
oldsalary = a;
Rate = b;
newrwage = oldsalary*(1+Rate/2)-oldsalary; //The wage increase only occurs for 6 months
return newrwage;
}

float Wagecalc::newannual(float a, float b){
float newawage;
oldsalary = a;
Rate = b;
newawage = oldsalary*(1+Rate/2); //The new annual salary with the 6 months retro increase
return newawage;
}

float Wagecalc::newmonthly(float a, float b){
float newmwage;
oldsalary = a;
Rate = b;
newmwage = (oldsalary*(1+Rate/2))/12; //The new monthly salary with the 6 months retro increase
return newmwage;
}


//Main class that deliver all the calculations
int main(){
	Wagecalc WC;
	const float payincrease = 0.076;
	float salary_input;
	cout << "Please enter your salary last year: " << endl;
	cin >> salary_input;
	cout << "Amount of retroactive pay for 6 months is: " << WC.newretro(salary_input, payincrease) << endl;
	cout << "New annual salary of employee is : " << WC.newannual(salary_input, payincrease) << endl;
	cout << "New monthly salary of employee is : " << WC.newmonthly(salary_input, payincrease) << endl;
	cout << "Exit Program ... " << endl;
	return 0;
}