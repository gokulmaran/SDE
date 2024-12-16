#include <iostream>
#include <string>
using namespace std;
//Link: https://leetcode.com/problems/remove-outermost-parentheses/description/
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans;
        for (char i : s) {
            if (i == '(') {
                if (cnt > 0) {
                    ans += i;
                }
                cnt++;
            } else {
                if (cnt > 1) {
                    ans += i;
                }
                cnt--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    string result = sol.removeOuterParentheses(s);

    cout << "String after removing outer parentheses: " << result << endl;

    return 0;
}
