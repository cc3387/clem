#include<iostream>
#include<cstdio>
using namespace std;

class Money{

private: 
	
	int num_of_dollar;
    int num_of_cents;

public:

	double dollar_amount;
	double cents;
	double cents_amount;
	double total_monetary;

	void set(int,int);
	void transform();
	double monetary_amount();
};


void Money::set(int a, int b){
   
   num_of_dollar = a;
   num_of_cents = b;
      
}

void Money::transform(){
  
	 dollar_amount = num_of_dollar;
	 cents = num_of_cents; //Pass the Integer into a double and then perform division
	 cents_amount = cents / 100; // Perform division so that the number of cents can return a double value in the end
	 total_monetary = dollar_amount + cents_amount;
	 cout << "Dollars Amount is: " << dollar_amount << endl;
	 cout << "Cents Amount is: " << cents_amount << endl;
}

double Money::monetary_amount(){
return total_monetary;
}


int main(){
    
	Money M;

	M.set(7,90);
	M.transform();
	cout<<"The total amount given input is: " << M.monetary_amount() << endl;

	M.set(90,150);
	M.transform();
	cout<<"The total amount given input is: " << M.monetary_amount() << endl;

}



