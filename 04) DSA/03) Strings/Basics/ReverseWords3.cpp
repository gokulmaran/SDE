#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};

int main() {
    Solution sol;

    // Prompt the user for input
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Call the method to reverse the words
    string result = sol.reverseWords(input);

    // Output the resulting string
    cout << "Reversed words: " << result << endl;

    return 0;
}
