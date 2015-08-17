#include<iostream>
#include<stdio.h>
using namespace std;

class CounterType{

private:
	
	int number;

public: 
	
	void SetCount(int);
	void IncreaseCount();
	void DecreaseCount();
	int ReturnCount();
	int Display();


};


void CounterType::SetCount(int a){
	number = a;
	if (number < 0){
    printf("The number entered is negative.");
	exit(0);
	}
}

void CounterType::IncreaseCount(){
	number += 1;
	if(number < 0){
    printf("The number becomes negative.");
	exit(0);
	}
}

void CounterType::DecreaseCount(){
	number -= 1;
	if(number < 0){
    printf("The number becomes negative.");
	exit(0);
	}
}

int CounterType::ReturnCount(){
return number;
}

int CounterType::Display(){
printf("The Count is %d", number);
}


int main(){
	
	int countinput;
	char InDe;
	char ans;
	CounterType CT;
	
	cout<<"Please enter the number: " <<endl;
	cin>>countinput;
	CT.SetCount(countinput);
	
	do{
	cout<<"Increase Count or Decrease Count? (I for increase, D for Decrease)"<<endl;
	cin >> InDe;
	
	if(InDe == 'D'){
	CT.DecreaseCount();
	}
	
	if(InDe == 'I'){
	CT.IncreaseCount();
	}

	CT.Display();
	cout << " " << endl;
	cout << "Increase and Decrease again?" << endl;
	cin >> ans;
	} while (ans =='Y'|| ans == 'y');

}



