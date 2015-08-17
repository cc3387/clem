#include <iostream>
#include <cmath>
using namespace std;

#define METRICTONS 35273.92

int main(){

float wcerealounces;
float wcerealmt;
float noboxes;

cout << "Enter cereal weights in ounces: " << endl;

cin >> wcerealounces;

wcerealmt = wcerealounces/METRICTONS;

noboxes = ceil(wcerealmt);

cout << "The weight of cereal in ounces is: " << wcerealounces << endl;

cout << "The weight of cereal in Metric Tons is : " << wcerealmt << endl;

cout << "The number of boxes needed is: " << noboxes << endl; 

cout << "Exiting Program .... " << endl;

return 0;

}