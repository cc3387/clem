#include "Polynomial.h"


//Default Constructor
Poly::Poly(){
order = 0;
coeff = new int[order];
coeff[0] = 1;
}

//Constructors with initiated values
Poly::Poly(int Order){
order = (Order+1);
coeff = new int[order];

//Define all the coefficients with 1
for(int i=0; i < order; i++){
coeff[i] = 1;
}
}

//Constructors with coeff included
Poly::Poly(int Order, int *Coeff){
order = (Order+1);
coeff = new int[order];
for(int i=0; i < order; i++){
coeff[i] = Coeff[i];
}
}

//Copy Constructors 
Poly::Poly(const Poly &p){
cout<<"This is Copy Constructor..."<<endl;
order = p.order;
coeff = p.coeff;
}

//Destructor
Poly::~Poly(){
cout<<"This is Destructor..."<<endl;
delete[] coeff;
}

/************************ Mutators and Accessors *****************************/
void Poly::set(){

int Order;
int Coeff_int;

cout << "Please Enter The Order Of The Polynomial. " << endl;
cin >> Order;
order = (Order+1);

coeff = new int[order];

cout<<"Please enter the coefficient starting from X^0, enter 0 if power does not exist." <<endl;

for(int i=0; i<order; i++){
cin >> Coeff_int;
coeff[i] = Coeff_int;
}
}

//void set coefficients
void Poly::set(int Coeff[], int size){

order = (size+1);
coeff = new int[order];

for(int i=0; i<order; i++){
coeff[i] = Coeff[i];
}
};

//Get coefficient value
int Poly::get(int a) const{
return coeff[a];
}

//Getting order
int Poly::getOrder() const{
return order;
}

//Getting the whole coeff
int* Poly::get(){
return coeff;
}

/********************************Operator Overloading Methods ************************************/

//Operator + Overloading
Poly Poly::operator+(const Poly &rhs){

Poly P = *this;

if(P.getOrder() > rhs.getOrder())
{
 int *coeff_temp = new int [P.getOrder()];
 
 for(int i=0; i < P.getOrder(); i++){
 coeff_temp[i] = 0;
 }

 for(int i=0; i < rhs.getOrder(); i++){
 coeff_temp[i] = rhs.coeff[i];
 }

 for(int i=0; i < P.getOrder(); i++){
 P.coeff[i] = coeff[i] + coeff_temp[i];
 }
 P.set(P.coeff, P.getOrder()-1);
 return P;
}
else
{
 int *coeff_temp = new int [rhs.getOrder()];
 for(int i=0; i < P.getOrder(); i++){
 coeff_temp[i] = P.coeff[i];
 }

 P.coeff = coeff_temp;
 
 for(int i=0; i<rhs.getOrder(); i++){
 rhs.coeff[i] = rhs.coeff[i] + P.coeff[i];
 }
 P.set(rhs.coeff, rhs.getOrder()-1);
 return P;
};
};



//Operator - Overloading
Poly Poly::operator-(const Poly &rhs){

Poly P = *this;

if(P.getOrder() > rhs.getOrder())
{
 int *coeff_temp = new int [P.getOrder()];
 
 for(int i=0; i < P.getOrder(); i++){
 coeff_temp[i] = 0;
 }

 for(int i=0; i < rhs.getOrder(); i++){
 coeff_temp[i] = rhs.coeff[i];
 }

 for(int i=0; i < P.getOrder(); i++){
 P.coeff[i] = coeff[i] - coeff_temp[i];
 }
 P.set(P.coeff, P.getOrder()-1);
 return P;
}
else
{
 int *coeff_temp = new int [rhs.getOrder()];
 for(int i=0; i < P.getOrder(); i++){
 coeff_temp[i] = P.coeff[i];
 }

 P.coeff = coeff_temp;
 
 for(int i=0; i<rhs.getOrder(); i++){
 rhs.coeff[i] =  P.coeff[i] - rhs.coeff[i];
 }
 P.set(rhs.coeff, rhs.getOrder()-1);
 return P;
};
};


//Operator * Scaler Overloading
Poly Poly::operator*(const int scale){
Poly P = *this;
for(int i=0; i < P.getOrder(); i++){
P.coeff[i] *= scale;
}
P.set(P.coeff, P.getOrder()-1);
return P;
}

//For backward directions that take 2 arguments
const Poly operator*(int scale, const Poly &P){
Poly P1 = P;
for(int i=0; i < P.getOrder(); i++){
P.coeff[i] *= scale;
}
P1.set(P.coeff, P.getOrder()-1);
return P1;
}

const Poly operator *(const Poly &P, int scale){
return scale * P;
}



//Operator * another polynomial
Poly Poly::operator*(const Poly &rhs){
Poly P = *this;

//Initializing the maximum order
int max_order = (P.getOrder() + rhs.getOrder())-1;

//Initializing the new set for summation
int *coeff_final = new int[max_order];
int *coeff_temp = new int[max_order];

for(int i=0; i < max_order; i++){
coeff_final[i] = 0;
coeff_temp[i] = 0;
}

for(int i=0; i < P.getOrder(); i++){
coeff_final[i] = P.coeff[i];
}

for(int i=0; i<rhs.getOrder(); i++){
  
  //Create a new summation array
  if(i > 0){
  delete[] coeff_temp;
  int *coeff_temp = new int[max_order];  
  for(int i=0; i < max_order; i++){
  coeff_temp[i] = 0;
  }
  }

  for(int j=0; j<P.getOrder(); j++){
  
  int total_order = i + j;
  
  if(i == 0){
  coeff_final[total_order] = P.coeff[j]*rhs.coeff[i];
  }
  else{
  coeff_temp[total_order] = P.coeff[j]*rhs.coeff[i];
  coeff_final[total_order] += coeff_temp[total_order];
  }

  }
}

//Setting the coefficients are order into the class
P.set(coeff_final, max_order-1);
delete[]coeff_final;
delete[]coeff_temp;
return P;
};

//Operator boolean == for Poly Class
bool Poly::operator==(const Poly &rhs){
return true;
}

//const operator[]
int &Poly::operator[](int I){
     if(I > order){
     return coeff[I];
     }
     else{
     return coeff[I];
  }
}

const int &Poly::operator[](int I) const{
     if(I > order){
     return coeff[I];
     }
     else{
     return coeff[I];
  }
}

//Operator Honer's method()
int Poly::operator()(int a){
Poly P;
int max = order-1;
int init = coeff[max];

while(max > 0){
init = coeff[max-1] + a*init;
max--;
}
return init;
}


//Operator overloading "="
Poly &Poly::operator=(const Poly &rhs){
if(this != &rhs){
delete[] coeff;
set(rhs.coeff,rhs.getOrder()-1);
}
return *this;
}

//Outstream overloading
ostream& operator << (ostream &Out, const Poly &rhs){

int i = rhs.getOrder()-1;
int max;

//Search for the maximum polynomial output
for(int j=0; j<=i; j++){
int test = rhs.get(j);
if(abs(test)>0){
max = j;
}
}

while (i >= 0){
if(rhs.get(i)!=0){
if(rhs.get(i) >= 1){
if(i == max){
Out << "";
}else{
Out << "+";}
};
if(i > 1){
if(abs(rhs.get(i))==1 && rhs.get(i) < 0){
Out << "-";
Out << "X^";
Out << i; 
}else if (abs(rhs.get(i))==1 && rhs.get(i) > 0) {
Out << "X^";
Out << i;
}else{
Out << rhs.get(i);
Out << "X^";
Out << i;
}
}else if (i == 1){
if(abs(rhs.get(i))==1 && rhs.get(i) < 0){
Out << "-";
Out << "X";
}else if(abs(rhs.get(i))==1 && rhs.get(i) > 0){
Out << "X";
}else{
Out << rhs.get(i);
Out << "X";}
}else if (i == 0)
{Out << rhs.get(i);}
}
i--;
}
return Out;
}
