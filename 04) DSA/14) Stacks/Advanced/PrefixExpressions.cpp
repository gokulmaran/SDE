#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string S) {
    stack<int> stack;

    for (char ch : S) {
        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert character to integer
        } else {
            // Otherwise, it's an operator, so pop the top two elements
            int val2 = stack.top();
            stack.pop();
            int val1 = stack.top();
            stack.pop();

            switch (ch) {
                case '+':
                    stack.push(val1 + val2);
                    break;
                case '-':
                    stack.push(val1 - val2);
                    break;
                case '*':
                    stack.push(val1 * val2);
                    break;
                case '/':
                    stack.push(val1 / val2);
                    break;
                
                default:
                    return -1;
            }
        }
    }
    return stack.top();
}

// Main function for testing
int main() {
    // Example postfix expressions
    string postfix1 = "231*+9-";
    string postfix2 = "123*+5-";
    string postfix3 = "456*+2/";

    // Evaluate and print results
    cout << "Result of postfix expression \"" << postfix1 << "\": " << evaluatePostfix(postfix1) << endl;
    cout << "Result of postfix expression \"" << postfix2 << "\": " << evaluatePostfix(postfix2) << endl;
    cout << "Result of postfix expression \"" << postfix3 << "\": " << evaluatePostfix(postfix3) << endl;

    return 0;
}

