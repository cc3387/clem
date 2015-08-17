#ifndef DoodleBug_H
#define DoodleBug_H

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "Predator.h"


class DoodleBug : public Predator{

protected:
	int number_of_DB;
	int *ant_ate;
	int *DB_Coord;

public:
	DoodleBug(); //Default Constructor
	void setcoord(int numdb);
	void intakegrid(char antgrid, int x, int y);
	void MarkDBOnGrid(int x, int y); //Mark where the ants is
	void MarkDBGrid(int x, int y); //Mark where the ants moved to
	void starve(); //Only Doodlebug has it
	void make_new_coord();
	~DoodleBug(); // Destructor to destroy grid

	//Virtual Functions overloading
	void move();
	void Breed();

};

#endif

