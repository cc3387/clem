#include <string>
#include <cstdlib>
#include <iostream>
#include "Figure.h"

const char* figure :: erase(){
return "This is erase from class figure!";
}

const char* figure :: draw(){
return "This is draw from class figure!";
}

void figure :: center(){
std::cout<<"Center is called from figure..."<<std::endl;
std::cout<<erase()<<std::endl;
std::cout<<draw()<<std::endl;
}