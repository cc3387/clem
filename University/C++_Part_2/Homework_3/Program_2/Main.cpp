#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream Instream;
	int n = 1; //Counter
	double Sum = 0;
	double temp;
	
	Instream.open("Double.txt");
    if(Instream.is_open()){
	cout<<"The Stream is Opened..."<<endl;
	}else{
	cout<<"There is no file to open..."<<endl;
	exit(1);
	}

	while(!Instream.eof()){ // Instream numbers
	Instream >> temp;
	Sum += temp;
	n++;
	}
	
	Instream.close();
	
	//Summary
	cout<<"The number of integers in the file is: " << n << endl;
	cout<<"The average of the streamed file array of double is: "<< Sum/n << endl;	
	return 0;
}