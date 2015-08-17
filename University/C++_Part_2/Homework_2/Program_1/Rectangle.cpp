#include <string>
#include <cstdlib>
#include <iostream>
#include "Rectangle.h"

const char* rectangle :: erase(){
return "This is erase from class rectangle!";
}

const char* rectangle :: draw(){
return "This is draw from class rectangle!";
std::cout<<" "<<std::endl;
}

void rectangle :: center(){
std::cout<<"Center is called from rectangle..."<<std::endl;
std::cout<<erase()<<std::endl;
std::cout<<draw()<<std::endl;
}