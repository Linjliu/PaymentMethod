
#include "PaymentMethod.h"
#include <iostream>
#include <cstring>

// CreditCard construct
CreditCard::CreditCard(std::string name, std::string ccn, std::string exp)
    : ownerName(name), cardNumber(ccn), expireDate(exp)
{}

// Credit card payment verification: the card number must be 16 digits, with simple verification of the expiry date
bool CreditCard::processPayment(double amount)
{
    std::cout << "\n===== Credit Card Payment =====" << std::endl;
    std::cout << "Owner: " << ownerName << std::endl;
    std::cout << "Card No: " << cardNumber << std::endl;
    std::cout << "Trying to pay: $" << amount << std::endl;

    // Verify card number length
    if (cardNumber.length() != 16)
    {
        std::cout << "Failed: Card number must be 16 digits!" << std::endl;

        return false;
    }

    for (char c : cardNumber)
    {
        if (!isdigit(c))
        {
            std::cout << "Failed: Card number must contain only digits!" << std::endl;
            
            return false;
        }
    }

    if (expireDate.length() != 5 || expireDate[2] != '/')
    {
        std::cout << "Failed: Invalid expiration date format!" << std::endl;
        
        return false;
    }

    // It expires if the year is less than 26
    std::string yearStr = expireDate.substr(3, 2);
    int year = stoi(yearStr);
    if (year < 26)
    {
        std::cout << "Failed: Credit card expired!" << std::endl;
        
        return false;
    }

    std::cout << "Success! Credit card payment approved." << std::endl;
    
    return true;
}

// PayPal 构造
PayPal::PayPal(std::string mail, double bal)
    : email(mail), balance(bal)
{
}

// PayPal：Check whether the balance is sufficient and simply determine whether @ is included
bool PayPal::processPayment(double amount)
{
    std::cout << "\n===== PayPal Payment =====" << std::endl;
    std::cout << "Account Email: " << email << std::endl;
    std::cout << "Account Balance: $" << balance << std::endl;
    std::cout << "Trying to pay: $" << amount << std::endl;

    // Simple email validation to check if it contains @
    if (email.find('@') == std::string::npos)
    {
        std::cout << "Failed: Invalid email address!" << std::endl;
        
        return false;
    }

    if (balance < amount)
    {
        std::cout << "Failed: Balance is not enough!" << std::endl;
        
        return false;
    }

    balance -= amount;
    std::cout << "Success! PayPal payment approved. Remaining balance: $" << balance << std::endl;
    
    return true;
}

// Implementation of Batch Payment Function
void processAllPayments(PaymentMethod* paymentArr[], int size, double payAmount)
{
    for (int i = 0; i < size; i++)
    {
        if (paymentArr[i] != nullptr)
        {
            paymentArr[i]->processPayment(payAmount);
        }
    }
}