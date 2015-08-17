/***************************
[in] : n, Guess_Number
[out] : Two decimals double estimation
****************************/

#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

inline double Babylonian(double n, double guess, int i){
	   			
	   if (i <= 5) {
	   double r = n/guess;
	   guess = (guess + r)/2;
	   return guess;
	   };
	   
}

int main() {

	double number;
	double Guess_Number;
	
	cout << "Enter the positive number n: " << endl;
	cin >> number;

    if (number < 0){
	printf ("n is negative. The Babylonian cannot be applied.\n");
	}
	else{
	Guess_Number = number/2; //Initial guess on the numbers
	for (int i = 1; i <= 5; i++){
	Guess_Number = Babylonian(number, Guess_Number, i);
	};
	cout << "The square root of n using Babylonian algorithm is: " << setprecision(3) << Guess_Number << endl;
	};
	
	cout << "Exiting Program... " << endl;

	return 0;

};