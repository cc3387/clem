#include "Question_4.h"

//Constructor
DynamicStringArray::DynamicStringArray(){
size = 0;
dynamicarray = NULL;
}

//Add entry into the dynamic array and replay dynamicarray initialized
void DynamicStringArray::AddEntry(std::string a){

size += 1; 
std::cout<<"Size is : " << size << std::endl;
std::string *dynamicarray_1;
dynamicarray_1 = new std::string[size];
for(int i = 0; i < size - 1 ; i++){
dynamicarray_1[i] = dynamicarray[i];
}
dynamicarray_1[size-1] = a;
dynamicarray = dynamicarray_1;

for(int i=0 ; i < size ; i++){
std::cout<<dynamicarray[i]<<std::endl;
}

}

//Delete entry into the dynamic array and replay dynamicarray initialized
void DynamicStringArray::DeleteEntry(std::string b){

	bool value;
	int index;
	int size_1 = size-1;

	std::string *dynamicarray_1;
	dynamicarray_1 = new std::string[size_1];

	for(int i = 0 ; i < size; i++){
	if(dynamicarray[i] == b){
	index = i;
	value = true;
	}
	}
	
	std::cout<<"The value is: " << value << std::endl;
	std::cout<<"The index is: " << index << std::endl;

	if(value == 1){
	//Condition 1 if the chosen name is at the start of the array
	if(index == 0){
	for(int i = 1; i < size; i++){
	dynamicarray_1[i-1] = dynamicarray[i];
	}
	}

	//Condition 2 if the chosen name is at the end of the array
	if(index == size-1){
	for(int i = 0; i < size-1; i++){
	dynamicarray_1[i] = dynamicarray[i];
	}
	}


	//Condition 3 if the chosen name is in the middle of the array
	if(index != 0 || index != (size-1)){
	for(int i = 0; i < index; i++){
	dynamicarray_1[i] = dynamicarray[i];
	}
	for(int i = (index+1); i < size; i++){
	dynamicarray_1[i-1] = dynamicarray[i];
	}
	}
	
	//Define the new dynamic array
	dynamicarray = new std::string[size_1];
	//Copy all the value over from array_1
	for(int i = 0; i < size_1; i++){
	dynamicarray[i] = dynamicarray_1[i];
	}
	}
	else{
	std::cout<<"There is no match for the delete entry.."<< std::endl;
	}

	std::cout<<"The list after deleting output is: ";
	for(int i=0 ; i < size_1 ; i++){
	std::cout<<dynamicarray[i]<< " ";
	}
	std::cout<<" " << std::endl;

	//Change the size of the array, mark down for the next delete
	size = size_1;
}

//Get Entry Function

std::string DynamicStringArray::GetEntry(int c){
return dynamicarray[c-1];
}

//Operator Overloading
DynamicStringArray& DynamicStringArray::operator =(const DynamicStringArray &p){
	std::cout<<"Initiating Copy Constructor..."<<std::endl;
	size = p.size;
	dynamicarray = new std::string[size];
	for(int i = 0; i < size; i++){
	dynamicarray[i] = p.dynamicarray[i];
	std::cout<<"The copied dynamic array strings are: " << dynamicarray[i] <<std::endl;
	}
}





//Destructor
DynamicStringArray::~DynamicStringArray(){
std::cout<<"Initiating Destructors..."<<std::endl;
delete[] dynamicarray;	
}


int main(){

	DynamicStringArray DSA, DSA_1;
	DSA.AddEntry("Clem");
	DSA.AddEntry("John");
	DSA.AddEntry("Spencer");
	DSA.AddEntry("Portia");
	std::cout<<"The dynamic array with the entered index is: "<< DSA.GetEntry(3) << std::endl;
	std::cout<<"The dynamic array with the entered index is: "<< DSA.GetEntry(1) << std::endl;	
	
	//Deleting Entry
	DSA.DeleteEntry("Clem");
	DSA.DeleteEntry("Portia");
	
	//Copying 
	DSA_1 = DSA;
	return 0;
}