#include <iostream>
#include <queue>

using namespace std;
//Link: https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> q;   // Queue to store elements in stack order

    // Constructor
    MyStack() {}

    // Method to push an element onto the stack
    void push(int x) {
        q.push(x);
        int n = q.size();

        // Rotate the queue to make the newly pushed element the front
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Method to pop an element from the stack
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Indicate error for empty stack
        }
        int result = q.front();
        q.pop();
        return result;
    }

    // Method to get the top element of the stack
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Indicate error for empty stack
        }
        return q.front();
    }

    // Method to check if the stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    // Create a MyStack object
    MyStack* obj = new MyStack();

    // Push elements onto the stack
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);

    // Print the top element
    cout << "Top element: " << obj->top() << endl; // Should print 40

    // Pop elements from the stack
    cout << "Popped: " << obj->pop() << endl; // Should print 40
    cout << "Popped: " << obj->pop() << endl; // Should print 30

    // Push more elements
    obj->push(50);
    obj->push(60);

    // Print the top element again
    cout << "Top element: " << obj->top() << endl; // Should print 60

    // Pop all elements
    while (!obj->empty()) {
        cout << "Popped: " << obj->pop() << endl;
    }

    // Try popping from an empty stack
    cout << "Popped: " << obj->pop() << endl; // Should indicate stack is empty

    // Clean up
    delete obj;

    return 0;
}
