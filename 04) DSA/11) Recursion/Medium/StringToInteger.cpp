#include <iostream>
#include <string>
#include <climits>
using namespace std;
//Link: https://leetcode.com/problems/string-to-integer-atoi/description/
// Helper function to convert string to integer with recursion
long myatoi(const string& s, int i, int sign, long result) {
    if (sign * result >= INT_MAX) {
        return INT_MAX;
    }
    if (sign * result <= INT_MIN) {
        return INT_MIN;
    }
    if (i >= s.size() || s[i] < '0' || s[i] > '9') {
        return sign * result;
    }
    result = myatoi(s, i + 1, sign, result * 10 + (s[i] - '0'));
    return result;
}

// Function to convert string to integer
int myAtoi(const string& s) {
    int i = 0, n = s.size(), sign = 1;

    // Handle spaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Handle sign
    if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < n && s[i] == '+') {
        i++;
    }

    return static_cast<int>(myatoi(s, i, sign, 0));
}

int main() {
    string str;
    cout << "Enter a string to convert to integer: ";
    getline(cin, str);

    // Call the myAtoi function and store the result
    int result = myAtoi(str);

    // Print the result
    cout << "Converted integer: " << result << endl;

    return 0;
}
