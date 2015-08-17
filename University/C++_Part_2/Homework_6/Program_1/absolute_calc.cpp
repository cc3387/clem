#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;


template <class T>
T calc_abs(char num_ops, T x, T y){
  
  if(num_ops == '+'){
  T total = x + y;
  
  if(total <0){
  total = -(total);
  }
  
  throw total;
  }

  else if(num_ops == '-'){
  T total = x - y;
  
  if(total <0){
  total = -(total);
  }
  
  throw total;
  }

  else if(num_ops == '*'){
  T total = x * y;
  
  if(total <0){
  total = -(total);
  }
  
  throw total;
  }

  else if(num_ops == '/'){
  
  if(y == 0){
  throw "No";
  }
  else{
  T total = x / y;
  if(total < 0){
  total = -(total);
  }
  throw total;
  }

  }


}

template <class T>
void abs_tc_final(char num_ops, T x, T y){

	try{
	calc_abs(num_ops, x, y);
	}
	catch(T a){
	cout<<"The total absolute function is: " << a << endl;
	}catch(...){
	cout<<"Numbers cannot divide by zero.." << endl;
	}

}

int main(){

	cout<<"Results for float variables: " <<endl;
	float x = 10.32;
	float y = 5.21;
	abs_tc_final('+', x, y);
	abs_tc_final('-', x, y);
	abs_tc_final('*', x, y);
	abs_tc_final('/', x, y);
	cout<<" " <<endl;

	cout<<"Results for int variables: " <<endl;
	int x1 = 10;
	int y1 = 3;
	abs_tc_final('+', x1, y1);
	abs_tc_final('-', x1, y1);
	abs_tc_final('*', x1, y1);
	abs_tc_final('/', x1, y1);
	cout<<" " <<endl;


	cout<<"Results for double variables: " <<endl;
	double x2 = 5.567;
	double y2 = 6.689;
	abs_tc_final('+', x2, y2);
	abs_tc_final('-', x2, y2);
	abs_tc_final('*', x2, y2);
	abs_tc_final('/', x2, y2);
	cout<<" "<<endl;


	cout<<"Results for char variables: " <<endl;
	char x3 = 'm';
	char y3 = 'n';
	abs_tc_final('+', x3, y3);
	abs_tc_final('-', x3, y3);
	abs_tc_final('*', x3, y3);
	abs_tc_final('/', x3, y3);
	cout<<" "<<endl;


	//Check for Exceptions
	abs_tc_final('/', 5, 0);
}