#include <iostream>

//Solve the Power Problem Iteratively
template<typename T>
T Power(T X, int N){
  
  char flag;
  int i=1;
  T X1=X;
  T Y=X;
  T Final;
  int m = N % 2;

  if(typeid(X) == typeid(flag)){
  throw flag;
  }

  if(m == 0){
  while(i < N/2){
  X1 *= X;
  Y *= X;
  i++;
  }
  return X1 * Y;
  }
  else{
  while(i < N/2){
  X1 *= X;
  Y *= X;
  i++;
  }
  return X1*Y*X;
  }
  
}

int main(){

	try{
    Power<char>('c',4);
	}
	catch(char m){
	std::cout << "Caught Exception --" << std::endl; 
	std::cout << "Cannot Calculate and Power 'char' " << std::endl; 
	std::cout << " " << std::endl; 
	}

	//Printing out integer
	std::cout << "The int power is: " << Power<int>(3,4) << std::endl;

	//Printing out double
	std::cout << "The double power is: " << Power<double>(3.54,4) << std::endl;

	//Printing out float
	std::cout << "The float power is: " << Power<float>(3.1,4) << std::endl;

	//Printing out long
	std::cout << "The long power is: " << Power<long>(2,3) << std::endl;
	
    return 0;
}