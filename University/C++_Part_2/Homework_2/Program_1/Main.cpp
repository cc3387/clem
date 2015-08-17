#include <iostream>
#include "figure.h"
#include "Rectangle.h"
#include "Triangle.h"

int main(){
	
	triangle tri;
	figure *fig = &tri;
	fig->draw();
	std::cout <<
		"\nDerived class Triangle object calling center()\n";
	fig->center();

	rectangle rect;
	figure *fig1 = &rect;
	fig1->draw();
	std::cout <<
		"\nDerived class Triangle object calling center()\n";
	fig1->center();


}