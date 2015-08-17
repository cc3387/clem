#include <iostream>
#include <vector>
using namespace std;

//Improved method using class to do the multiplication
class Matrix{

private:

	int row;
	int column;
	int **Mat;	   

public:

	//Default Constructor
	Matrix() : row(0), column(0), Mat(0){}

	//Parameterized Constructor
	Matrix(int the_row, int the_column) : row(the_row), column(the_column){
	cout<<"Initializaing Constructor ... " <<endl;
	Mat = new int*[row];
	for(int i=0; i<column; i++){
	Mat[i] = new int[column];
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
		Mat[i][j] = 0;
	    }
	}

	}

	//Parameterized Constructor with Matrix passing by
	Matrix(int **the_Mat, int the_row, int the_column) : row(the_row), column(the_column){
	Mat = new int*[row];
	for(int i=0; i<column; i++){
	Mat[i] = new int[column];
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
		Mat[i][j] = 0;
		Mat[i][j] = the_Mat[i][j];
	    }
	}

	}

	//Destructor
	~Matrix(){
	cout << "Initializing Destructor ... " << endl;	
	delete[] Mat;
	};

	//Assignment operator
	Matrix &operator=(const Matrix &Mt){
	delete[] Mat;

	Mat = new int*[row];
	for(int i=0; i<column; i++){
	Mat[i] = new int[column];
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
		Mat[i][j] = 0;
		Mat[i][j] = Mt.getMat(i,j);
		}
	}

	}

//Setters Getters and Operator

int getMat(int row, int column)const{
return Mat[row][column];
}

//Overloading * to multiply the vectors together (combining all the functions)
friend Matrix operator *(const vector<vector<int> > &the_A, const vector<vector<int> > &the_B){

	 if(the_A[1].size() == the_B.size()){
	 
	 int **M; //Define the new matrix
	 
	 M = new int*[the_A.size()];

	 for(int i=0; i<the_A.size(); i++){
	 M[i] = new int[the_B[1].size()];
	 }


	 for(int i=0; i<the_A.size(); i++){
		 for(int j=0;j<the_B[1].size(); j++){
		 M[i][j] = 0;
		 }
	 }
		  
	 for(int i=0; i<the_A.size(); i++){
		for(int j=0; j < the_B[1].size(); j++){
		    int C_mult = 0;
			for(int k = 0; k < the_A[1].size(); k++){
			C_mult += the_A[i][k] * the_B[k][j];
			}	
		    M[i][j] = C_mult;
		}
	 }

	 return Matrix(M,the_A.size(), the_B[1].size());
	 
	 }
	 else{
	 cout << "The dimension is not compatible ... " << endl;
	 exit(1);
	 }
}
};

//Building functions without using the class
bool Check_Dimensions(vector<vector<int> > the_A, vector<vector<int> > the_B){
	 
	 if(the_A[1].size() == the_B.size()){
	 return true;
	 }
	 else{
	 cout << "The dimension is not compatible ... " << endl;
	 return false;
	 }
}

int Multiply(vector<vector<int> > the_A, vector<vector<int> > the_B, int A_row, int B_col, int A_col_B_row){

	int C = 0;

    for(int j = 0; j < A_col_B_row; j++){
	   C += the_A[A_row][j] * the_B[j][B_col];
	}
	return C;
}

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
		A[i][j] = i + 1;
		}
	}

	//Initializing B
	for(int i=0; i<column; i++){
		for(int j=0; j <row; j++){	
		B[i][j] = 0;
		B[i][j] = j + 1;
		}
	}

	int k = Check_Dimensions(A,B);


	if(k == 1){
	//Initializing C
	for(int i=0; i<row; i++){
		for(int j=0; j <row; j++){
		C[i][j] = 0;
		C[i][j] = Multiply(A,B,i,j,column);
		}
	}
	
	cout<<" " << endl;
	cout<<"Matrix A: " << endl;
		
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

	cout<<" " <<endl;
	cout<<"Matrix C: " << endl;

	for(int i=0; i<row; i++){
		for(int j=0; j<row; j++){
		if(j != row-1)
			cout << C[i][j] << " ";
		else
			cout << C[i][j] << endl;
		}
	}
	}
	else{
	//If not compatible, then exit program.
	exit(1);
	}
	cout<<" " <<endl;


	/******************************** Improved Method with operator * overloaded **********************/
	//Improved method using classes and operator overloading
	Matrix CMat(row,row);
	CMat = A * B;
	

	cout<<" " <<endl;
	cout<<"Matrix C using assignment operator (A*B): " << endl;
	for(int i=0; i<row; i++){
		for(int j=0; j<row; j++){
		if(j != row-1)
			cout << CMat.getMat(i,j) << " ";
		else
			cout << CMat.getMat(i,j)  << endl;
		}
	}
	
	Matrix CMat1(column,column);
	CMat1 = B * A;
	cout<<" " <<endl;
	cout<<"Matrix C using assignment operator (B*A): " << endl;
	for(int i=0; i<column; i++){
		for(int j=0; j<column; j++){
		if(j != column-1)
			cout << CMat1.getMat(i,j) << " ";
		else
			cout << CMat1.getMat(i,j)  << endl;
		}
	}
	
	cout<<" " <<endl;
	cout<<"Matrix D with incompatible size: " << endl;
	//Testing a non working example
	Matrix DMat(row,row);
	DMat = A * A;


	return 0;

}