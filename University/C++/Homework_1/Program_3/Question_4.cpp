/************************************************
Logic Understanding--

FV = Face Value 
R = interest Rates
T = Time in years
CR = Consumer receivables

FV - (FV * R * T) = Consumer Received
FV * (1- R*T) = Consumer Received
FV = Consumer Received / (1 - R*T);
**************************************************/

#include <iostream>
#include <cmath>
using namespace std;


class FVRepayCalc{

private:
	float R;
	float T;
	float CR;

public:
	float FVcalc(float, float, float);
	float Repayment(float, float);
};

float FVRepayCalc::FVcalc(float a, float b, float c)
{	R = a;
	T = b;
	CR = c;
	float FV = CR/(1-(R/100*T));
	return FV;
}

float FVRepayCalc::Repayment(float a, float b)
{
   float FV = a;
   float T = b;
   float Tmonth = T * 12;
   float RV = FV/Tmonth;
   return RV;
}

int main(){
	
	FVRepayCalc FRC;
	float interest;
	float time;
	float ConsumerReceive;
	float futurevalue;

	cout << "Enter Interest in %: " << endl;
	cin >> interest;
	cout << "Enter Duration in Years: " << endl;
	cin >> time;
	cout << "Enter amount to receive: " << endl;
	cin >> ConsumerReceive;
	
	futurevalue = FRC.FVcalc(interest, time, ConsumerReceive);
	cout << "The Future Value is: " << futurevalue << endl;
	cout << "The Repayment Value is: " << FRC.Repayment(futurevalue, time) << endl;
	cout << "Exiting Program ... " << endl;

	return 0;
}