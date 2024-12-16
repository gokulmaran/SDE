#include <iostream>
#include <string>
#include <cctype> // For isalpha
#include <algorithm> // For swap

using namespace std;
//Link: https://leetcode.com/problems/reverse-only-letters/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
            } else if (!isalpha(s[j])) {
                j--;
            } else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Prompt the user for input
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Call the method to reverse only the letters
    string result = sol.reverseOnlyLetters(input);

    // Output the resulting string
    cout << "Resulting string: " << result << endl;

    return 0;
}
