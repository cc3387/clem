#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

//Define the number of arrays and size
const int NUM_MONTHS = 12;
double average_monthly_rainfall[NUM_MONTHS];
double prev_months[NUM_MONTHS];
double diff[NUM_MONTHS];

//Define the Method classes that will input the average and actual arrays
void Inputaverage();
void Input_prev_months(int month_integer);
void calcdiff(double a[], double b[], double c[], int month);
void Output(double a[], double b[], double c[], int month, char option);


//Main Body
int main(){
	
	int month;
	char opt;
	char ans;
	Inputaverage();
	cout<< "Please enter the current month in the following format (Jan = 1, Feb = 2, Mar = 3 , Apr = 4 ... ): " << endl;
	cin >> month;
	Input_prev_months(month);
	calcdiff(average_monthly_rainfall, prev_months, diff, month);

	do{
	cout<<"Please choose how to display the data : (c for chart, t for table)"<<endl;
	cin >> opt;
	Output(average_monthly_rainfall, prev_months, diff, month, opt);
	cout<<"Choose another display option? (y/n)" << endl;
	cin >> ans;
	} while (ans == 'y' || ans == 'Y');


	return 0; 
}

//InputAverage Definition
void Inputaverage(){

	double input_average_rainfall;
	cout<<"Enter average rainfall (mm) since January: " << endl;
	
	for(int i = 0; i < NUM_MONTHS; i++){
	
	if(i == 0){
	cout << "Jan: " <<endl;
	}
	
	if(i == 1){
	cout << "Feb: " <<endl;
	}
	
	if(i == 2){
	cout << "March: " <<endl;
	}

	if(i == 3){
	cout << "April: " <<endl;
	}

	if(i == 4){
	cout << "May: " <<endl;
	}

	if(i == 5){
	cout << "Jun: " <<endl;
	}

	if(i == 6){
	cout << "Jul: " <<endl;
	}

	if(i == 7){
	cout << "Aug: " <<endl;
	}

	if(i == 8){
	cout << "Sep: " <<endl;
	}

	if(i == 9){
	cout << "Oct: " <<endl;
	}

	if(i == 10){
	cout << "Nov: " <<endl;
	}

	if(i == 11){
	cout << "Dec: " <<endl;
	}
	cin >> input_average_rainfall;
	average_monthly_rainfall[i] = input_average_rainfall;
	};
}

//InputPreviousMonths Definition
void Input_prev_months(int month_integer){
	 
	 double rainfall;

	 month_integer -= 1;

	 cout<< "Enter the monthly rainfall in the previous 12 months: " << endl;
	
for (int i = 0 ; i < NUM_MONTHS ; i++){

    if((month_integer + (i+1)) % 12 == 0){
	cout << "Pre Jan : " <<endl;
	}
	
	if((month_integer + (i+1)) % 12 == 1){
	cout << "Pre Feb: " <<endl;
	}
	
	if((month_integer + (i+1)) % 12 == 2){
	cout << "Pre March: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 3){
	cout << "Pre April: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 4){
	cout << "Pre May: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 5){
	cout << "Pre Jun: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 6){
	cout << "Pre Jul: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 7){
	cout << "Pre Aug: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 8){
	cout << "Pre Sep: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 9){
	cout << "Pre Oct: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 10){
	cout << "Pre Nov: " <<endl;
	}

	if((month_integer + (i+1)) % 12 == 11){
	cout << "Pre Dec: " <<endl;
	}

	cin >> rainfall;
	prev_months[i] = rainfall;
  };

}

//Calculate difference calculations
void calcdiff(double a[], double b[], double c[], int month){
	month -= 1;
	for (int i = 0 ; i < NUM_MONTHS ; i++){
	double temp = a[(month + (i+1)) % 12];
	double temp1 = b[i];
    c[i] = temp - temp1;
	}
}

//Output
void Output(double a[], double b[], double c[], int month, char option){
   
   char* month_name;
   month -= 1;


	
for (int i = 0; i < NUM_MONTHS ; i++){
	double temp = a[(month + (i+1)) % 12]; //collect all the arrays value for average
	double temp1 = b[i]; // collect all the arrays value for previous 12 months
	 
	if((month + (i+1)) % 12 == 0){
	month_name = "Jan";
	}
	
	if((month + (i+1)) % 12  == 1){
	month_name = "Feb";
	}
	
	if((month + (i+1)) % 12  == 2){
	month_name = "Mar";
	}

	if((month + (i+1)) % 12  == 3){
	month_name = "Apr";
	}

	if((month + (i+1)) % 12  == 4){
	month_name = "May";
	}

	if((month + (i+1)) % 12  == 5){
	month_name = "Jun";
	}

	if((month + (i+1)) % 12 == 6){
	month_name = "Jul";
	}

	if((month + (i+1)) % 12  == 7){
	month_name = "Aug";
	}

	if((month + (i+1)) % 12  == 8){
	month_name = "Sep";
	}

	if((month + (i+1)) % 12  == 9){
	month_name = "Oct";
	}

	if((month + (i+1)) % 12 == 10){
	month_name = "Nov";
	}

	if((month + (i+1)) % 12 == 11){
	month_name = "Dec";
	}
	
	if (option == 'c'){
    cout << "Ave Rainfall in " << month_name << " " << "|";
	for(int j = 1; j <= temp; j+=5){
    cout<< '*';
	}
	cout<< " "<<endl;

    cout << "Pre Rainfall in " << month_name << " " << "|";
    for(int j = 1; j <= temp1; j+=5){
	cout << '*';
	}
	cout<< " " << endl;
    }

	if (option == 't'){
    cout << "Month" << " " << "Ave Rainfall" << " " << "Pre Rainfall" << "   " << "Diff" << endl;
	cout <<  month_name << "          " << a[(month + (i+1)) % 12] << "      " << b[i] << "          " << c[i] << endl;
	}

}

}