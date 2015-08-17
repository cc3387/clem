#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

	int N = 20;
	int M = 10;

	int A[N][M];
	int B[M][N];

	//Filling in A Values

	for (int i = 0; i < N; i ++){
	   	for (int j = 0; j < M; j++){

		A[i][j] = i+j;
		
		printf("A[%d][%d] is: %d\n", i, j, A[i][j]);
		}
	};


	//Define the i as zero in initial section
	int i = 0;

	for (int k = 0 ; k < N * M ; k++){
	    
		//Decide on the mod, if mod of M is zero, then we switch row
		if( (k % M) == 0 && (k != 0)){
		i++; 
		}
		
		int temp[M];
		int tempcount = k % M;
		temp[tempcount] = A[i][tempcount];
		B[tempcount][i] = temp[tempcount];
		printf("B[%d][%d] is: %d\n",tempcount, i, B[tempcount][i]);

	};
	
	return 0; 
}
