#include <iostream>
#include <utility>
using namespace std;

class IntArray {
private:
    int* data; // Private: owns the dynamically allocated array.
    int size;  // Private: keeps the number of elements.

public:
    // Default constructor: creates an empty array.
    IntArray() : data(nullptr), size(0) {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor: creates an array and fills it with a value.
    IntArray(int n, int value) : data(nullptr), size(n > 0 ? n : 0) {
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = value;
            }
        }
        cout << "Parameterized constructor called" << endl;
    }

    // Rule of Five 1/5: copy constructor performs a deep copy.
    IntArray(const IntArray& other)
        : data(other.size > 0 ? new int[other.size] : nullptr),
          size(other.size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        cout << "Copy constructor called" << endl;
    }

    // Rule of Five 2/5: copy assignment safely replaces this object's data.
    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            int* newData = other.size > 0 ? new int[other.size] : nullptr;

            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }

            delete[] data;
            data = newData;
            size = other.size;
        }
        cout << "Copy assignment operator called" << endl;
        return *this;
    }

    // Rule of Five 3/5: move constructor transfers ownership.
    IntArray(IntArray&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor called" << endl;
    }

    // Rule of Five 4/5: move assignment releases old data, then takes ownership.
    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        cout << "Move assignment operator called" << endl;
        return *this;
    }

    // Rule of Five 5/5: destructor releases the owned array.
    ~IntArray() {
        delete[] data;
        cout << "Destructor called" << endl;
    }

    // Public member function to display the array.
    void display() const {
        cout << "Array: ";
        if (size == 0) {
            cout << "Empty";
        } else {
            for (int i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Default Constructor ---" << endl;
    IntArray a;
    a.display();

    cout << "\n--- Parameterized Constructor ---" << endl;
    IntArray b(3, 10);
    b.display();

    cout << "\n--- Copy Constructor ---" << endl;
    IntArray c(b);
    c.display();

    cout << "\n--- Copy Assignment ---" << endl;
    IntArray d;
    d = b;
    d.display();

    cout << "\n--- Move Constructor ---" << endl;
    IntArray e(move(b));
    e.display();
    cout << "Source after move: ";
    b.display();

    cout << "\n--- Move Assignment ---" << endl;
    IntArray f(2, 5);
    f = move(c);
    f.display();
    cout << "Source after move: ";
    c.display();

    cout << "\nObjects will now be destroyed automatically." << endl;
    return 0;
}
