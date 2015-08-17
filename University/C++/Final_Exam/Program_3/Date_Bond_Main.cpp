#include "Date_Method.h"
#include "Bond_Method.h"

int main(){

Date Today(4,18,2012);
Date Maturity(12,31,2025);
Date Purchase(2,28,2012);

Bond Y("NYC_Obligation", 885.0, Purchase, Maturity);
Bond *bond_ptr = new Bond("GW_Bridge_Obligation", 895.0, Purchase, Maturity);

int Y_days = Y.daysToMaturity(Today);
float Y_years = Y_days / 365;
cout<<"The name of the First Bond is : "<< Y.get_name() <<endl;
cout<<"The price of the First Bond is : "<< Y.get_price() << endl;
cout<<"The difference between Maturity Date and Today's Date is: "<< Y_days << " Days."<<endl;
cout<<"The difference between Maturity Date and Today's Date is: "<< Y_years << " Years."<<endl;

int ptr_days = bond_ptr -> daysToMaturity(Today);
float ptr_years = ptr_days / 365;
cout<<"The name of the Second Bond is : "<< bond_ptr -> get_name() <<endl;
cout<<"The price of the Second Bond is : "<< bond_ptr -> get_price() << endl;
cout<<"The difference between Maturity Date and Today's Date is: "<<ptr_days<< " Days."<<endl;
cout<<"The difference between Maturity Date and Today's Date is: "<<ptr_years<< " Years."<<endl;
return 0;
}