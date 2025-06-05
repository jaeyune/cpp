// main.cpp
#include <iostream>
#include "CustomerAccount.h"
using namespace std;

int main() {
    CustomerAccount acc(1000);

    try {
        cout << "현재 잔고: " << acc.getBalance() << "원" << endl;
        acc.deposit(500);
        cout << "입금 후 잔고: " << acc.getBalance() << "원" << endl;
        acc.withdraw(2000);  // 예외 발생 예상
    }
    catch (const AccountException& e) {
        cerr << "예외 발생: " << e.what() << " (금액: " << e.getAmount() << "원)" << endl;
    }

    try {
        acc.deposit(-300);  // 또 다른 예외 발생 예상
    }
    catch (const AccountException& e) {
        cerr << "예외 발생: " << e.what() << " (금액: " << e.getAmount() << "원)" << endl;
    }

    cout << "프로그램 종료" << endl;
    return 0;
}

// ./account_program