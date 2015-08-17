#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include <string>
#include <iostream>
#include <cstdlib>
#include "Payment.h"


class CashPayment : public Payment {

public:
	//Constructors
	CashPayment(); // Default Constructor
	CashPayment(float payamount);
	
	//Output payment details
	void paymentDetails();
};

#endif

