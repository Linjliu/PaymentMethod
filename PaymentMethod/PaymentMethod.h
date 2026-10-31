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

// 信用卡子类
class CreditCard : public PaymentMethod
{
private:
    std::string ownerName;    // 持卡人姓名
    std::string cardNumber;   // 卡号
    std::string expireDate;   // 有效期 MM/YY
public:
    CreditCard(std::string name, std::string ccn, std::string exp);
    bool processPayment(double amount) override;
};

// PayPal数字钱包子类
class PayPal : public PaymentMethod
{
private:
    std::string email;
    double balance;           // 钱包余额
public:
    PayPal(std::string mail, double bal);
    bool processPayment(double amount) override;
};

// 批量处理所有支付的函数声明
void processAllPayments(PaymentMethod* paymentArr[], int size, double payAmount);

#endif