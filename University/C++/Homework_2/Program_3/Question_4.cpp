#include<iostream>
#include<cmath>
using namespace std;

const double gconstant= 0.00000006673;

//Function Declaration
double gforce(double m1, double m2, double distance);

//Function
double gforce(double m1, double m2, double distance){
double gravityforce;
gravityforce = (gconstant * m1 * m2) / (pow(distance, 2.0));
return gravityforce;
}

int main(){

double mass_1;
double mass_2;
double distance;
char ans;

do {
cout << "Please Enter the first mass in grams (g): " << endl;
cin >> mass_1;
cout << "Please Enter the second mass in grams (g): " << endl;
cin >> mass_2; 
cout << "Please Enter the distance in centimeters (cm): " << endl;
cin >> distance;
cout << "The Gravity Force in dynes: " << gforce(mass_1, mass_2, distance);
cout << " [g*cm/(s*s)] \n";
cout << "Repeat program? (y/n)" << endl;
cin >> ans;
} while (ans =='y' || ans == 'Y');

cout<<"Exiting Program..."<<endl;
return 0;

}