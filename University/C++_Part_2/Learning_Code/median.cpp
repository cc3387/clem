#include <iostream>

//Perform an insertion sort
void sort(int arr[], int size){

	for(int i=0; i<size; i++){ 
	   
	   int temp = arr[i]; // Pick one number
	   int j = i; //Assign another counter operator for the comparison loop, start with i

	   while(j > 0 && arr[j-1] > temp){ //start with the assigned value
	   arr[j] = arr[j-1];
	   j--;
	   arr[j] = temp;
	   }
	}
}


double getMedian(int sorted_arr[], int size){

	   double Median;

	   if((size%2) ==0){
	   Median = (sorted_arr[size/2] + sorted_arr[size/2 - 1])/2;
	   }
	   else{
	   Median = sorted_arr[size/2];
	   }
	   return Median;
}

double getmode(int arr[], int size){

	int *repetitionarr = new int[size];

	for(int i=0; i<size; i++){
	repetitionarr[i] = 0;
	int j = 0;
	bool repfound = false;
	while(j<i && arr[j] != arr[i]){
	if(arr[j] != arr[i]){
	++j;
	}
	}
	++(repetitionarr[j]);
	}
	
	int maxrepeat = 0;

	for(int i=0; i<size; i++){
	if(repetitionarr[i] > repetitionarr[maxrepeat]){
	maxrepeat = i;
	}
	}

	delete[] repetitionarr;
	return arr[maxrepeat];
}

void print_array (int arr[], int size){

	 std::cout << "The numbers in the array are: " << std::endl;

     for(int i=0; i<size; i++){
	 std::cout<< arr[i] << std::endl;
	 }
}



int main(){

	int arr_1[10] = {1,3,10,5,4,8,12,5,6,7};
	sort(arr_1, 10);
	std::cout << " "<< std::endl;
	print_array(arr_1,10);
	std::cout << " "<< std::endl;
	std::cout << "The Median is: " << getMedian(arr_1,10) << std::endl;
	std::cout << "The Mode is: " << getmode(arr_1, 10) << std::endl;
}
