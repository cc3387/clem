#include "Ants.h"

Ants :: Ants(){
//Deliberately left empty
}

void Ants:: setcoord(int numants, int numDB){
	
	srand(time(NULL));
	number_of_ants = numants;
	counter = 0;
	doodle_counter = 0;

	Ants_Coord = new int*[number_of_ants];
	
	for(int i=0; i<number_of_ants; i++){
	Ants_Coord[i] = new int[2];
	}
	
	number_DB = numDB;

	DoodleBug_Coord = new int*[numDB];
	
	for(int i=0; i < numDB; i++){
	DoodleBug_Coord[i] = new int[2];
	}



	for(int i=0; i<number_of_ants; i++){

	  Ants_Coord[i][0] = 0 + ( std::rand() % size); //Generate random numbers from 0 to 20
      Ants_Coord[i][1] = 0 + ( std::rand() % size);

	  int x_coord = Ants_Coord[i][0];
	  int y_coord = Ants_Coord[i][1];

	  for(int k=0; k<i; k++){
	   
	  if(Ants_Coord[k][0] == x_coord && Ants_Coord[k][1] == y_coord){
	  int search = 0;
	  if((x_coord+1)>0 && (x_coord+1) < size && Grid[x_coord+1][y_coord] =='.' && search == 0){
	  Grid[x_coord+1][y_coord] = 'O';
	  search++;}
	  else if((x_coord-1)>0 && (x_coord-1) < size && Grid[x_coord-1][y_coord] =='.' && search == 0){
	  Grid[x_coord-1][y_coord] = 'O';
	  search++;}
	  else if((y_coord+1)>0 && (y_coord+1) < size && Grid[x_coord][y_coord + 1] =='.' && search == 0){
	  Grid[x_coord][y_coord + 1] = 'O';
	  search++;}
	  else if((y_coord-1)>0 && (y_coord-1) < size && Grid[x_coord][y_coord - 1] =='.' && search == 0){
	  Grid[x_coord][y_coord - 1] = 'O';
	  search++;}
	  else if((x_coord+1)>0 && (x_coord+1) < size && (y_coord + 1)>0 && (y_coord + 1) < size && Grid[x_coord + 1][y_coord + 1] =='.' && search == 0){
	  Grid[x_coord + 1][y_coord + 1] = 'O';
	  search++;}
	  else if((x_coord - 1)>0 && (x_coord - 1) < size && (y_coord + 1)>0 && (y_coord + 1) < size &&Grid[x_coord - 1][y_coord + 1] =='.' && search == 0){
	  Grid[x_coord - 1][y_coord + 1] = 'O';
	  search++;}
	  else if((x_coord+1)>0 && (x_coord+1) < size && (y_coord - 1)>0 && (y_coord - 1) < size &&Grid[x_coord + 1][y_coord - 1] =='.' && search == 0){
	  Grid[x_coord + 1][y_coord - 1] = 'O';
	  search++;}
	  else if((x_coord - 1)>0 && (x_coord - 1) < size && (y_coord - 1)>0 && (y_coord - 1) < size && Grid[x_coord - 1][y_coord - 1] =='.' && search == 0){
	  Grid[x_coord - 1][y_coord - 1] = 'O';
	  search++;}
	  }

	  };

	  MarkAntsOnGrid(x_coord, y_coord);	
	}
}

void Ants::MarkAntsOnGrid(int x, int y){
	 Grid[x][y] = 'O';
}

void Ants::MarkMoveGrid(int x, int y){
	 Grid[x][y] = '.';
}


void Ants::move(){
	 
	 srand(time(NULL));
     int x_coord;
	 int y_coord;
	 int temp;
	 int k;
	 int k1;
	 counter = (counter+1)%3;

	 //Updating all the DoodleBug's Location
	 k = 0;

	 for(int i=0; i<size; i++){
		for(int j=0; j<size;j++){
		if(Grid[i][j] == 'X'){
		k++;
		}
		}
	 }
	 
	 delete[] *DoodleBug_Coord;
	 DoodleBug_Coord = new int*[k];

	 for(int i=0; i<k; i++){
	 DoodleBug_Coord[i] = new int[2];
	 }
	 
	 k1 = 0;

	 for(int i=0; i<size; i++){
		for(int j=0; j<size;j++){
		if(Grid[i][j] == 'O'){
		k1++;
		}
		}
	 }
	 

	 delete[] *Ants_Coord;
	 Ants_Coord = new int*[k1];

	 for(int i=0; i<k1; i++){
	 Ants_Coord[i] = new int[2];
	 }

	 k = 0; //reset k to 0

	 for(int i=0; i<size; i++){
		for(int j=0; j<size;j++){
		if(Grid[i][j] == 'X'){
		DoodleBug_Coord[k][0] =0;
		DoodleBug_Coord[k][0] =i;
		DoodleBug_Coord[k][1] =0;
		DoodleBug_Coord[k][1] =j;
		k++;
		}
		}
	 }
	 
	 k1 = 0; //reset k1 to 0

	 for(int i=0; i<size; i++){
		for(int j=0; j<size;j++){
		if(Grid[i][j] == 'O'){
		Ants_Coord[k1][0] =0;
		Ants_Coord[k1][0] =i;
		Ants_Coord[k1][1] =0;
		Ants_Coord[k1][1] =j;
		k1++;
		}
		}
	 }
	 
	 number_of_ants = k1;

	 for(int i=0; i<number_of_ants; i++){
		 x_coord = Ants_Coord[i][0];
		 y_coord = Ants_Coord[i][1];

		 int coord_move = 0 + (std::rand() % 2);
	     int random_move = -1 + (std::rand() % 2);
	     if(random_move == 0){
	     random_move = 1;
	     }
		 
		 for(int j=0; j<k;j++){
		 if((x_coord + random_move == DoodleBug_Coord[j][0] && y_coord == DoodleBug_Coord[j][1]) ||
			(y_coord + random_move == DoodleBug_Coord[j][1] && x_coord == DoodleBug_Coord[j][0]) ||
			x_coord + random_move >= size-1 || x_coord + random_move <= 0 || y_coord + random_move >=size -1 || y_coord+random_move <=0){
		 MarkAntsOnGrid(x_coord,y_coord);
		 }
		 else{
		 if(coord_move == 0 && Grid[x_coord+random_move][y_coord] != 'X'){
		 MarkAntsOnGrid(x_coord+random_move, y_coord);
		 if(Grid[x_coord][y_coord] != 'X'){
         MarkMoveGrid(x_coord, y_coord);
		 }
		 }else if(coord_move == 1 && Grid[x_coord][y_coord+random_move] != 'X'){
		 MarkAntsOnGrid(x_coord, y_coord + random_move);
		 if(Grid[x_coord][y_coord] != 'X'){
         MarkMoveGrid(x_coord, y_coord);
		 }
		 }
		 }
		 

		 }
	 }	 
}

void Ants::Breed(){
	 if(counter == 2){
	 
	 int ants_add = 0;
	 int ants_add_1 = ants_add;


	 for(int i=0; i<number_of_ants; i++){
		 int x_coord = Ants_Coord[i][0];
	     int y_coord = Ants_Coord[i][1];
		 int search=0;

		 if(x_coord == 0){x_coord =1;}; 
		 if(x_coord == size - 1){x_coord = size-2;};
		 if(y_coord == 0){y_coord = 1;};
		 if(y_coord == size - 1){y_coord = size-2;};

		 if((x_coord+1)>0 && (x_coord+1) < size-1 && Grid[x_coord+1][y_coord] =='.' && Grid[x_coord+1][y_coord] !='X' && search == 0){
		 Grid[x_coord+1][y_coord] = 'O';
		 ants_add++;
		 search++;}
		 else if((x_coord-1)>0 && (x_coord-1) < size-1 && Grid[x_coord-1][y_coord] =='.' && Grid[x_coord-1][y_coord] !='X'  && search == 0){
	     Grid[x_coord-1][y_coord] = 'O';
		 ants_add++;
	     search++;}
	     else if((y_coord+1)>0 && (y_coord+1) < size-1 && Grid[x_coord][y_coord + 1] =='.' && Grid[x_coord][y_coord+1] !='X'  && search == 0){
	     Grid[x_coord][y_coord + 1] = 'O';
		 ants_add++;
	     search++;}
	     else if((y_coord-1)>0 && (y_coord-1) < size-1 && Grid[x_coord][y_coord - 1] =='.' && Grid[x_coord][y_coord-1] !='X'  && search == 0){
		 Grid[x_coord][y_coord - 1] = 'O';
		 ants_add++;
		 search++;}
	  
	 }//for statement
  } //if statement
}

void Ants::intakegrid(char grid, int x, int y){
 	 Grid[x][y] = grid;
	 doodle_counter = 0;
	 if(Grid[x][y] == 'X'){
	 DoodleBug_Coord[doodle_counter][0] = x;
	 DoodleBug_Coord[doodle_counter][1] = y;
	 //std::cout<< DoodleBug_Coord[doodle_counter][0] << "," <<DoodleBug_Coord[doodle_counter][1] << std::endl;
	 doodle_counter+=1;
	 }
}



Ants :: ~Ants(){
std::cout << "Initiating Ants (Derived) Destructor ... " << std::endl;
delete[] *Ants_Coord;
}