#include "CreditPayment.h"

CreditPayment :: CreditPayment() : Payment(){
//default constructor
}

CreditPayment :: CreditPayment(float payamount) : Payment(payamount) {
//parameterized constructor
}

//Payment Details Function
void CreditPayment :: paymentDetails(){
std::cout << "The amount paid in credit is: " << getpayment() << std::endl;
}