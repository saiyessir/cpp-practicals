# Practical 10 – Custom Exception Handling in a Banking Program

## Aim
To practise reporting application-specific failures and handling different errors in a controlled way.

## Custom exception classes
- **InvalidAmount:** Derived from `std::invalid_argument`. It represents a transaction amount that is zero or negative.
- **InsufficientFunds:** Derived from `std::runtime_error`. It represents a withdrawal amount greater than the account's available balance.

## Program description
The `BankAccount` class stores a private balance and provides a `withdraw()` operation. It checks the amount before changing the balance. The program catches each custom exception separately and displays a helpful message.

## Test cases
1. **Successful withdrawal:** Start with Rs. 500.00 and withdraw Rs. 150.00. Expected balance: Rs. 350.00.
2. **Invalid amount:** Attempt to withdraw Rs. 0.00. Expected: `InvalidAmount` is caught and the balance remains Rs. 350.00.
3. **Insufficient funds:** Attempt to withdraw Rs. 400.00 when the balance is Rs. 350.00. Expected: `InsufficientFunds` is caught and the balance remains Rs. 350.00.

## Compile and run
Using g++ with C++17:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o banking_exceptions
./banking_exceptions
```

## Expected output
See [sample-output.txt](sample-output.txt).

## Result
Thus, I successfully created a banking transaction program with custom exception classes. I learned how to throw and catch specific exceptions and ensure that failed transactions do not incorrectly change the account balance.
