#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <iostream>
#include "figure.h"

class rectangle : public figure{

public:
	const char* erase();
	const char* draw();
	void center();
};

#endif

