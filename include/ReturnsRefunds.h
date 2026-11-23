
#ifndef RETURNSREFUNDS_H
#define RETURNSREFUNDS_H

#include <iostream>
#include <string>

using namespace std;

class ReturnRequest {
private:
    int returnID;
    string productName;
    double refundAmount;

public:
    ReturnRequest(int id, string name, double amount) {
        returnID = id;
        productName = name;
        refundAmount = amount;
    }

    double getRefundAmount() const {
        return refundAmount;
    }

    void displayRequest() const {
        cout << "\n--- Return Request ---" << endl;
        cout << "Return ID: " << returnID << endl;
        cout << "Product: " << productName << endl;
        cout << "Refund Amount: " << refundAmount << endl;
    }
};

class DigitalWallet {
private:
    double balance;

public:
    DigitalWallet(double initialBalance) {
        balance = initialBalance;
    }

    void addMoney(double amount) {
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }

    void displayBalance() const {
        cout << "Wallet Balance: " << balance << endl;
    }
};

class RefundProcessor {
public:
    void processRefund(const ReturnRequest& request,
                       DigitalWallet& wallet) {
        wallet.addMoney(request.getRefundAmount());

        cout << "Refund of "
             << request.getRefundAmount()
             << " processed successfully." << endl;
    }
};

#endif
