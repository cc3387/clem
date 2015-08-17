#include<iostream>
#include<cstdio>
using namespace std;

class Point{

private: 
	
	double x_coordinates;
	double y_coordinates;

public:

	void set(double, double);
	void move(double, double);
	void rotate90clockwise();
	const double retrieve_x(){return x_coordinates;};
	const double retrieve_y(){return y_coordinates;};

};


void Point::set(double a, double b){
   
   x_coordinates = a;
   y_coordinates = b;
      
}

void Point::move(double a, double b){
  
  x_coordinates += a;
  y_coordinates += b;
}

void Point::rotate90clockwise(){
	 
	 int i = 0; //This is the integer to make sure that each time rotate90clockwise called only ran 1 condition, so that the if conditions will not be repeated in 1 call.

	 if (x_coordinates >= 0 && y_coordinates >= 0 && i == 0){
		 y_coordinates *= -1;
		 i++;
	 }
	 
	 if (x_coordinates >= 0 && y_coordinates <= 0 && i == 0){
	     x_coordinates *= -1;
	     i++;
	 }

	 if (x_coordinates <= 0 && y_coordinates <= 0 && i == 0){
	     y_coordinates *= -1;
	     i++;
	 }

	 if (x_coordinates <= 0 && y_coordinates >= 0 && i == 0){
	     x_coordinates *= -1;
	     i++;
	 }

}


int main(){
    
	Point P;
	
	P.set(0,4);
	P.move(5,4);
	P.rotate90clockwise();
	P.rotate90clockwise();
	P.move(1,1);
	cout<<"X's coordinates is: " << P.retrieve_x()<<endl;
	cout<<"Y's coordinates is: " << P.retrieve_y()<<endl;
}



