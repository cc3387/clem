#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <iostream>
#include "figure.h"

class triangle : public figure{
	
public:
	const char* erase();
	const char* draw();
	void center();
};

#endif

