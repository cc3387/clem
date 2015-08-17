#include "Payment.h"

Payment :: Payment() : payment_amount(0){
//default constructor
}

Payment :: Payment(float payamount) : payment_amount(payamount){
//parameterized constructor
}

//Setter Function
void Payment :: setpayment(float payment){
payment_amount = payment;
}

//Getter Function
float Payment :: getpayment(){
return payment_amount;
}

//Payment Details Function
void Payment :: paymentDetails(){
std::cout << "The amount paid is: " << getpayment() << std::endl;
}