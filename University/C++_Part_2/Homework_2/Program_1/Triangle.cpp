#include <string>
#include <cstdlib>
#include <iostream>
#include "Triangle.h"

const char* triangle :: erase(){
return "This is erase from class triangle!";
}

const char* triangle :: draw(){
return "This is draw from class triangle!";
std::cout<<" "<<std::endl;
}

void triangle :: center(){
std::cout<<"Center is called from triangle..."<<std::endl;
std::cout<<erase()<<std::endl;
std::cout<<draw()<<std::endl;
}