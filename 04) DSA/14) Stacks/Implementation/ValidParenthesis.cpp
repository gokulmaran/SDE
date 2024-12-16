#include <iostream>
#include <stack>
#include <string>

using namespace std;
//Link: https://leetcode.com/problems/valid-parentheses/
bool isValid(string s) {
    stack<char> st; // Change stack<int> to stack<char>
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.empty() ||
                (st.top() == '(' && s[i] != ')') ||
                (st.top() == '{' && s[i] != '}') ||
                (st.top() == '[' && s[i] != ']')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4: " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test 5: " << (isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}
