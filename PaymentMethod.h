#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include <string>

// Abstract Payment Method Superclass
class PaymentMethod
{
public:
    // Pure virtual function: process payment, to be implemented by subclasses
    virtual bool processPayment(double amount) = 0;

    // 虚析构函数 default
    virtual ~PaymentMethod() = default;
};

// Credit Card Subcategory
class CreditCard : public PaymentMethod
{
private:
    std::string ownerName;    //Cardholder Name
    std::string cardNumber;   //Card number
    std::string expireDate;   //Validity Period MM/YY
public:
    CreditCard(std::string name, std::string ccn, std::string exp);
    bool processPayment(double amount) override;
};

// PayPalSubcategory of digital wallet
class PayPal : public PaymentMethod
{
private:
    std::string email;
    double balance;           //Wallet balance
public:
    PayPal(std::string mail, double bal);
    bool processPayment(double amount) override;
};

// Function declaration for batch processing all payments
void processAllPayments(PaymentMethod* paymentArr[], int size, double payAmount);

#endif