#include <stdio.h>
#include <iostream>
using namespace std;

//Define the size of rows and columns
const int Row = 7;
const int Col = 5;

char seatmap[Row][Col];

//Function designs
void seatmapdesign();
void DisplaySeat();
void InsertSeat(int &rows, char &columns, int &intcolumns);
void MarkSeat(int &rows, int &intcolumns);

int main(){
	
	int r;
	char c;
	char ans;
	int ic;

seatmapdesign();

do{
DisplaySeat();
InsertSeat(r, c, ic);
MarkSeat(r,ic);
DisplaySeat();
cout << "Mark Another seat? (y/n)" << endl;
cin >> ans;
}while (ans == 'y' || ans == 'Y');

return 0; 
}



void seatmapdesign(){
   
	for(int j = 0; j < Col ; j++){
	    
	   for(int i = 0; i < Row ; i++){

	   if(j == 0) {
	   
	   if(i == 0){
	   seatmap[i][j] = '1';
	   }

	   if(i == 1){
	   seatmap[i][j] = '2';
	   }

	   if(i == 2){
	   seatmap[i][j] = '3';
	   }

	   if(i == 3){
	   seatmap[i][j] = '4';
	   }

	   if(i == 4){
	   seatmap[i][j] = '5';
	   }

	   if(i == 5){
	   seatmap[i][j] = '6';
	   }

	   if(i == 6){
	   seatmap[i][j] = '7';
	   }

	   }

	   if(j == 1) {
	   seatmap[i][j] = 'A';
	   }

	   if(j == 2) {
	   seatmap[i][j] = 'B';
	   }

	   if(j == 3) {
	   seatmap[i][j] = 'C';
	   }

	   if(j == 4) {
	   seatmap[i][j] = 'D';
	   }
	   
	   };
    };

}

void DisplaySeat(){

	int j = 0;

	for(int i = 0; i < Row ; i++){
	cout<<seatmap[i][j]<< " " << seatmap[i][j+1] << " " << seatmap[i][j+2] << " " << seatmap[i][j+3]<< " " << seatmap[i][j+4] << endl;
	};
}

void InsertSeat(int &rows, char &columns, int &intcolumns){

cout << "Please enter the seat row: " << endl;
cin >> rows;
cout << "Please enter seat letter: " << endl;
cin >> columns;

if(columns == 'A'){
intcolumns = 1;
}

if(columns == 'B'){
intcolumns = 2;
}

if(columns == 'C'){
intcolumns = 3;
}

if(columns == 'D'){
intcolumns= 4;
}

}

void MarkSeat(int &rows, int &intcolumns){
	rows -=1;
	seatmap[rows][intcolumns] = 'X';
}