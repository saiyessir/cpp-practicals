# Practical 9 – Generic Stack Using C++ Templates

## Aim
To understand generic programming and how one class can work with multiple data types.

## Problem
Write a generic Stack class using templates and test it with `int`, `float`, and `std::string` values.

## Class design
- `Stack<T>` is a class template. The type `T` is supplied when an object is declared.
- A private `std::vector<T>` stores the stack elements.
- `push(value)` adds an item to the top.
- `pop()` removes and returns the top item.
- `top()` accesses the top item without removing it.
- `empty()` checks whether the stack contains any items.
- `pop()` and `top()` throw `std::out_of_range` if called on an empty stack.

## How templates help
The same `Stack<T>` implementation works with integers, floating-point numbers, and strings. The compiler creates the appropriate version for each type, so three separate stack classes are not needed.

## Test cases
1. Push and read integer values, then pop an item.
2. Push and read floating-point values, then pop an item.
3. Push and read string values, then pop an item.
4. Check an empty stack and verify that popping from it is handled with an exception.

## Compile and run
Using g++ with C++17:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o stack_demo
./stack_demo
```

## Expected output
See [sample-output.txt](sample-output.txt).

## Result
Thus, I successfully implemented a generic Stack class using a C++ template. I tested it with int, float, and std::string values and learned how templates allow one class to work with different data types. I also handled attempts to pop from an empty stack safely.
