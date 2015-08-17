#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

const int MAX_NUM = 100;
double FULL_LIST[MAX_NUM];
double std_deviation_calc(double a[], int size);

int main(){

	double standard_dev;
	double p_list[] = {10,20,5,3,1};
	int size_of_p_list = sizeof(p_list) / sizeof(double); //since each number included are double, therefore size 8 of double is divided.
	standard_dev = std_deviation_calc(p_list, size_of_p_list);
	cout<<"Standard Deviation of the array is: " << standard_dev;
	return 0;
}


//Standard deviationa calculation

double std_deviation_calc(double a[], int size){

	double sum = 0;
	double temp;
	double average;
	double std;
	double sum_x_x_ave = 0;

	for(int i = 0; i < size; i++){
	FULL_LIST[i] = a[i];
	temp = a[i];
	sum += temp;
	}

	average = sum / size;

	for(int i=0; i < size; i++){
	temp = FULL_LIST[i];
	FULL_LIST[i] = pow(temp - average, 2.0);
	temp = FULL_LIST[i];
	sum_x_x_ave += temp;
	}
	
	std = sqrt(sum_x_x_ave/size);
	return std;
}
