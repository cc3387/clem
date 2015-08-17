#include <iostream>
#include <vector>
using namespace std;

class Matrix{

private:
	int row;
	int column;
	vector<vector<int> > Mat;

public:
	
	//Default constructor
	Matrix() : row(0), column(0){};
	
	//Parameterized Constructor
	Matrix(int the_row, int the_col) : row(the_row), column(the_col){
	vector<vector<int> > Mat(row,vector<int>(column,0));
	for(int i=0; i<row; i++){
		for(int j=0; j <column; j++){	
		Mat[i][j] = 0;
		}
	}
	};
	
	Matrix &operator=(const Matrix &Mt){
	for(int i = 0; i < row; i++){
		for(int j=0; j< column; j++){
		Mat[i][j] = Mt.getMat(i,j);
		}
	}
	return *this;
	};

	//Setters and Getters
	int getMat(int i, int j) const{
	return Mat[i][j];
	}

	int printMat() const{
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
		if(j != column-1)
			cout << Mat[i][j];
		else
			cout << Mat[i][j] << endl;
		}
	}
	
	}
};


int main(){

	//Define the dimension of rows and columns
	int row = 5;
	int column = 4;

	vector<vector<int> > A(row, vector<int>(column,0)); // 5-by-4 matrix
	vector<vector<int> > B(column, vector<int>(row,0)); // 4-by-5 matrix
	vector<vector<int> > C(row, vector<int>(row,0));   // 5-by-5 matrix

	//Initializing A
	for(int i=0; i<row; i++){
		for(int j=0; j <column; j++){	
		A[i][j] = 0;
		A[i][j] = i*j;
		}
	}

	//Initializing B
	for(int i=0; i<column; i++){
		for(int j=0; j <row; j++){	
		B[i][j] = 0;
		B[i][j] = i+j;
		}
	}

	//Initializing C
	for(int i=0; i<row; i++){
		for(int j=0; j <row; j++){	
		C[i][j] = 0;
		}
	}



	cout<<"Matrix A: " << endl;
	cout<<" " << endl;
	//Printing out A Matrix
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
		if(j != column-1)
			cout << A[i][j] << " ";
		else
			cout << A[i][j] << endl;
		}
	}

	cout<<" " <<endl;
	cout<<"Matrix B: " << endl;

	for(int i=0; i<column; i++){
		for(int j=0; j<row; j++){
		if(j != row-1)
			cout << B[i][j] << " ";
		else
			cout << B[i][j] << endl;
		}
	}


	return 0;

}