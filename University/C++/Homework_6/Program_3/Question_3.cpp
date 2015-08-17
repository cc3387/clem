#include "Question_3.h"

void Student::input(){
std::string a;
int b;
std::string c;

std::cout<<"Enter Student's Name: " << std::endl;
std::cin >> a;
name = a;

std::cout<<"Enter the number of classes he is studying: " << std::endl;
std::cin >> b;
numclasses = b;

classlist = new std::string[numclasses];

for (int i = 0; i < numclasses ; i++){
std::cout<<"Enter the class names: " << std::endl;
std::cin >> c;
classlist[i] = c;
}


}

void Student::output(){
std::cout<<"The name of the student is: " << name << std::endl;
std::cout<<"The number of classes he/she is taking is: " << numclasses << std::endl;
for(int i = 0; i < numclasses ; i++){
std::cout<<"The classes he/she is taking are: " << classlist[i] << std::endl;
}
}

void Student::reset(){
std::cout<<" " <<std::endl;
std::cout<<"Calling reset function, reseting list..."<<std::endl;
numclasses = 0;
delete [] classlist;
classlist = new std::string[numclasses];
std::cout<<"Reset Number of Classes to: " << numclasses << std::endl;
}

Student& Student::operator =(const Student& p){
	std::cout<<" "<<std::endl;
	std::cout<<"Overloading '=' operator, Copying...."<<std::endl;
	name = p.name;
	numclasses = p.numclasses;
	classlist = new std::string[numclasses];


	for(int i = 0; i < numclasses; i++){
	classlist[i] = p.classlist[i];
	}


}


Student::~Student(){
std::cout<<" "<<std::endl;
std::cout<<"Initializing destructor"<<std::endl;
delete[] classlist;
}

int main(){
	//Initiating Student S and Student S1, S1 will be a copied class
	Student S, S1;
	
	S.input();
	S.output();

	//Copying using the operand "="
	S1 = S;
	S1.output();

	//Reseting
	S.reset();
	S1.reset();

}