#include<iostream>
using namespace std;


class X {

public:

	//function overloading within class X
	void foo(int);
	void foo(int,int);
	void foo(int,int,int);
	void foo(int,int,int,int);

};

void X::foo(int X1){
cout << X1 << endl;
}

void X::foo(int X1, int X2){
cout << X1 << " "<< X2 << endl;
}

void X::foo(int X1, int X2, int X3){
cout << X1 << " " << X2 << " " << X3 << endl;
}

void X::foo(int X1, int X2, int X3, int X4){
cout << X1 << " " << X2 <<" " << X3 << " " <<X4 << endl;
}

int main(){

	X x_class;

	x_class.foo(4);
	x_class.foo(4,6);
	x_class.foo(4,6,9);
	x_class.foo(4,6,10,11);

	return 0;
}