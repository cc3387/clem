#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>
#include <cstdlib>

class Payment{

protected:
	float payment_amount;

public:
	//Constructors
	Payment(); // Default Constructor
	Payment(float payamount);
	
	//Setter and Getter function
	void setpayment(float payment);
	float getpayment();
	
	//Output payment details
	void paymentDetails();
};

#endif

