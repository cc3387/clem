#ifndef Predator_H
#define Predator_H

#include <string>
#include <iostream>

class Predator{

protected:
	char **Grid;
	int **DoodleBug_Coord;
	int **DoodleBug_Coord_1;
	int **Ants_Coord;
	int size;
	int counter;
	int *counter_DB;
	int *counter_starve;

public:
	Predator(); //Default Constructor
	void setgrid(int grid_size);
	void DisplayGrid();
	char get_grid(int x, int y);
	int get_size();
	~Predator(); // Destructor to destroy grid

/***************Define Pure Virtual function to be extended to Ants and Bugs****************/
	virtual void move() = 0;
	virtual void Breed() = 0;
};

#endif

