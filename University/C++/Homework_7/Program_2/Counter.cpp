#include <iostream>
#include "Counter.h"
using namespace std;

//Defining method definitions

//Starting constructors
Counter::Counter(){
count = 0;
a = 0;
s = 0;
d = 0;
f = 0;
}

void Counter::reset(){
count = 0;
}

void Counter::incr1(){
count += 1;
}

void Counter::incr10(){
count += 10;
}

void Counter::incr100(){
count += 100;
}

void Counter::incr1000(){
count += 1000;
}

bool Counter::overflow(){
if (count > MAX_COUNT){
value = true;
}
else{
value = false;
return value;
}

}

void Counter::in_cents(){
a += 1;
incr1();
if(a > 9){
a = 1;
count -= 9;
}
}

void Counter::in_dimes(){
s += 1;
incr10();
if(s > 9){
s = 1;
count -= 90;
}
}

void Counter::in_dollars(){
d += 1;
incr100();
if(d > 9){
d = 1;
count -= 900;
}
}

void Counter::in_10_dollars(){
f += 1;
incr1000();
if(f > 9){
f = 1;
count -= 9000;
}
}

void Counter :: Display(){
if (count != 10000){
cout << "The Count is: " << count << endl;
cout << "The Amount of Cent is: " << a << endl;
cout << "The Amount of Dime is: " << s << endl;
cout << "The Amount of Dollar is: " << d << endl;
cout << "The Amount of 10 Dollars is: " << f << endl;
}
}


void Counter::request_overflow(){
count = 10000;
value = overflow();
if(value == 1){
cout << "Count exceeds Maximum 9999" << endl;
exit(0);
}
}

void Counter::enter(char p){

if(p =='a'){
in_cents();
}
else if(p == 's'){
in_dimes();
}
else if(p == 'd'){
in_dollars();
}
else if(p == 'f'){
in_10_dollars();
}
else if(p == 'o'){
request_overflow();
}
else{
cout << "Please Re-Enter " << endl;
}

}


int main(){
	
	char input;
	Counter C;

	cout<<"Please enter the digits (a = 1, s = 10, d = 100, f = 1000, o = overflow): "<<endl;
	do{
    cin >> input;
	C.enter(input);
	C.Display();
	}while (input != 'o');

	cout<<"Overflow Requested. Exiting ..." << endl;
	
	return 0;
}