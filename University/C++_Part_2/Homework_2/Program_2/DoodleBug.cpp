#include "DoodleBug.h"

DoodleBug :: DoodleBug(){
//Deliberately left empty
}

void DoodleBug:: setcoord(int numdb){
	
	srand(time(NULL));
	number_of_DB = numdb;

	DB_Coord = new int[number_of_DB];
	counter_starve = new int[number_of_DB];
	counter_DB = new int[number_of_DB];

	for(int i=0; i<number_of_DB; i++){
	DB_Coord[i] = 0;
	}

	for(int i=0; i<number_of_DB; i++){
	counter_starve[i] = 0;
	}

	for(int i=0; i<number_of_DB; i++){
	counter_DB[i] = 0;
	}


	DoodleBug_Coord = new int*[number_of_DB];
	
	for(int i=0; i<number_of_DB; i++){
	DoodleBug_Coord[i] = new int[2];
	}
	
	for(int i=0; i<number_of_DB; i++){

	  DoodleBug_Coord[i][0] = 0 + ( std::rand() % size); //Generate random numbers from 0 to 20
      DoodleBug_Coord[i][1] = 0 + ( std::rand() % size);

	  int x_coord = DoodleBug_Coord[i][0];
	  int y_coord = DoodleBug_Coord[i][1];

	  for(int k=0; k<i; k++){
	   
	  if(DoodleBug_Coord[k][0] == x_coord && DoodleBug_Coord[k][1] == y_coord){
	  int search = 0;
	  if((x_coord+1)>0 && (x_coord+1) < size && Grid[x_coord+1][y_coord] =='.' && Grid[x_coord+1][y_coord] !='O' && search == 0){
	  Grid[x_coord+1][y_coord] = 'X';
	  search++;}
	  else if((x_coord-1)>0 && (x_coord-1) < size && Grid[x_coord-1][y_coord] =='.' && Grid[x_coord-1][y_coord] !='O' && search == 0){
	  Grid[x_coord-1][y_coord] = 'X';
	  search++;}
	  else if((y_coord+1)>0 && (y_coord+1) < size && Grid[x_coord][y_coord + 1] =='.' && Grid[x_coord][y_coord + 1] !='O' && search == 0){
	  Grid[x_coord][y_coord + 1] = 'X';
	  search++;}
	  else if((y_coord-1)>0 && (y_coord-1) < size && Grid[x_coord][y_coord - 1] =='.' && Grid[x_coord][y_coord - 1] !='O' && search == 0){
	  Grid[x_coord][y_coord - 1] = 'X';
	  search++;}
	  else if((x_coord+1)>0 && (x_coord+1) < size && (y_coord + 1)>0 && (y_coord + 1) < size && Grid[x_coord + 1][y_coord + 1] =='.' && Grid[x_coord + 1][y_coord + 1] !='O' && search == 0){
	  Grid[x_coord + 1][y_coord + 1] = 'X';
	  search++;}
	  else if((x_coord - 1)>0 && (x_coord - 1) < size && (y_coord + 1)>0 && (y_coord + 1) < size && Grid[x_coord - 1][y_coord + 1] =='.' && Grid[x_coord - 1][y_coord + 1] !='O'  && search == 0){
	  Grid[x_coord - 1][y_coord + 1] = 'X';
	  search++;}
	  else if((x_coord+1)>0 && (x_coord+1) < size && (y_coord - 1)>0 && (y_coord - 1) < size && Grid[x_coord + 1][y_coord - 1] =='.' && Grid[x_coord + 1][y_coord - 1] !='O'  && search == 0){
	  Grid[x_coord + 1][y_coord - 1] = 'X';
	  search++;}
	  else if((x_coord - 1)>0 && (x_coord - 1) < size && (y_coord - 1)>0 && (y_coord - 1) < size && Grid[x_coord - 1][y_coord - 1] =='.' && Grid[x_coord - 1][y_coord - 1] !='O' && search == 0){
	  Grid[x_coord - 1][y_coord - 1] = 'X';
	  search++;}
	  }

	  };

	  MarkDBOnGrid(x_coord, y_coord);	
	}
}

void DoodleBug::MarkDBOnGrid(int x, int y){
	 Grid[x][y] = 'X';
}

void DoodleBug::MarkDBGrid(int x, int y){
	 Grid[x][y] = '.';
}

void DoodleBug::intakegrid(char antgrid, int x, int y){
 	 Grid[x][y] = antgrid;		 
}



void DoodleBug::move(){

	 srand(time(NULL));
     int x_coord;
	 int y_coord;
	 int temp;
	 int k;
	 
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

	 k = 0;

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


	 number_of_DB = k;

	 ant_ate = new int[number_of_DB];

	 for (int i=0; i < number_of_DB; i++){
	 counter_DB[i] = (counter_DB[i]+1)%8;

	 int search = 0;
	 int coord_move = 0 + (std::rand() % 2);
	 int random_move = -1 + (std::rand() % 2);
	 if(random_move == 0){
	 random_move = 1;
	 }

	 //std::cout<<DoodleBug_Coord[i][0]<<","<<DoodleBug_Coord[i][1]<<std::endl;
	 //std::cout<<coord_move<<","<<random_move<<std::endl;
	 x_coord = DoodleBug_Coord[i][0];
	 y_coord = DoodleBug_Coord[i][1];

	 //std::cout<<x_coord<<","<<y_coord<<std::endl;

	 if(x_coord < size-1 && Grid[x_coord+1][y_coord]=='O' && search == 0){ //Adjacent Left
	 MarkDBGrid(x_coord,y_coord); //x_coord
	 if(x_coord== size -1 ){
	 x_coord = x_coord - 2;
	 }		 
	 DoodleBug_Coord[i][0] = x_coord + 1;
	 x_coord = DoodleBug_Coord[i][0];
	 MarkDBOnGrid(x_coord, y_coord);
	 search++;
	 ant_ate[i] += 1;
	 counter_starve[i] = 0; // reset counter starve
	 //std::cout<<counter_starve[i] << std::endl;
	 }

	 else if(x_coord > 1 && Grid[x_coord-1][y_coord]=='O' && search == 0){ //Adjacent Right
	 MarkDBGrid(x_coord,y_coord);
	 if(x_coord == 0){
	 x_coord = x_coord + 2;
	 }	
	 DoodleBug_Coord[i][0] = x_coord - 1;
	 x_coord = DoodleBug_Coord[i][0];
	 MarkDBOnGrid(x_coord, y_coord);
	 search++;
	 ant_ate[i] += 1;
	 counter_starve[i] = 0; // reset counter starve
	 //std::cout<<counter_starve[i] << std::endl;
	 }

	 else if(y_coord < size-1 && Grid[x_coord][y_coord+1]=='O' && search == 0){ //Adjacent Up
	 MarkDBGrid(x_coord,y_coord); //y_coord
	 if(y_coord == size -1){
	 y_coord = y_coord - 2;
	 }	
	  
	 DoodleBug_Coord[i][1] = y_coord+1;
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBOnGrid(x_coord, y_coord);
	 search++;
	 ant_ate[i] += 1;
	 counter_starve[i] = 0; // reset counter starve
	 //std::cout<<counter_starve[i] << std::endl;
	 }

 	 else if(y_coord > 1 && Grid[x_coord][y_coord-1]=='O' && search == 0){ //Adjacent Down
	 MarkDBGrid(x_coord,y_coord); //y_coord
	 if(y_coord == 0){
	 y_coord = y_coord + 2;
	 }	
	 DoodleBug_Coord[i][1] = y_coord-1;
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBOnGrid(x_coord, y_coord);
	 search++;
	 ant_ate[i] += 1;
	 counter_starve[i] = 0; // reset counter starve
	 //std::cout<<counter_starve[i] << std::endl;
	 }

	 else if(coord_move == 0){
	 temp = DoodleBug_Coord[i][0];

	 //std::cout<<"This is temp: " << temp << std::endl;

	 if(temp == 0){
	 temp = 1;
	 }else if(temp == size - 1){
	 temp = size - 2;	 
	 }

	 temp += random_move;
	 
	 y_coord = DoodleBug_Coord[i][1]; //Move y-axis location
	 
	 if(temp < 0 || temp > size - 1 || Grid[temp][y_coord] == 'X'){
	 x_coord = DoodleBug_Coord[i][0]; //If the temp moved out of scope, nothing changed
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBOnGrid(x_coord, y_coord);
	 ant_ate[i] -= 1;
	 counter_starve[i]+=1;
	 counter_starve[i] = counter_starve[i] %3;
	 //std::cout<<counter_starve[i] << std::endl;
	 }
	 else if (Grid[temp][y_coord] == '.'){
	 x_coord = DoodleBug_Coord[i][0]; //If the temp is not out of scope, replace 'X' with '.' and write 'X' in new grid
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBGrid(x_coord, y_coord);
	 DoodleBug_Coord[i][0] = temp;
	 x_coord = DoodleBug_Coord[i][0];
	 MarkDBOnGrid(x_coord, y_coord);
	 ant_ate[i] -= 1;
	 counter_starve[i]+=1;
	 counter_starve[i] = counter_starve[i] %3;
	 //std::cout<<counter_starve[i] << std::endl;
	 }

	 }
	 else if(coord_move == 1){
	 temp = DoodleBug_Coord[i][1];

	 //std::cout<<"This is temp: " << temp << std::endl;
	 
	 if(temp == 0){
	 temp = 1;
	 }else if(temp == size-1){
	 temp = size - 2;	 
	 }
	 temp += random_move;
	 x_coord = DoodleBug_Coord[i][0]; //Move x-axis location
	 
	 if(temp < 0 || temp > size - 1 || Grid[x_coord][temp] == 'X'){
	 x_coord = DoodleBug_Coord[i][0]; //If the temp moved out of scope and if any adjacent is occupied, nothing changed
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBOnGrid(x_coord, y_coord);
	 ant_ate[i] -= 1;
	 counter_starve[i]+=1;
	 counter_starve[i] = counter_starve[i] %3;
	 //std::cout<<counter_starve[i] << std::endl;
	 }
	 else if (Grid[temp][y_coord] == '.'){
	 x_coord = DoodleBug_Coord[i][0]; //If the temp is not out of scope, replace 'X' with '.' and write 'X' in new grid
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBGrid(x_coord, y_coord);
	 DoodleBug_Coord[i][1] = temp;
	 y_coord = DoodleBug_Coord[i][1];
	 MarkDBOnGrid(x_coord, y_coord);
	 ant_ate[i] -= 1;
	 counter_starve[i]+=1;
	 counter_starve[i] = counter_starve[i] %3;
	 //std::cout<<counter_starve[i] << std::endl;
	 }
	  
	 }
	 
	 //std::cout<<DoodleBug_Coord[i][0]<<","<<DoodleBug_Coord[i][1]<<std::endl;

	 }
}

void DoodleBug::Breed(){
	 
	 
	 int db_add = 0;
	 int db_add_1 = db_add;
	 int k;


	 for(int i=0; i<number_of_DB; i++){
		 if(counter_DB[i] == 0){
		 int x_coord = DoodleBug_Coord[i][0];
	     int y_coord = DoodleBug_Coord[i][1];
		 int search=0;

		 if((x_coord+1)>0 && (x_coord+1) < size && Grid[x_coord+1][y_coord] =='.' && search == 0){
		 Grid[x_coord+1][y_coord] = 'X';
		 db_add++;
		 search++;}
		 else if((x_coord-1)>0 && (x_coord-1) < size && Grid[x_coord-1][y_coord] =='.' && search == 0){
	     Grid[x_coord-1][y_coord] = 'X';
		 db_add++;
	     search++;}
	     else if((y_coord+1)>0 && (y_coord+1) < size && Grid[x_coord][y_coord + 1] =='.' && search == 0){
	     Grid[x_coord][y_coord + 1] = 'X';
		 db_add++;
	     search++;}
	     else if((y_coord-1)>0 && (y_coord-1) < size && Grid[x_coord][y_coord - 1] =='.' && search == 0){
		 Grid[x_coord][y_coord - 1] = 'X';
		 db_add++;
		 search++;}
	  
	 }//if statement
  }//for statement

	 k = 0;

	 for(int i=0; i<size; i++){
		for(int j=0; j<size;j++){
		if(Grid[i][j] == 'X'){
		k++;
		}
		}
	 }

	 number_of_DB = k;

	 delete[] counter_starve;
	 counter_starve = new int[number_of_DB];

	 for(int i=0; i<number_of_DB ; i++){
	 counter_starve[i] = 0;
	 }

	 
}

void DoodleBug::starve(){
	  
	 int k;
	
	 for(int i=0; i<number_of_DB; i++){
	   if(counter_starve[i] == 2){
	   int x_coord = DoodleBug_Coord[i][0];
	   int y_coord = DoodleBug_Coord[i][1];
	   MarkDBGrid(x_coord, y_coord);
	   DB_Coord[i] = 1;
	   } //for statement
	 } //if statement
}

void DoodleBug :: make_new_coord(){
	int count = 0;
    for(int i = 0; i<number_of_DB; i++){
		if(counter_starve[i] == 2){
	    std::cout<<"The dead bug is in location: "<< i <<std::endl;
		count+=1;
		}
	}

	int counter[count];
	int k = 0;

	for(int i = 0; i<number_of_DB; i++){
		if(counter_starve[i] == 2){
	   	counter[k] = i;  
		k++;
		}
	}

	for(int m=0; m<count; m++){
	if(counter[m] > 0 && counter[m] < number_of_DB){ //if the number is in the middle

	    DoodleBug_Coord_1 = new int*[number_of_DB-1];
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord_1[k] = new int[2];
		}

		for(int k=0; k<counter[m]; k++){
		DoodleBug_Coord_1[k] = DoodleBug_Coord[k];
		}
		
		for(int k=counter[m]+1; k<number_of_DB; k++){
		DoodleBug_Coord_1[k-1] = DoodleBug_Coord[k];
		}

		DoodleBug_Coord = new int*[number_of_DB-1];
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord[k] = new int[2];
		}
		
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord[k] = DoodleBug_Coord_1[k];
		}

		delete[] DoodleBug_Coord_1;
		number_of_DB -= 1;
		//std::cout<<number_of_DB<<std::endl;
      }
	  else if (counter[m] ==0){ //When the location is at the front
		DoodleBug_Coord_1 = new int*[number_of_DB-1];
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord_1[k] = new int[2];
		}

		for(int k=1; k<counter[m]; k++){
		DoodleBug_Coord_1[k-1] = DoodleBug_Coord[k];
		}
		
		DoodleBug_Coord = new int*[number_of_DB-1];
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord[k] = new int[2];
		}
		
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord[k] = DoodleBug_Coord_1[k];
		}

		//delete[] DoodleBug_Coord_1;
		number_of_DB -= 1;
	  }
	  else if(counter[m] == number_of_DB){ // if the number is at the end
        DoodleBug_Coord_1 = new int*[number_of_DB-1];
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord_1[k] = new int[2];
		}

		for(int k=0; k<counter[m] ; k++){
		DoodleBug_Coord_1[k] = DoodleBug_Coord[k];
		}
		
		DoodleBug_Coord = new int*[number_of_DB-1];
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord[k] = new int[2];
		}
		
		for(int k=0; k<number_of_DB-1; k++){
		DoodleBug_Coord[k] = DoodleBug_Coord_1[k];
		}

		//delete[] DoodleBug_Coord_1;
		number_of_DB -= 1;
		}
	}
}




DoodleBug :: ~DoodleBug(){
std::cout << "Initiating Ants (Derived) Destructor ... " << std::endl;
delete[] *DoodleBug_Coord;
delete[] ant_ate;
delete[] counter_DB;
delete[] counter_starve;
}