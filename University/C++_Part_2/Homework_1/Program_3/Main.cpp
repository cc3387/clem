#include "Payment.h"
#include "CashPayment.h"
#include "CreditPayment.h"
#include <iostream>

int main(){
	//Testing Base Class -- Payment
	Payment P(20.5);
	P.paymentDetails();

	//Testing Derived Class -- CashPayment
	CashPayment CP(30.5), CP1(4000.35);
	CP.paymentDetails();
	CP1.paymentDetails();

	//Testing Derived Class -- CreditPayment
	CreditPayment CrP(500.125), CrP1(3000.5);
	CrP.paymentDetails();
	CrP1.paymentDetails();

	return 0;
}