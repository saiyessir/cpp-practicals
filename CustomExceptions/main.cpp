#include <iostream>
#include <stdexcept>
#include <string>

// Represents an amount that is zero or negative.
class InvalidAmount : public std::invalid_argument {
public:
    InvalidAmount()
        : std::invalid_argument("Transaction amount must be greater than zero.") {}
};

// Represents a withdrawal that is greater than the available balance.
class InsufficientFunds : public std::runtime_error {
public:
    InsufficientFunds()
        : std::runtime_error("Insufficient funds for this withdrawal.") {}
};

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            throw InvalidAmount();
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;
        std::cout << "Withdrawal of Rs. " << amount
                  << " completed successfully.\n";
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(500.00);

    std::cout << "BANKING TRANSACTION EXCEPTION HANDLING\n";
    std::cout << "Initial balance: Rs. " << account.getBalance() << "\n\n";

    // Test 1: Successful withdrawal.
    std::cout << "Test 1 - Successful withdrawal:\n";
    try {
        account.withdraw(150.00);
    } catch (const InvalidAmount& error) {
        std::cout << "Invalid amount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        std::cout << "Insufficient funds: " << error.what() << '\n';
    }
    std::cout << "Balance: Rs. " << account.getBalance() << "\n\n";

    // Test 2: Invalid (zero) amount.
    std::cout << "Test 2 - Invalid amount:\n";
    try {
        account.withdraw(0.00);
    } catch (const InvalidAmount& error) {
        std::cout << "Invalid amount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        std::cout << "Insufficient funds: " << error.what() << '\n';
    }
    std::cout << "Balance after failed transaction: Rs. "
              << account.getBalance() << "\n\n";

    // Test 3: Withdrawal greater than the available balance.
    std::cout << "Test 3 - Insufficient funds:\n";
    try {
        account.withdraw(400.00);
    } catch (const InvalidAmount& error) {
        std::cout << "Invalid amount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        std::cout << "Insufficient funds: " << error.what() << '\n';
    }
    std::cout << "Balance after failed transaction: Rs. "
              << account.getBalance() << '\n';

    return 0;
}
