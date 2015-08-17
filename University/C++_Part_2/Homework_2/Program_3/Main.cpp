#include "Shape.h"

int main(){
    
	Square Sq;
	Sq.set_side(5);
	Rectangle Rect;
	Rect.set_side(4.5,4);
	Triangle Tri;
	Tri.set_bh(5.5,3);
	Circle Circ;
	Circ.set_radius(2.5);

	Shape *S1 = &Sq;
	std::cout<<"The area of Square is: " << S1 -> Area() << std::endl;
	Shape *S2 = &Rect;
	std::cout<<"The area of Rectangle is: " << S2 -> Area() << std::endl;
	Shape *S3 = &Tri;
	std::cout<<"The area of Triangle is: " << S3 -> Area() << std::endl;
	Shape *S4 = &Circ;
	std::cout<<"The area of Circle is: " << S4 -> Area() << std::endl;
	
}