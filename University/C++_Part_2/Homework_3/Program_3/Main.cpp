#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SortnOut(double list[], int size, char* file){
	   
	   int j;
	   double temp;

	   for(int i=1; i<size; i++){
		  temp = list[i];
		  for(int j = i-1; j>=0; j--){
			  if(list[j] > temp){
			  list[j+1] = list[j];
			  list[j] = temp;
			  } 
		  }
	   }

	for(int i=0; i<size; i++){
	cout<<list[i]<<endl;
	}

	ofstream Outfile(file);
	for(int i=0; i<size; i++){
	if(i != size - 1){
	Outfile << list[i]<< "," << endl;
	}else{
	Outfile << list[i] << " ";
	}
	}

	Outfile.close();
}

int main(){

    ifstream Instream("Integer.txt"), Instream_2("Double.txt");
	int n = 1; //Integer File Counter
	int n1 = 1; //Double File Counter
	string temp;
	string temp1;
	double number;
	double number1;


	//Check if Integer file is open
    if(Instream.is_open()){
	cout<<"The Stream is Opened..."<<endl;
	}else{
	cout<<"There is no file to open..."<<endl;
	exit(1);
	}
	
	//Check if Double file is open
    if(Instream_2.is_open()){
	cout<<"The Stream is Opened..."<<endl;
	}else{
	cout<<"There is no file to open..."<<endl;
	exit(1);
	}
	
	while(!Instream.eof()){ // Counter the number of lines
	getline(Instream, temp);
	n++;
	}
	
	while(!Instream_2.eof()){ // Counter the number of lines
	getline(Instream_2, temp1);
	n1++;
	}
	
	Instream.close();
	Instream_2.close();


	ifstream Instream_1("Integer.txt"), Instream_3("Double.txt");
	
	int total = n+n1-1;

	double arr[n];
	double arr1[n1];
	double arr_total[total];

	n = 1;
	n1 = 1;

	while(!Instream_1.eof()){ // Counter the number of lines
	getline(Instream_1, temp);
	number = atof(temp.c_str());
	arr[n-1] = number;
	n++;
	}
	
	while(!Instream_3.eof()){ // Counter the number of lines
	getline(Instream_3, temp1);
	number1 = atof(temp1.c_str());
	arr1[n1-1] = number1;
	n1++;
	}

	for(int i=0; i<total; i++){
	   if(i < n){
		arr_total[i] = arr[i];
	   }else{
		arr_total[i-1] = arr1[i-n];
	   }
	}
	
	SortnOut(arr_total, total-1, "Sorted.txt");

	Instream_1.close();
	Instream_3.close();

	return 0;
}