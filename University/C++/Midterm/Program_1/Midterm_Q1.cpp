#include <iostream>
#include <math.h>
using namespace std;

//Define the two arrays to be tested

const int MaxArr = 100;
const int MaxFib = 20;

float Array[MaxArr];
int Fib[MaxFib];
//Transferring float to int array
int arr[MaxArr];


inline void initarrays(){

//Define Array with 100
for (int i=0; i<MaxArr; i++){
Array[i] = i + 1;
}

//Converting Array from float to int
for (int i=0; i<MaxArr; i++){
arr[i] = int(Array[i]);
}


//Define Array with Fibonacci sequence
Fib[0] = 0;
Fib[1] = 1;
for (int i=2; i < MaxFib; i++){
Fib[i] = Fib[i-1] + Fib[i-2];
}

}


float Mean(int arr[], int Size){

	float sum;
	float average;

	for(int i=0; i<Size; i++){
	sum += arr[i];
	}

	average = sum / Size;
	return average;
}

float Mean(float arr[], int Size = 10){

	float sum;
	float average;

	for(int i=0; i<Size; i++){
	sum += arr[i];
	}

	average = sum / Size;
	return average;
}

float SD(int arr[], int Size){

	float sumstd[Size];
	float sumstdfinal;
	float std;

	double average = Mean(arr,Size);

	double average_1 = double(average);

	cout<<"Calling Mean Function from SD: " << average_1<<endl;

	for(int i=0; i < Size; i++){
    sumstd[i] = (arr[i] - average_1)*(arr[i] - average_1);
	}
	
	sumstdfinal = 0;

	for(int i=0; i < Size; i++){
	sumstdfinal += sumstd[i];
	}

	std = sqrt(sumstdfinal / Size);
	return std;
}

float SD(float arr[], int Size = 10){
    
	//delete previous result
	float ave;
	float sumstd[Size];
	float sumstdfinal;
	float std;
	
    ave = Mean(arr);

    for(int i=0; i < Size; i++){
    sumstd[i] = (arr[i] - ave)*(arr[i] - ave);
	}

	sumstdfinal = 0;

	for(int i=0; i < Size; i++){
	sumstdfinal += sumstd[i];
	}

	std = sqrt(sumstdfinal / Size);
	return std;
}


int main(){

//First initiate all value
initarrays();

//Deliver the results after array initialization
cout << "The mean for int Array[100] is: " << Mean(arr, MaxArr) <<endl;
cout << "The Standard Deviation for int Array[100] is: " << SD(arr, MaxArr)<<endl;	
cout << "The mean for Fib[20] is: " << Mean(Fib, MaxFib) <<endl;
cout << "The Standard Deviation for Fib[20] is: " << SD(Fib, MaxFib) <<endl;
cout << "The Standard Deviation for float Array[10] is: " << SD(Array) <<endl;
}