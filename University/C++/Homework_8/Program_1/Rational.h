#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Rational{

private:
	int numerator;
	int denominator;
	int Wholenumber;

public:
	Rational();
	Rational(int);
	Rational(int,int);
	
	void setnum(int);
	void setdenom(int);
	void setwhole(int);

	int getnum() const;
	int getdenom() const;
	int getwhole() const;

	void normalize();

	//Operator Overloading
	friend ostream& operator<<(ostream& outputstream, const Rational& rationalnumbers);
	friend istream& operator>>(istream& inputstream, const Rational& rationalnumbers);

	//Numerical Operator Overloading
	friend const Rational operator +(const Rational& rhs, const Rational& lhs);
	friend const Rational operator -(const Rational& rhs, const Rational& lhs);
	friend const Rational operator *(const Rational& rhs, const Rational& lhs);
	friend const Rational operator /(const Rational& rhs, const Rational& lhs);
};

	bool operator ==(const Rational& rhs, const Rational& lhs);
	bool operator >(const Rational& rhs, const Rational& lhs);
	bool operator <(const Rational& rhs, const Rational& lhs);
	bool operator >=(const Rational& rhs, const Rational& lhs);
	bool operator <=(const Rational& rhs, const Rational& lhs);