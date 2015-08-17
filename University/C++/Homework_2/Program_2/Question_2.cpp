#include<iostream>

using namespace std;

//Function Declaration
double inflation(double priceprevious, double pricenow);

//Function
double inflation(double priceprevious, double pricenow){
double infrate;
infrate = (pricenow - priceprevious) / priceprevious * 100;
return infrate;
}

int main(){

double priceprevious;
double pricenow;
char ans;

do {
cout << "Please Enter the price of the item last year: " << endl;
cin >> priceprevious;
cout << "Please Enter the price of the item this year: " << endl;
cin >> pricenow; 
cout << "The inflation is :" << inflation(priceprevious, pricenow);
cout << "%. \n";
cout << "Repeat program? (y/n)" << endl;
cin >> ans;
} while (ans =='y' || ans == 'Y');

cout<<"Exiting Program..."<<endl;
return 0;

}