#include <iostream>
using namespace std;

//Define the units needed when numbers go out of scope in terms of data types
int units;

//Define the Recursive method

inline int Pow_Recursive(int X, int N){
	units = 0;
	int X1;
	int *X2;
	if (N == 0){
	X = 1;
	return X;
	}
	else if (N == 1){
	return X;
	}
	else{
	X *= Pow_Recursive(X,N-1);
	X2 = &X;
	cout<<"The X's address is: " << X2 << "  The X value is: " << X << endl;
	if(X > 1000000000){
	X1 = X/1000;
	X = X1;
	units = units + 3;
	}
	return X;
	}
	delete X2;
}

inline int Pow_Alt(int X, int N){

	int i=1;
	double X1=X;
	double Y=X;
	double Final;
	double m = N % 2;
	units=0;

	if( m == 0){
	while(i<N/2){
	X1 = X1*X;
	Y  = Y*X;

	if(X1 > 1000000000 && Y > 1000000000){
	
	X1 = X1 / 1000000000;
	Y = Y / 1000000000;
	units = units + 18;
	}
	i++;
	}

	if(X1*Y > 1000000000){
	Final = (X1*Y) / 1000000000;
	units = units + 9;
	return Final;
	}
	else{
	return X1*Y;
	}
	}
	else{
	while(i<N/2){
	X1 = X1*X;
	Y  = Y*X;
	i++;
	}
	return X1*Y*X;
	}
}

int getUnits(int a){
   return a;
}

int main(){

//Calling Recursive Power Function

	int Result;

	//Recursive Power Results
	Result = Pow_Recursive(10,3);
	cout<<"Result using Recursive for Pow(10,3) is: " << Result<<endl;
	Result = Pow_Recursive(2,10);
	cout<<"Result using Recursive for Pow(2,10) is: " << Result<<endl;
	Result = Pow_Recursive(2,24);
	cout<<"Result using Recursive for Pow(2,24) is: " << Result<<endl;
	Result = Pow_Recursive(1024,10);
	cout<<"Result using Recursive for Pow(1024,10) is: " << Result<<"e+"<<units<<endl;
	
	//Alternative Power Results
	Result = Pow_Alt(10,3);
	cout<<"Result using Alternative for Pow(10,3) is: " << Result<<endl;
	Result = Pow_Alt(2,10);
	cout<<"Result using Alternative for Pow(2,10) is: " << Result<<endl;
	Result = Pow_Alt(2,24);
	cout<<"Result using Alternative for Pow(2,24) is: " << Result<<endl;
	Result = Pow_Alt(1024,10);
	cout<<"Result using Alternative for Pow(1024,10) is: " << Result<<"e+"<<units<<endl;

}