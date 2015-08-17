#include<iostream>
#include<string>
using namespace std;


int fibonacci(int n){

	int f0 = 1;
	int f1 = 1;

	if(n == 0){
	return f0;
	}else if(n==1){
	return f1;
	}else if (n > 1){
	return fibonacci(n-1) + fibonacci(n-2); //Adding the second number with the first number
	}
}

int main(){
	
	//Generating the first 20 numbers in the Fibonacci Sequence out of the function below
	for(int i=0; i<21; i++){
	cout<<"F"<< i << " in fibonacci sequence is: " << fibonacci(i)<<endl;
	}
	return 0;
}