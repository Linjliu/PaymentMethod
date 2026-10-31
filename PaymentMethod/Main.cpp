#include <iostream>
#include "PaymentMethod.h"

int main()
{
    // 创建栈上信用卡对象
    CreditCard myCard("Luke Blow", "4179864676436971", "12/28");

    // 基类指针数组，大小2
    PaymentMethod* payList[2];

    // 第一个元素：栈对象地址 &
    payList[0] = &myCard;

    // 第二个元素：new 在堆上创建PayPal对象
    payList[1] = new PayPal("Luke@example.com", 250.0);

    std::cout << "===== Start Checkout Process =====" << std::endl;
    double transactionAmount = 100.0;

    // 调用批量支付函数
    processAllPayments(payList, 2, transactionAmount);

    // new出来的对象必须手动 delete，防止内存泄漏
    delete payList[1];

    payList[1] = nullptr;

    return 0;
}