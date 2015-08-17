#include <iostream>
#include "Hotdog.h"
using namespace std;

//Method Definitions

HotdogSt::HotdogSt(int a, int b){
ID = a;
num_hd_sold = b;
total_hd_sold += b;
}

void HotdogSt::JustSold(){
cout << "Hotdog Stand " << ID << " just sold a hot dog !" << endl;
num_hd_sold += 1;
total_hd_sold += 1;
}

void HotdogSt::getStandSold(){
cout << "Hotdog Stand " << ID << " now sold " << num_hd_sold << " hot dogs" << endl;
}

int HotdogSt::getID(){
return ID;
}

int HotdogSt::display_total(){
cout<<"The combined hot dog sold now is : ";
return total_hd_sold;
}


int main(){

	HotdogSt HDT1(1,20), HDT2(2,30), HDT3(3,40);
	cout<<HDT3.display_total()<<endl;
	HDT1.JustSold();
	HDT2.JustSold();
	HDT2.JustSold();
	HDT2.JustSold();
	HDT3.JustSold();
	HDT1.getStandSold();
	HDT2.getStandSold();
	HDT3.getStandSold();
	cout<<HDT1.display_total()<<endl;
}
