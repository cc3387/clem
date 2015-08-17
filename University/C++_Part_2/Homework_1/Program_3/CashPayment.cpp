#include "CashPayment.h"

CashPayment :: CashPayment() : Payment(){
//default constructor
}

CashPayment :: CashPayment(float payamount) : Payment(payamount) {
//parameterized constructor
}

//Payment Details Function
void CashPayment :: paymentDetails(){
std::cout << "The amount paid in cash is: " << getpayment() << std::endl;
}