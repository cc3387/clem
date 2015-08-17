#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


class HanoiPost{

public:
    static string hanoi(int, int, int);
};


string HanoiPost::hanoi(int nDisks, int from, int to){

	   int help;

	   string Move_Nmin1_1_2, Move_Nmin1_2_3 , Move_N, mySol;
	   
	   if(nDisks == 1){
	   
	   cout<<from << " -> " << to << endl;
	   
	   return from + " -> " + to + '\n';  
	   }
	   
	   else{
	   
	   help = 6 - from - to;

	   Move_Nmin1_1_2 = hanoi(nDisks-1, from, help); 

	   Move_N = from + "->" + to + '\n';
	   
	   cout<< from << " -> " << to << endl; 

	   Move_Nmin1_2_3 = hanoi(nDisks-1, help, to); 

	   mySol = Move_Nmin1_1_2 + Move_Nmin1_2_3 + Move_N;

	   return mySol;
	   }
}

int main(){

	int n = 3;
	int n1 = 4;
	int n2 = 5;
	
	HanoiPost HP;
	
	string StepstoSol;

	cout<<"The scenario with "<< n << " bricks is with the following moves: " << endl;
	StepstoSol = HP.hanoi(n,1,3);
	cout<<" " << endl;
	
	cout<<"The scenario with " << n1 << " bricks is with the following moves: " << endl;
	StepstoSol = HP.hanoi(n1,1,3);
	cout<<" " << endl;

	cout<<"The scenario with " << n2 << " bricks is with the following moves: " << endl;
	StepstoSol = HP.hanoi(n2,1,3);
	cout<<" " << endl;
	
	return 0;
}