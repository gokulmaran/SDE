#include <iostream>

using namespace std;

class MyStack {
private:
    int arr[1000]; // Array to hold stack elements
    int top;      // Index of the top element

public:
    MyStack();    // Constructor
    void push(int x); // Method to push element onto the stack
    int pop();    // Method to pop element from the stack
    bool isEmpty(); // Method to check if the stack is empty
    bool isFull(); // Method to check if the stack is full
};

// Constructor initializes the top index
MyStack::MyStack() : top(-1) {}

// Method to push an element onto the stack
void MyStack::push(int x) {
    if (top >= 999) {
        cout << "Stack overflow" << endl;
        return;
    }
    arr[++top] = x;
}

// Method to pop an element from the stack
int MyStack::pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return -1; // Returning -1 if the stack is empty
    }
    return arr[top--];
}

// Method to check if the stack is empty
bool MyStack::isEmpty() {
    return top == -1;
}

// Method to check if the stack is full
bool MyStack::isFull() {
    return top == 999;
}

int main() {
    MyStack stack;

    // Test pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    // Test popping elements from the stack
    cout << "Popped: " << stack.pop() << endl; // Should print 40
    cout << "Popped: " << stack.pop() << endl; // Should print 30

    // Test pushing more elements
    stack.push(50);
    stack.push(60);

    // Test popping all elements
    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << endl;
    }

    // Test popping from an empty stack
    cout << "Popped: " << stack.pop() << endl; // Should indicate stack underflow

    return 0;
}
