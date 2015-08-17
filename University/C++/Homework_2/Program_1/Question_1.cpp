#include<iostream>

using namespace std;

//Universal data type

const double liters_to_gallons = 0.264179;

//Function Declaration
double miles_per_hour (double liters, double miles);


//Method function
double miles_per_hour (double liters, double miles){

	double mph;
	mph = (liters * liters_to_gallons) / miles;
	return mph;

}

int main(){
	
	double liters;
	double miles;
	char ans;

	do{
	cout<<"Please enter the liters of gasoline consumed by the car: " <<endl; 
	cin>>liters;
	cout<<"Please enter the miles that the car has traveled: " << endl;
	cin>>miles;
	cout << "Miles per hour value is: " << miles_per_hour(liters, miles);
	cout<<" mph.\n";
	cout<<"Again (y/n)?: ";
	cin>>ans;
	} while (ans =='y' || ans == 'Y');

	cout<<"Exiting Program..."<<endl;
	return 0;
}