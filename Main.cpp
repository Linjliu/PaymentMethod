#include <iostream>
#include "PaymentMethod.h"

int main()
{
    // Create a credit card object on the stack
    CreditCard myCard("Luke Blow", "4179864676436971", "12/28");

    // array of base class pointers, size 2
    PaymentMethod* payList[2];

    // The first element: stack object address &
    payList[0] = &myCard;

    // The second element: new creates a PayPal object on the heap
    payList[1] = new PayPal("Luke@example.com", 250.0);

    std::cout << "===== Start Checkout Process =====" << std::endl;
    double transactionAmount = 100.0;

    // Call the batch payment function
    processAllPayments(payList, 2, transactionAmount);

    // Objects created with new must be manually deleted to prevent memory leaks.
    delete payList[1];

    payList[1] = nullptr;

    return 0;
}