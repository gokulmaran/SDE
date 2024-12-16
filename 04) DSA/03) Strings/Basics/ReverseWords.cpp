#include <iostream>
#include <string>
#include <sstream>

using namespace std;
//link: https://leetcode.com/problems/reverse-words-in-a-string/description/
class Solution {
public:
    string reverseWords(string s) {
        stringstream all(s);
        string word, ans = "";
        while (all >> word) {
            ans = word + " " + ans;
        }
        return ans.substr(0, ans.length() - 1); // Remove trailing space
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
