# Practical 2: BankAccount Class

## Aim
To understand how classes combine data and behaviour, and how access specifiers (private and public) protect data in C++.

## Concepts demonstrated
- A `BankAccount` class with private data members: account number, account holder, and balance.
- Public member functions: `deposit()`, `withdraw()`, and `display()`.
- A constructor to initialise each account.
- Basic validation for initial balance, deposit, and withdrawal amounts.
- Two objects created and used in `main()`.

## Private and public members
- **Private members** protect account information. They cannot be accessed directly from outside the class.
- **Public members** provide controlled ways to use the class, such as depositing, withdrawing, and displaying account details.

## Compile and run
From this folder, compile with:

```bash
g++ -std=c++17 main.cpp -o practical
```

Run on Windows:

```powershell
.\practical.exe
```

Run on macOS or Linux:

```bash
./practical
```

## Sample output
See [sample-output.txt](sample-output.txt).

## Result / Observation
I learned how to create classes and objects in C++, initialise objects using constructors, and protect data using private and public access specifiers. I also learned to perform operations through public member functions.
