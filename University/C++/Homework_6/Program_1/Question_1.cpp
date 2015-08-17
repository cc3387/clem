#include <iostream>
#include <stdio.h>
#include <cmath>
#include "Question_1.h"
using namespace std;

//Method Classes that were included in the header classes

//Default Constructor's Definition
TwoD::TwoD(void){
	cout<<"Object Initialized" << endl;

	MaxRows = 100;
	MaxCols = 100;

	DoubleArrayPtr *arr_ptr = new DoubleArrayPtr[MaxRows];

	for (int i = 0; i < MaxRows; i++){
	arr_ptr[i] = new double[MaxCols];
	};

	table = arr_ptr;

   for(int i = 0 ; i < MaxRows; i++){
	   for(int j = 0; j < MaxCols; j++){
       table[i][j] = 0; //Initialize the dynamic arrays with all zeros.
	   }
   }

}

//Parametric Constructor's Definition
TwoD::TwoD(int a, int b){
   cout<<"Object Initialized" << endl;

   MaxRows = a;
   MaxCols = b;

   DoubleArrayPtr *arr_ptr = new DoubleArrayPtr[MaxRows];

   for (int i = 0; i < MaxRows; i++){
   arr_ptr[i] = new double[MaxCols];
   };

   table = arr_ptr;

   for(int i = 0 ; i < MaxRows; i++){
	   for(int j = 0; j < MaxCols; j++){
       table[i][j] = 0; //Initialize the dynamic arrays with all zeros.
	   }
   }
}

//Parametric Constructor's Definition
TwoD::TwoD(int a, int b, int c, int d, double element){
   cout<<"Object Initialized" << endl;

   MaxRows = a;
   MaxCols = b;
   row = c;
   col = d;

   DoubleArrayPtr *arr_ptr = new DoubleArrayPtr[MaxRows];

   for (int i = 0; i < MaxRows; i++){
   arr_ptr[i] = new double[MaxCols];
   };

   table = arr_ptr;

   for(int i = 0 ; i < MaxRows; i++){
	   for(int j = 0; j < MaxCols; j++){
       table[i][j] = 0; //Initialize the dynamic arrays with all zeros.
	   }
   }

   table[c][d] = element;
}

//Copy Constructor Definition
TwoD::TwoD(const TwoD &p){
	cout<<"Copy constructor with pointers."<<endl;
	
	MaxRows = p.getMaxRow();
	MaxCols = p.getMaxCol();

	table = new double*[MaxRows];
	for(int i=0; i < MaxRows; i++){
	table[i] = new double[MaxCols];
	}

	for(int i = 0; i < MaxRows; i++) {
        for(int j = 0; j < MaxCols; j++) {
            table[i][j] = p.table[i][j];
        }
    }

	result = p.return_number();
	cout<<"Copied entry is: " << result << endl;
}


void TwoD::entry(int a, int b, double element){
	 row = a;
	 col = b;
	 table[row][col] = element;
}

double TwoD::return_number() const{
	return table[row][col];   
}

int TwoD::getMaxRow() const{
return MaxRows;
}

int TwoD::getMaxCol() const{
return MaxCols;
}

int TwoD::getRow() const{
return row;
}

int TwoD::getCol() const{
return col;
}

TwoD::~TwoD(){
cout << "Object is being deleted" << endl;
delete [] table;
}

const TwoD operator +(const TwoD& TD_1, const TwoD& TD_2){
return TwoD(TD_1.getMaxRow(), TD_1.getMaxCol(), TD_1.getRow(), TD_1.getCol(), TD_1.return_number() + TD_2.return_number());	 
}


bool operator ==(const TwoD& TD_1, const TwoD& TD_2){
return ((TD_1.getRow() == TD_2.getRow())&&(TD_1.getCol() == TD_2.getCol())&&(TD_1.getMaxRow() == TD_2.getMaxRow())&&(TD_1.getMaxCol() == TD_2.getMaxCol()));
}

//Equal Operator

TwoD & TwoD::operator=(const TwoD &p){
	cout<<"Copying constructors with overload operator..."<<endl;
	MaxRows = p.getMaxRow();
	MaxCols = p.getMaxCol();

	table = new double*[MaxRows];
	for(int i=0; i < MaxRows; i++){
	table[i] = new double[MaxCols];
	}

	for(int i = 0; i < MaxRows; i++) {
        for(int j = 0; j < MaxCols; j++) {
            table[i][j] = p.table[i][j];
        }
    }

	result = p.return_number();
	cout<<"Copied entry is: " << result << endl;
	
	return *this;

}

//Main Function
int main(){
	
	//Initialize the dynamic memories for the process of entering datasets, Create TD1 as default and TD2 with specific size
	TwoD TD1(3,4,1,1,15.5), TD2(3,4,1,1,20);
	
	if(TD1 == TD2){
	TwoD TD3 = TD1 + TD2; 
	cout << "The sum of the two array with same location and size is:" << TD3.return_number() << endl;
	}
	else{
	printf("The size or columns/rows are not equal for TD1/TD2.");
	exit(0);
	}

	//Declare default TwoD Constructors
	TwoD TD4, TD5;
	TD4.entry(80,20, 10.5);
	TD5.entry(10,20, 5.5);
	cout<<"Result with initialized constructor is: " << TD4.return_number()<<endl;
	cout<<"Result with initialized constructor is: " << TD5.return_number()<<endl;

	//Calling TD6 with copy constructor
	TwoD TD6(TD4);
	TwoD TD7(TD5);

	//Copying Class with operator overloading
	TwoD TD8,TD9;
	TD8 = TD4;
	TD9 = TD5;
	return 0;
};
