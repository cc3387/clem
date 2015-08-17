#include "myinteger.h"

void MyInteger::set_number(int a){
number= a;
}

int MyInteger::get_number(){
return number;
}

void MyInteger::set_units(int a){

int unit_temp=0;
int divided;
int i = 9; //An integer can take up to 1 billion unit.
x = new int[i];


while(i >= 0){
divided = a / int(pow(10.0, i));
x[i] = divided;
if(divided > 1 && divided < 10){
if(i > unit_temp){
unit_temp = i;
}
}
a -= divided * int(pow(10.0,i));
i--;
}
units = unit_temp;
}

int MyInteger::get_units(){
return units;
}

int MyInteger::get_x(int a){
return x[a];
}


int MyInteger::operator[](int y){

	if(y > units){
	return -1;
	}
	else{
	return x[y];
	}
};



int main(){

MyInteger MI;

MI.set_number(418);
MI.set_units(418);

//Show the numbers entered and the number of units needed
cout<<"The number entered is: "<<MI.get_number()<<endl;
cout<<"The number of rows (index) in the column (including 0) is: " << MI.get_units()<<endl;

//Getting the number using [] operator
cout<<"The first unit using the [] operator is: " << MI[0]<<endl;
cout<<"The second unit using the [] operator is: " << MI[1]<<endl;
cout<<"The third unit using the [] operator is: " << MI[2]<<endl;
cout<<"The number that is out of bound is: " << MI[3]<<endl;

return 0;

}