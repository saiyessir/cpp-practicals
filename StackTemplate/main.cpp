#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// A generic stack that can store values of any suitable data type.
template <typename T>
class Stack {
private:
    std::vector<T> items;

public:
    // Add an item to the top of the stack.
    void push(const T& value) {
        items.push_back(value);
    }

    // Remove and return the top item.
    // Throws an exception if the stack is empty.
    T pop() {
        if (empty()) {
            throw std::out_of_range("Cannot pop: stack is empty.");
        }

        T value = items.back();
        items.pop_back();
        return value;
    }

    // Safely access the top item without removing it.
    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Cannot access top: stack is empty.");
        }

        return items.back();
    }

    bool empty() const {
        return items.empty();
    }
};

int main() {
    std::cout << "GENERIC STACK USING TEMPLATES\n";

    // Test with int values.
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << "\nInteger stack top: " << intStack.top() << '\n';
    std::cout << "Popped integer: " << intStack.pop() << '\n';
    std::cout << "Integer stack top now: " << intStack.top() << '\n';

    // Test with float values.
    Stack<float> floatStack;
    floatStack.push(2.5f);
    floatStack.push(4.75f);
    std::cout << "\nFloat stack top: " << floatStack.top() << '\n';
    std::cout << "Popped float: " << floatStack.pop() << '\n';

    // Test with std::string values.
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("C++ Templates");
    std::cout << "\nString stack top: " << stringStack.top() << '\n';
    std::cout << "Popped string: " << stringStack.pop() << '\n';

    // Test an invalid operation on an empty stack.
    Stack<int> emptyStack;
    std::cout << "\nEmpty stack test:\n";
    std::cout << "Is empty: " << (emptyStack.empty() ? "Yes" : "No") << '\n';

    try {
        emptyStack.pop();
    } catch (const std::out_of_range& error) {
        std::cout << "Handled safely: " << error.what() << '\n';
    }

    return 0;
}
