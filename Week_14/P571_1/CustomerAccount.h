#ifndef CUSTOMER_ACCOUNT_H
#define CUSTOMER_ACCOUNT_H

#include <string>
#include <stdexcept>
using namespace std;

// 예외 클래스 정의
class AccountException {
    string message;
    int amount;
public:
    AccountException(string msg, int amt) : message(msg), amount(amt) {}

    string what() const { return message; }
    int getAmount() const { return amount; }
};

// CustomerAccount 클래스 정의
class CustomerAccount {
    int balance;
public:
    CustomerAccount(int b = 0) : balance(b) {}

    int getBalance() const { return balance; }

    int deposit(int amount) {
        if (amount <= 0)
            throw AccountException("입금액은 0보다 커야 합니다.", amount);
        balance += amount;
        return balance;
    }

    int withdraw(int amount) {
        if (amount > balance)
            throw AccountException("잔고보다 큰 금액을 출금할 수 없습니다.", amount);
        balance -= amount;
        return balance;
    }
};

#endif
