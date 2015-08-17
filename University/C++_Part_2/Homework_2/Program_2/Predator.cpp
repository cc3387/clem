#include "Predator.h"

Predator :: Predator(){
counter = 0;
}

void Predator:: setgrid(int grid_size){
	
	size = grid_size;
	
	Grid = new char*[size];
	for(int i=0; i<size; i++){
	Grid[i] = new char[size];
	}
	
	for(int i=0; i<size; i++){
	   for(int j=0; j<size; j++){
	   Grid[i][j] = '.';
	 }
   }
}

void Predator :: DisplayGrid(){

	for(int i = 0; i < size; i++){
	   for(int j=0; j < size; j++){
	   if(j < size-1){
	   std::cout << Grid[i][j] << " ";
	   }else if (j = size-1){
       std::cout << Grid[i][j] << std::endl;
	   }
	  }
	}
}

char Predator :: get_grid(int x, int y){
return Grid[x][y];
}

int Predator :: get_size(){
return size;
}



Predator :: ~Predator(){
std::cout << "Initiating Predator (Base) Destructor ... " << std::endl;
delete[] *Grid;
}