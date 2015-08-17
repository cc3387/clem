#include <iostream>
#include <fstream>

using namespace std;


inline int Max(int a, int b){
if(b>a){
return b;
}else{
return a;
}
}

inline int Min(int a, int b){
if(b<a){
return b;
}else{
return a;
}
}

int main(){

    ifstream Instream;
	int n = 1; //Counter
	int Maximum = 0;
	int Minimum = 0;
	int temp;
	
	Instream.open("Integer.txt");
    if(Instream.is_open()){
	cout<<"The Stream is Opened..."<<endl;
	}else{
	cout<<"There is no file to open..."<<endl;
	exit(1);
	}

	while(!Instream.eof()){ // Instream numbers
	Instream >> temp;
	
    if(n == 1){
	Maximum = temp;
	Minimum = temp;
	}
	
	Maximum = Max(Maximum, temp);
	Minimum = Min(Minimum, temp);
	n++;
	}
	
	Instream.close();
	
	//Summary
	cout<<"The number of integers in the file is: " << n << endl;
	cout<<"The maximum of the streamed file array of integer is: "<< Maximum << endl;
	cout<<"The minimum of the streamed file array of integer is: "<< Minimum << endl;
	
	return 0;
}