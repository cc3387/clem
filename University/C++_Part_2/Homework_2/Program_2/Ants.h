#ifndef Ants_H
#define Ants_H

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "Predator.h"


class Ants : public Predator{

protected:
	int number_of_ants;
	int doodle_counter;
	int number_DB;
public:
	Ants(); //Default Constructor
	void setcoord(int numants, int numDB);
	void intakegrid(char antgrid, int x, int y);
	void MarkAntsOnGrid(int x, int y); //Mark where the ants is
	void MarkMoveGrid(int x, int y); //Mark where the ants moved to
	~Ants(); // Destructor to destroy grid

	//Virtual Functions overloading
	void move();
	void Breed();

};

#endif

