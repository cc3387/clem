#include "Predator.h"
#include "Ants.h"
#include "DoodleBug.h"

int main(){
	char ans;

	//Define the Grid
	Ants A;
	DoodleBug DB;

	//Create Predator Pointer
	Predator *P_1;
	Predator *P_2;

	P_1 = &A;
	P_2 = &DB;
	P_1->setgrid(20); //Initialize the grid
	P_2->setgrid(20); //Initialize the grid
	A.setcoord(100,5); //Set the number of Ants coordinates

	int size = A.get_size();
	char Grid[size][size]; //Set a pass on grid

	//Pass Grid from Ants to DoodleBug
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
		Grid[i][j] = A.get_grid(i,j);
		DB.intakegrid(Grid[i][j],i,j);
		}
	}

	//Set DoodleBug coordinates
	DB.setcoord(5);
	
	//Displate the combined grid
    std::cout<< "The original grid with 100 ants and 5 doodlebugs is: " << std::endl;
	P_2->DisplayGrid();


    do{
	P_2 -> move();
	DB.starve();
	DB.make_new_coord();
	P_2 -> Breed();

	//Transfer everything to A
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
		Grid[i][j] = DB.get_grid(i,j);
		A.intakegrid(Grid[i][j],i,j);
		}
	}

	P_1 -> move();
	P_1 -> Breed();

    std::cout<< "After the move, the grid becomes: " << std::endl;
	P_1->DisplayGrid();
    
	//Transfer everything to DB
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
		Grid[i][j] = P_1->get_grid(i,j);
		DB.intakegrid(Grid[i][j],i,j);
		}
	}
	
	std::cout<< "Do you want to continue? (y/n) " << std::endl;
	std::cin >> ans;
	}while(ans=='Y' || ans =='y');
}