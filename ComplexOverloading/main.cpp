#include <iostream>
#include <iomanip>
using namespace std;

// Function overloading: same name, different parameter types.
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0)
        : real(r), imaginary(i) {}

    // Operator overloading: define + for two ComplexNumber objects.
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real,
                             imaginary + other.imaginary);
    }

    void display() const {
        cout << real;
        if (imaginary >= 0) {
            cout << " + " << imaginary << "i";
        } else {
            cout << " - " << -imaginary << "i";
        }
    }
};

int main() {
    cout << "FUNCTION OVERLOADING\n";
    cout << "add(10, 20) = " << add(10, 20) << '\n';
    cout << "add(2.5, 3.7) = " << add(2.5, 3.7) << '\n';

    cout << "\nOPERATOR OVERLOADING\n";
    ComplexNumber first(3.0, 4.0);
    ComplexNumber second(2.0, 5.0);

    cout << "First complex number: ";
    first.display();
    cout << '\n';

    cout << "Second complex number: ";
    second.display();
    cout << '\n';

    ComplexNumber result = first + second;
    cout << "Sum: ";
    result.display();
    cout << '\n';

    return 0;
}
