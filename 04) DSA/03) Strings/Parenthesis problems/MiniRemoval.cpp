#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> arr(s.begin(), s.end());
        int opened = 0;
        // First pass: mark excess '(' with '#'
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(') {
                opened++;
            } else if (arr[i] == ')') {
                if (opened == 0) {
                    arr[i] = '#';
                } else {
                    opened--;
                }
            }
        }
        // Second pass: mark excess '(' from the end
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (opened > 0 && arr[i] == '(') {
                arr[i] = '#';
                opened--;
            }
        }
        // Remove '#' and build the final string
        string ans;
        for (auto x : arr) {
            if (x != '#') {
                ans += x;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Prompt the user for input
    cout << "Enter a string with parentheses: ";
    string input;
    getline(cin, input);

    // Call the method to remove invalid parentheses
    string result = sol.minRemoveToMakeValid(input);

    // Output the result
    cout << "The string after removing invalid parentheses: " << result << endl;

    return 0;
}
