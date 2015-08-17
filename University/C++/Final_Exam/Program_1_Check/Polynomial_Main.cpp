#include "Polynomial.h"

int main(){

Poly P1, P2;

int Order_1 = 4;
int Order_2 = 7;

int Coeff_1[] = {-19,1,-12,3,2};
int Coeff_2[] = {-19,1,-6,0,0,7,0,2};

//Initialize the coefficients in the class
P1.set(Coeff_1,Order_1);
P2.set(Coeff_2,Order_2);
Poly P3 = P1 + P2;
cout << "The Polynomial of P1 + P2 is: " << P3 << endl;

P1.set(Coeff_1,Order_1);
P2.set(Coeff_2,Order_2);
P3 = (P2 - P1);
cout <<"The Polynomial of P1 - P2 is: " << P3 << endl;


P1.set(Coeff_1,Order_1);
P2.set(Coeff_2,Order_2);
P3 = P1 * 10;
cout << "The Polynomial of P1 * 10 is: " << P3 << endl;

P1.set(Coeff_1,Order_1);
P2.set(Coeff_2,Order_2);
P3 = 10 * P1;
cout << "The Polynomial of 10 * P1 is: " << P3 << endl;


P1.set(Coeff_1,Order_1);
P2.set(Coeff_2,Order_2);
P3 = P2 * P1;
cout << "The Polynomial of P1 * P2 is : " << P3 << endl;

//Flag that shows yes or no
bool flag = (P1 == P2);
cout << "The flag of P1 == P2 is: " << flag << endl;

//Assigning new value to P2
P1.set(Coeff_1,Order_1);
P2.set(Coeff_2,Order_2);
cout << "P1[3] is: " << P1[3] << endl;
cout << "P2[5] is: " << P2[5] << endl;
P1[3] = P2[5];
cout << "After operatration, P1[3] is: " << P1[3] << endl;

//Horners Method
P1.set(Coeff_1,Order_1);
int Z = P1(5);
cout << "The value given X=5 for Polynomial P1 is: " << Z << endl;

//Other Testing of the function
Poly P4, P5;
P4.set();

P5 = P4;
P1.set(Coeff_1,Order_1);
Poly P6 = P1 + P5;
cout<<"The result of the sum of entered coefficient and P1 is: " << P6 << endl;

P5 = P4;
P1.set(Coeff_1,Order_1);
P6 = P1 * P5;
cout<<"The result of the multiplication of entered coefficient and P1 is: " << P6 <<endl;


return 0;
}
