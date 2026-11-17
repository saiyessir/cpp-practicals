#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    // Private members protect account data from direct outside access.
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor initialises the account details.
    BankAccount(int accNo, const string& name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Public function to deposit a positive amount.
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful: Rs. " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public function to withdraw only when funds are sufficient.
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful: Rs. " << amount << endl;
        } else {
            cout << "Invalid amount or insufficient balance!" << endl;
        }
    }

    // Public function displays account details without exposing fields directly.
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    // Create two separate BankAccount objects.
    BankAccount account1(101, "Alex", 5000);
    BankAccount account2(102, "Sam", 3000);

    cout << "ACCOUNT 1 DETAILS" << endl;
    account1.display();
    account1.deposit(1000);
    account1.withdraw(500);
    account1.display();

    cout << "\nACCOUNT 2 DETAILS" << endl;
    account2.display();
    account2.deposit(2000);
    account2.withdraw(1000);
    account2.display();

    return 0;
}
