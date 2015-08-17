#include"Rational.h"

//Constructors
Rational::Rational(){
Wholenumber = 0;
}

Rational::Rational(int a){
Wholenumber = a / 1;
}


Rational::Rational(int a, int b){
numerator = a;
denominator = b;
}

//Functions to return private numbers
void Rational::setnum(int a){
numerator = a;
}

void Rational::setdenom(int a){
denominator = a;
}

void Rational::setwhole(int a){
Wholenumber = a;
}

int Rational::getnum() const{
return numerator;
}

int Rational::getdenom() const{
return denominator;
}

int Rational::getwhole() const{
return Wholenumber;
}

//Operator Overloading with outstream and instream function
ostream& operator << (ostream& outputstream, const Rational& rationalnumbers){
	
	int numer = abs(rationalnumbers.numerator);
	int denom = abs(rationalnumbers.denominator);
	int whole = abs(rationalnumbers.Wholenumber);

	if(rationalnumbers.numerator < 0 && rationalnumbers.denominator > 0){
	outputstream << "-";
	}
	else if(rationalnumbers.numerator > 0 && rationalnumbers.denominator < 0){
	outputstream << "-";
	}
	else if (rationalnumbers.numerator < 0 && rationalnumbers.denominator < 0){
	outputstream << "";
	}

	if (rationalnumbers.denominator == 1){
	outputstream << numer;
	}
	else if(rationalnumbers.denominator == rationalnumbers.numerator){
	outputstream << 1;
	}
	else if(rationalnumbers.denominator == 0){
	cout<<"Denominator cannot be zero." << endl;
	}
	else if (rationalnumbers.numerator != 0 && rationalnumbers.denominator != 0){
	outputstream << numer << "/" << denom;
	}

	return outputstream;
}

istream& operator >> (istream& inputstream, Rational& rationalnumbers){
	
   int numer;
   int denom;
   char divide;
   cout << "Enter The Rational Number you want: " << endl;
   inputstream >> numer;
   if(numer == 0){
   rationalnumbers.setnum(0);
   }
   inputstream >> divide;
   if(divide != '/' || divide == ' '){
   rationalnumbers.setnum(numer);
   }
   inputstream >> denom;
   rationalnumbers.setnum(numer);
   rationalnumbers.setdenom(denom);
   
   return inputstream;
}


//Normalizing denominators and numerators
void Rational::normalize(){

int GCD;
int maxsize;

if(abs(numerator) > abs(denominator)){
maxsize = abs(numerator);
}
else if(abs(numerator) < abs(denominator)){
maxsize = abs(denominator);
}

for(int i=1; i<=maxsize; i++){
if(abs(numerator) % i == 0 && abs(denominator) % i == 0){
GCD = i;
}
}

numerator /=GCD;
denominator /= GCD;

}



//Numerical Operator Overloading
const Rational operator +(const Rational& rhs, const Rational& lhs){
int total_num;
int total_den;

total_num = rhs.numerator*lhs.denominator + lhs.numerator*rhs.denominator;
total_den = rhs.denominator * lhs.denominator;
return Rational(total_num, total_den);

}

const Rational operator -(const Rational& rhs, const Rational& lhs){
int total_num;
int total_den;

total_num = rhs.numerator*lhs.denominator - lhs.numerator*rhs.denominator;
total_den = rhs.denominator * lhs.denominator;
return Rational(total_num, total_den);

}

const Rational operator *(const Rational& rhs, const Rational& lhs){
int total_num;
int total_den;

total_num = rhs.numerator * lhs.numerator;
total_den = rhs.denominator * lhs.denominator;
return Rational(total_num, total_den);

}

const Rational operator /(const Rational& rhs, const Rational& lhs){
int total_num;
int total_den;

total_num = rhs.numerator*lhs.denominator;
total_den = rhs.denominator * lhs.numerator;
return Rational(total_num, total_den);

}

bool operator ==(const Rational& rhs, const Rational& lhs){
return ((rhs.getnum() * lhs.getdenom()) == (lhs.getnum() * rhs.getdenom()));
}

bool operator >(const Rational& rhs, const Rational& lhs){
return (rhs.getnum() * lhs.getdenom() > lhs.getnum() * rhs.getdenom());
}

bool operator <(const Rational& rhs, const Rational& lhs){
return (rhs.getnum() * lhs.getdenom() < lhs.getnum() * rhs.getdenom());
}

bool operator <=(const Rational& rhs, const Rational& lhs){
return (rhs.getnum() * lhs.getdenom() <= lhs.getnum() * rhs.getdenom());
}

bool operator >=(const Rational& rhs, const Rational& lhs){
return (rhs.getnum() * lhs.getdenom() >= lhs.getnum() * rhs.getdenom());
}

int main(){

	Rational R_input, R1(2,3), R2;
	cin >> R_input;
	
	if(R_input.getdenom()==0){
	cout<<"The denominator is zero.."<<endl;
	exit(0);
	}
	
	R2 = R_input + R1;
	R2.normalize();
	cout << "The Result of Input Rational Number + Default Rational Number is: " << endl;
	cout << R2 << endl;
	R2 = R_input - R1;
	R2.normalize();
	cout << "The Result of Input Rational Number - Default Rational Number is: " << endl;
	cout << R2 << endl;
	R2 = R_input * R1;
	R2.normalize();
	cout << "The Result of Input Rational Number * Default Rational Number is: " << endl;
	cout << R2 << endl;
	R2 = R_input / R1;
	R2.normalize();
	cout << "The Result of Input Rational Number / Default Rational Number is: " << endl;
	cout << R2 << endl;
	
	if(R_input == R1)
	{cout<<"The entered values are the same!"<<endl;}
	else if(R_input > R1)
	{cout<<"The entered values is greater than fixed!"<<endl;}
	else if(R_input < R1)
	{cout<<"The entered values is less than fixed!"<<endl;}
	else if(R_input >= R1)
	{cout<<"The entered values is greater and equal to fixed!"<<endl;}
	else if(R_input <= R1)
	{cout<<"The entered values is less than and equal fixed!"<<endl;}

	return 0;
}