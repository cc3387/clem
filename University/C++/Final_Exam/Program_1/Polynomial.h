#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Poly{

private:

    int order; //order of the polynomial
    int *coeff;
    
public:

    Poly();
    Poly(int); //Create Nth order poly and initiates all coefficients
    Poly(int,int*);
    ~Poly(); //Destructor
    Poly(const Poly &p); //Copy Constructor


    //mutators and accessors
    void set();
    void set(int[],int);
    int getOrder() const;
    int *get();
    int get(int) const;

    //Operators Overloading
    Poly operator+(const Poly &rhs);
    Poly operator-(const Poly &rhs);
    Poly operator*(const int scale);
    Poly operator*(const Poly &rhs);
    friend const Poly operator*(const int scale, const Poly &P);
    friend const Poly operator*(const Poly &P, const int scale);
    bool operator==(const Poly &rhs);
    const int &operator[](int) const;
    int &operator[](int);
    int operator()(int);
    
    Poly &operator=(const Poly& rhs);
    friend ostream &operator << (ostream &Out, const Poly &rhs);

};