#include <iostream>
#include <string>
using namespace std;

//The get product function

int getProductID(int ids[], string names[], int numProducts, string target){

	for(int i=0; i<numProducts; i++){
	   
		if(names[i] == target){
		throw ids[i];
		}
		else
		if(names[i] != target && i == numProducts-1){
	    throw 'N';
		}
	}
}

int main(){

	int productIds[] = {4,5,8,10,13};
	string products[] = {"computer", "flash drive", "mouse", "printer", "camera"};

	try{
	getProductID(productIds, products, 5, "mouse");
	}catch(int a){
	cout << "The returned product id is: " << a << endl;
	}
	catch(...){
	cout << "There is no match on the input..." << endl;
	}

	try{
	getProductID(productIds, products, 5, "camera");
	}catch(int a){
	cout << "The returned product id is: " << a << endl;
	}
	catch(...){
	cout << "There is no match on the input..." << endl;
	}

	try{
	getProductID(productIds, products, 5, "laptop");
	}catch(int a){
	cout << "The returned product id is: " << a << endl;
	}
	catch(...){
	cout << "There is no match on the input..." << endl;
	}

	return 0;
}