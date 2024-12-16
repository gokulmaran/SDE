#include <iostream>
#include <string>
using namespace std;
//Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, opened = 0;
        for (auto x : s) {
            if (x == '(') {
                opened++;
                ans = max(ans, opened);
            }
            else if (x == ')') {
                opened--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string test1 = "((())()";
    cout << "Max depth for \"" << test1 << "\": " << sol.maxDepth(test1) << endl;
    // Expected output: 3

    // Test case 2
    string test2 = "(()(()))";
    cout << "Max depth for \"" << test2 << "\": " << sol.maxDepth(test2) << endl;
    // Expected output: 2

    // Test case 3
    string test3 = "(((";
    cout << "Max depth for \"" << test3 << "\": " << sol.maxDepth(test3) << endl;
    // Expected output: 3

    // Test case 4
    string test4 = ")))(((";
    cout << "Max depth for \"" << test4 << "\": " << sol.maxDepth(test4) << endl;
    // Expected output: 0

    return 0;
}
