#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printmat(vector<vector<double> > &vec, int the_row, int the_column){
	
	for(int i=0; i<the_row; i++){
		for(int j=0; j<the_column; j++){
		if(j != the_column-1)
			cout << vec[i][j] << " ";
		else
			cout << vec[i][j]  << endl;
		}
	}

}

void printvec(vector<double> &vec, int the_row){
	
	for(int i=0; i<the_row; i++){
			cout << vec[i] << endl;
	}
}

vector<vector<double> > get_D_U_L(vector<vector<double> > &vec, int the_row, int the_column, char type){
	if(type == 'D'){
	  for(int i=0; i < the_row; i++){
		 for(int j=0; j < the_column; j++){
		 if(i!=j){
		 vec[i][j] = 0;
		 }
		 else if(i==j){
		 double temp = 1/vec[i][j];
		 vec[i][j] = temp;
		 }
		 }
	  }
	}
	else if(type == 'L'){
	  for(int i=0; i < the_row; i++){
		 for(int j=0; j < the_column; j++){
		 if(i < j || i == j){
		 vec[i][j] = 0;
		 }
		 }
	  }
	}
	else if(type == 'U'){
	  for(int i=0; i < the_row; i++){
		 for(int j=0; j < the_column; j++){
		 if(i > j || i == j){
		 vec[i][j] = 0;
		 }
		 }
	  }
	}
	return vec;
}

vector<vector<double> > get_T(vector<vector<double> > the_D_inv, vector<vector<double> > the_L, vector<vector<double> > the_U, int the_row, int the_col){
	   
	   vector<vector<double> > T(the_row, vector<double>(the_col,0));

	   for(int i=0; i < the_row; i++){
		   for(int j=0; j < the_col; j++){
		   T[i][j] = (-1)*(the_L[i][j] + the_U[i][j]);
		   }
	   }

	   for(int i=0; i<the_D_inv.size(); i++){
		  for(int j=0; j < T[1].size(); j++){
		    double C_mult = 0;
			for(int k = 0; k < the_D_inv[1].size(); k++){
			C_mult += the_D_inv[i][k] * T[k][j];
			}	
		    T[i][j] = C_mult;
		  }
	   }

	   return T;
}

vector<double> get_C(vector<vector<double> > the_D_inv, vector<double> the_b){
	   
	   vector<double> C;

	   for(int i=0; i < the_b.size(); i++){
	   C.push_back(0);
	   }

	   for(int i=0; i<the_D_inv.size(); i++){
		  double C_mult = 0;
		  for(int j=0; j < the_b.size(); j++){
			C_mult += the_D_inv[i][j] * the_b[j];
		  }
		  C[i] = C_mult;
	   }

	   return C;
}

vector<double> find_solution(vector<vector<double> > the_A, vector<vector<double> > the_T, vector<double> the_C, vector<double> the_b){

	 vector<double> x;
	 vector<double> x_final;
	 vector<double> check_b;
	 vector<int> check;
	 vector<double> diff;
	 int check_sum;
	 char ans;
	 double C_mult;

	 for(int i=0; i < the_C.size(); i++){
	 x.push_back(1);
	 x_final.push_back(0);
	 check_b.push_back(0);
	 diff.push_back(0);
	 check.push_back(0);
	 }

	do{

	for(int i=0; i < the_C.size(); i++){
	 	C_mult = 0;
		for(int j=0; j < the_C.size(); j++){
		C_mult += the_T[i][j] * x[j];
		}
	 x_final[i] = C_mult;
	}

   	for(int i=0; i< the_C.size();i++){
	x_final[i] += the_C[i];
	}
	
	for(int i=0; i < the_C.size(); i++){
	 	C_mult = 0;
		for(int j=0; j < the_C.size(); j++){
		C_mult += the_A[i][j] * x_final[j];
		}
	check_b[i] = C_mult;

	}

	for(int i=0; i<the_b.size(); i++){
	diff[i] = check_b[i] - the_b[i];
	}

	for(int i=0; i<the_b.size(); i++){
	if(abs(diff[i]) < 0.0000000001){
	check[i] = 1;
	}
	else{
	check[i] = 0;
	}
	}

	check_sum = 0;
	for(int i=0; i<the_b.size(); i++){
	check_sum += check[i];
	}

	//cout<<"Continue?" <<endl;
	//cin >>ans;

	for(int i=0; i<the_b.size(); i++){
	x[i] = x_final[i];
	}

	}while(check_sum != the_b.size());

	return x_final;
}



int main(){

	int row = 4;
	int column = 4;

	vector<vector<double> > A(row, vector<double>(column,0));
	vector<vector<double> > D_inv(row, vector<double>(column,0));
	vector<vector<double> > L(row, vector<double>(column,0));
	vector<vector<double> > U(row, vector<double>(column,0));
	vector<vector<double> > T(row, vector<double>(column,0));
	vector<double> x;
	vector<double> b;
	vector<double> C;

	//Inputting values into A
	//for(int i=0; i < row; i++){
	//   for(int j=0; j < column; j++){
	//   A[i][j] = (i+1) * (j+1);
	//   }
	//}

	A[0][0] = 10;
	A[0][1] = -1;
	A[0][2] = 2;
	A[0][3] = 0;
	A[1][0] = -1;
	A[1][1] = 11;
	A[1][2] = -1;
	A[1][3] = 3;
	A[2][0] = 2;
	A[2][1] = -1;
	A[2][2] = 10;
	A[2][3] = -1;
	A[3][0] = 0;
	A[3][1] = 3;
	A[3][2] = -1;
	A[3][3] = 8;


	cout << "Matrix A : " << endl;
	printmat(A, row, column);
	cout << " " << endl;

	//Inputting values into b
	cout << "Vector b : " << endl;
	//for(int i=0; i < row; i++){
	//b.push_back(i+1);
	//}

	b.push_back(6);
	b.push_back(25);
	b.push_back(-11);
	b.push_back(15);

	printvec(b,row);
	cout << " " << endl;

	//Get the diagonal matrix
	cout<<"D inverse is: " << endl;
	D_inv = A;
	D_inv = get_D_U_L(D_inv,row,column,'D');
	printmat(D_inv, row, column);
	cout << " " << endl;
	L = A;
	L = get_D_U_L(L,row,column,'L');
	cout<<"L is: " << endl;
	printmat(L, row, column);
	cout << " " << endl;
	U = A;
	U = get_D_U_L(U,row,column,'U');
	cout<<"U is: " << endl;
	printmat(U, row, column);
	cout << " " << endl;
	
	T = get_T(D_inv, L, U, row, column);
	cout<<"T is: " << endl;
	printmat(T, row, column);
	cout << " " << endl;

	C = get_C(D_inv, b);
	cout<<"C is: " << endl;
	printvec(C, row);
	cout << " " << endl;

	cout<<"The solved Ax = b with the given matrices is: " << endl;
	x = find_solution(A, T, C, b);
	printvec(x, row);
	cout << " " << endl;


	return 0;
}