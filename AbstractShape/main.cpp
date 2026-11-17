#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;

// Abstract base class: every Shape must provide its own area().
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual ~Shape() = default;      // Safe deletion through base pointer
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        const double pi = 3.141592653589793;
        return pi * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    // Shape is abstract, so objects of Shape itself cannot be created.
    // Derived objects are stored using pointers to the Shape interface.
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(make_unique<Triangle>(8.0, 3.0));

    const char* names[] = {"Circle", "Rectangle", "Triangle"};

    cout << fixed << setprecision(2);
    cout << "Area of different shapes:\n";

    for (size_t i = 0; i < shapes.size(); ++i) {
        // Runtime polymorphism calls the matching derived area() method.
        cout << names[i] << " area: " << shapes[i]->area() << '\n';
    }

    return 0;
}
