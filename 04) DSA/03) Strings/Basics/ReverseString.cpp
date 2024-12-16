#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/reverse-string/description/
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

int main() {
    Solution sol;

    // Prompt the user for input
    cout << "Enter a string to reverse: ";
    string input;
    cin >> input;

    // Convert the input string to a vector of characters
    vector<char> charVector(input.begin(), input.end());

    // Reverse the vector
    sol.reverseString(charVector);

    // Convert the vector back to a string
    string reversedString(charVector.begin(), charVector.end());

    // Output the reversed string
    cout << "Reversed string: " << reversedString << endl;

    return 0;
}
