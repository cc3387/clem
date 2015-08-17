#ifndef Array_H
#define Array_H

#include <iostream>
#include <typeinfo>

template <typename T> class Array{

private:

	int size;
	T *arr;

public:

	Array(int the_size); //Parameterized Constructor
	void setArray(int loc, T value);
	void getArray();
};


//Method Definition

template<class T> 
Array<T>::Array(int the_size){
size = the_size;
arr = new T [size];
}

template<class T>
void Array<T> :: setArray(int loc, T value){
arr[loc] = value;
}

template<class T>
void Array<T> :: getArray(){
	for(int i=0; i<size; i++){
	std::cout<<arr[i]<<" " << "Type: " << typeid(arr[i]).name()<<std::endl;
	}

	std::cout<<"------------------"<<std::endl;
}

#endif