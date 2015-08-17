#include <iostream>
#include <math.h>
using namespace std;

int main(){

float acceleration;
float distance;
float time;

cout<<"Please enter the time of freefall in seconds: " << endl;
cin >> time;

acceleration = 32;

distance = 0.5 * acceleration * time * time;

cout<<"The distance (in feets) given the time you entered in second is: " << distance << endl;

cout<<"Exiting Program ... "<<endl;

return 0;


}