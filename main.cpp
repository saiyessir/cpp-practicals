#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables and data types
    string name;
    int age, num1, num2;
    double average;
    char grade;
    bool isStudent = true;

    // Constant
    const double PI = 3.14159;

    // Input
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "Enter your grade letter: ";
    cin >> grade;

    // Output and operators
    cout << "\n--- Student Details ---\n";
    cout << "Name: " << name << '\n';
    cout << "Age: " << age << '\n';
    cout << "Grade: " << grade << '\n';
    cout << "Is student: " << (isStudent ? "Yes" : "No") << '\n';
    cout << "Constant PI: " << PI << '\n';

    cout << "\n--- Arithmetic Operators ---\n";
    cout << "Addition: " << num1 + num2 << '\n';
    cout << "Subtraction: " << num1 - num2 << '\n';
    cout << "Multiplication: " << num1 * num2 << '\n';
    if (num2 != 0) {
        cout << "Division: " << static_cast<double>(num1) / num2 << '\n';
    } else {
        cout << "Division: Cannot divide by zero\n";
    }

    // Relational and logical operators
    cout << "\n--- Relational and Logical Operators ---\n";
    cout << "Age is 18 or above: " << (age >= 18 ? "Yes" : "No") << '\n';
    cout << "First number is greater: " << (num1 > num2 ? "Yes" : "No") << '\n';
    cout << "Both numbers are positive: "
         << ((num1 > 0 && num2 > 0) ? "Yes" : "No") << '\n';

    return 0;
}
