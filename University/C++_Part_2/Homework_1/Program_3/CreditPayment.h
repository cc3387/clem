#ifndef CREDITPAYMENT_H
#define CREDITPAYMENT_H

#include <string>
#include <iostream>
#include <cstdlib>
#include "Payment.h"


class CreditPayment : public Payment {

public:
	//Constructors
	CreditPayment(); // Default Constructor
	CreditPayment(float payamount);
	
	//Output payment details
	void paymentDetails();
};

#endif

