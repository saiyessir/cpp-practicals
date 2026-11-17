# Practical 3: Constructors and the Rule of Five

## Aim
To understand object creation, copying, moving, and safe management of an owned resource in C++.

## What this program demonstrates
- Default constructor and parameterized constructor.
- Copy constructor and copy assignment operator using deep copies.
- Move constructor and move assignment operator transferring ownership.
- Destructor releasing the dynamically allocated array.
- Objects exercising each constructor and assignment operation.

## The Rule of Five
1. **Destructor:** releases the owned dynamic array.
2. **Copy constructor:** creates a separate deep copy.
3. **Copy assignment operator:** safely replaces an object's contents with a deep copy.
4. **Move constructor:** transfers ownership to a newly created object.
5. **Move assignment operator:** releases the target's old resource and transfers ownership.

The default and parameterized constructors are additional constructor forms, not members of the Rule of Five.

## Compile and run
Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o practical
```

Run on Windows (PowerShell):

```powershell
.\practical.exe
```

Run on macOS or Linux:

```bash
./practical
```

## Memory checking
If Valgrind is installed on Linux, run:

```bash
valgrind --leak-check=full ./practical
```

If Valgrind is not available, use AddressSanitizer as an alternative:

```bash
g++ -std=c++17 -fsanitize=address -fno-omit-frame-pointer -g main.cpp -o practical
./practical
```

**Evidence note:** No memory checker has been run as part of this repository upload. Run Valgrind or AddressSanitizer on your laptop and include the actual result in your practical record. Do not claim a clean check unless the tool reports no errors.

## Sample output
See [sample-output.txt](sample-output.txt).

## Result / Observation
I learned how default, parameterized, copy, and move constructors work. I also learned how the Rule of Five helps manage dynamically allocated memory safely through deep copying, ownership transfer, and resource cleanup.
