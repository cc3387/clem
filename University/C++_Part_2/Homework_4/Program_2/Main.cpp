#include <iostream>
#include <string>
using namespace std;

class Account{

private:
	double balance;

public:
	
	//Constructor
	Account(){
	balance = 0;
	}

	//Parameterized Constructor
	Account(double initialDeposit){
	balance = initialDeposit;
	}


	//Getter
	double getBalance(){
	return balance;
	}

	
	//Inputting deposit function
	double deposit(double amount){

	if(amount > 0){
	balance += amount;
	return getBalance();
	}else if(amount == 0){
	return getBalance();
	}else{
	throw 'N';
	}

	}

	//Withdrawing deposit function
	double withdrawal(double amount){

	if(amount > balance || amount < 0){
	throw 'N';
	}else{
	balance -= amount;
	return getBalance();
	}
	
	}

};



int main(){

	Account A1;
	int dollar;
	char DW;
	char ans;

	do{
	
	cout << "Please choose if you want to deposit or withdraw: (D-deposit, W-withdraw): " << endl;
	cin >> DW;

	try{

	if(DW == 'D' || DW == 'd'){
	
		try{
		cout<< "Please enter the amount you want to deposit in: " << endl;
		cin >> dollar;
		cout << "The total deposit now is: " << A1.deposit(dollar)<< " dollars "<<endl;;
		}catch(...){
		cout << "There is an error in deposit ... Deposit cannot be below zero " <<endl;
		exit(1);
	   }
	}
	
	else if(DW =='W' || DW == 'w'){
	
		try{
		cout<< "Please enter the amount you want to withdraw: " << endl;
		cin >> dollar;
		cout << "The total deposit now is: " << A1.withdrawal(dollar)<< " dollars "<<endl;;
		}catch(...){
		cout << "There is an error withdrawal ... Withdrawl cannot be zero or exceed balance " <<endl;
		exit(1);
		}
	}
	
	else{
	throw 0 ;
	}
	}
	catch(int a){
	cout << "Please enter a choice in D/W" << endl;
	exit(1);
	}	

	cout << "Continue? (Y/N)" << endl;
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	return 0;
}