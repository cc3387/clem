#include "Dot_Products.h"


Vector2D::Vector2D(){
dot_product = 0;
max_size = 0;
}

Vector2D::Vector2D(int a, int b){
dot_product = (a + b);
}

void Vector2D::init_vector(int a){
max_size = a;
int max_col = 2;

xycoord = new int*[max_size];

for(int i = 0; i < max_size; i++){
xycoord[i] = new int[max_col];
}
}

void Vector2D::set_x(){
for(int i = 0; i < max_size; i++){
xycoord[i][1] = i;
cout<<xycoord[i][1]<<endl;
}
}

void Vector2D::set_y(){
for(int i = 0; i < max_size; i++){
xycoord[i][2] = i+1;
cout<<xycoord[i][2]<<endl;
}
}

int Vector2D::get_x(int a)const{
return xycoord[a][1];
}

int Vector2D::get_y(int a)const{
return xycoord[a][2];
}

int Vector2D::get_maxsize()const{
return max_size;
}

int Vector2D::get_dot_product()const{
return dot_product;
}

const Vector2D operator *(const Vector2D &rhs, const Vector2D &lhs){

	int sum_x = 0;
	int sum_temp_x = 0;
	int sum_y = 0;
	int sum_temp_y = 0;


	for(int i=0; i < rhs.get_maxsize(); i++){
    sum_temp_x = rhs.get_x(i) * lhs.get_x(i);
	sum_temp_y = rhs.get_y(i) * lhs.get_y(i);
	sum_x += sum_temp_x;
	sum_y += sum_temp_y;
	}

	return Vector2D(sum_x, sum_y);
}

bool operator ==(const Vector2D &rhs, const Vector2D &lhs){
return (rhs.get_maxsize() == lhs.get_maxsize());
}

Vector2D::~Vector2D(){
cout<<"Calling Destructor..."<<endl;
delete[] xycoord;
}


//Main section to test the program

int main(){

	int Dot_Product;
	Vector2D V2D_1, V2D_2, V2D_3;
	V2D_1.init_vector(5);
	V2D_2.init_vector(5);
	
	if(V2D_1 == V2D_2){
	cout<<"X coordinates of first set is: "<<endl;
	V2D_1.set_x();
	cout<<"Y coordinates of first set is: "<<endl;
	V2D_1.set_y();
	cout<<"X coordinates of second set is: "<<endl;
	V2D_2.set_x();
	cout<<"Y coordinates of second set is: "<<endl;
	V2D_2.set_y();

	V2D_3 = V2D_1 * V2D_2;
	
	cout<<"The dot product of the two sets is: " << V2D_3.get_dot_product()<<endl;
	}
	else{
	cout<<"Dimension mismatch..." <<endl;
	}

	return 0;
}