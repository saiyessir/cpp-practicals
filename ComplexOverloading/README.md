# Function Overloading and Operator Overloading

## AIM
To understand how C++ selects overloaded functions at compile time and how operators can be defined for user-created classes.

## Program description
1. The two `add()` functions demonstrate function overloading: one accepts integers and the other accepts doubles.
2. The `ComplexNumber` class stores real and imaginary parts.
3. The `+` operator is overloaded to add the real parts and imaginary parts of two complex numbers.

## Sample output
```text
FUNCTION OVERLOADING
add(10, 20) = 30
add(2.5, 3.7) = 6.2

OPERATOR OVERLOADING
First complex number: 3 + 4i
Second complex number: 2 + 5i
Sum: 5 + 9i
```

## Difference between the concepts
- **Function overloading:** Multiple functions share a name but have different parameter lists. The compiler selects the matching function based on the arguments.
- **Operator overloading:** Gives an existing operator (here, `+`) a suitable meaning for a user-defined type such as ComplexNumber.
- **Runtime polymorphism:** Selects an overridden virtual function at runtime through a base-class pointer or reference. It differs from overloading, which is resolved at compile time.

## Why overload the + operator?
The `+` operator makes adding complex numbers natural and readable. It combines the real parts and imaginary parts separately, just as expected in complex-number arithmetic.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o complex
./complex
```

## Result / observation
The program demonstrates function overloading using two `add()` functions and operator overloading using the `+` operator in the ComplexNumber class. The compiler selects the correct function based on argument types, while the overloaded operator makes object addition clear and convenient.
