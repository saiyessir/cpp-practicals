# Abstract Shape Class and Runtime Polymorphism

## AIM
To demonstrate how an abstract base-class interface calls the correct derived-class function at runtime.

## Classes and formulas
- `Shape`: abstract base class with pure virtual `area()` and a virtual destructor.
- `Circle`: calculates area using pi × radius × radius.
- `Rectangle`: calculates area using length × width.
- `Triangle`: calculates area using 0.5 × base × height.

## Sample dimensions
- Circle radius = 5
- Rectangle length = 4 and width = 6
- Triangle base = 8 and height = 3

## Sample output
```text
Area of different shapes:
Circle area: 78.54
Rectangle area: 24.00
Triangle area: 12.00
```

## Virtual functions and runtime polymorphism
A virtual function allows a derived-class implementation to be selected when called through a base-class pointer or reference. In this program, each element is accessed through a `Shape` pointer, but the correct `Circle::area()`, `Rectangle::area()`, or `Triangle::area()` function runs at runtime. This is runtime polymorphism.

## Why Shape cannot be instantiated
The `area()` function is declared pure virtual using `= 0`. Therefore, Shape is an abstract class and cannot be instantiated directly. It defines an interface that derived classes must implement.

The virtual destructor ensures that derived objects are safely destroyed when owned through a base-class pointer. The example uses `unique_ptr` to manage object lifetimes automatically.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o shapes
./shapes
```

## Result / observation
The program successfully demonstrates abstraction and runtime polymorphism. The area function belonging to the correct derived class is called through a Shape pointer, showing how a common base-class interface can support different implementations.
