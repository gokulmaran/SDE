#include <iostream>
#include <vector>

using namespace std;
//Link:https://leetcode.com/problems/min-stack/
class MinStack {
public:
    vector<vector<int>> st; // Stack to store pairs of (value, minimum value up to this point)

    // Constructor
    MinStack() {}

    // Push method to add an element to the stack
    void push(int val) {
        int min_val = getMin(); // Get the current minimum value
        if (st.empty() || min_val > val) {
            min_val = val; // Update the minimum value if the stack is empty or val is smaller
        }
        st.push_back({val, min_val}); // Push the value and updated minimum value
    }

    // Pop method to remove the top element from the stack
    void pop() {
        if (!st.empty()) {
            st.pop_back(); // Remove the top element
        }
    }

    // Top method to get the top element of the stack
    int top() {
        return st.empty() ? -1 : st.back()[0]; // Return the top value or -1 if stack is empty
    }

    // GetMin method to retrieve the minimum value in the stack
    int getMin() {
        return st.empty() ? -1 : st.back()[1]; // Return the minimum value or -1 if stack is empty
    }
};

int main() {
    // Create a MinStack object
    MinStack* obj = new MinStack();

    // Push elements onto the stack
    obj->push(3);
    obj->push(5);
    cout << "Top element: " << obj->top() << endl;     // Should print 5
    cout << "Minimum value: " << obj->getMin() << endl; // Should print 3

    obj->push(2);
    obj->push(1);
    cout << "Top element: " << obj->top() << endl;     // Should print 1
    cout << "Minimum value: " << obj->getMin() << endl; // Should print 1

    obj->pop();
    cout << "Top element after pop: " << obj->top() << endl; // Should print 2
    cout << "Minimum value after pop: " << obj->getMin() << endl; // Should print 2

    obj->pop();
    cout << "Top element after another pop: " << obj->top() << endl; // Should print 5
    cout << "Minimum value after another pop: " << obj->getMin() << endl; // Should print 3

    // Clean up
    delete obj;

    return 0;
}
