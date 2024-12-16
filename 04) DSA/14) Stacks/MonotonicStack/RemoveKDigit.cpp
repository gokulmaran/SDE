#include <iostream>
#include <stack>
#include <algorithm> // For reverse function

using namespace std;
//link: https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;

        for (char digit : num) {
            while (!s.empty() && k > 0 && s.top() > digit) {
                s.pop();
                k--;
            }
            s.push(digit);
        }

        // Remove remaining digits if k > 0
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        // Construct the result string
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }

        // Reverse the result to get the correct order
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string num1 = "1432219";
    int k1 = 3;
    cout << "Result for num1: " << sol.removeKdigits(num1, k1) << endl; // Expected Output: "1219"

    // Test case 2
    string num2 = "10200";
    int k2 = 1;
    cout << "Result for num2: " << sol.removeKdigits(num2, k2) << endl; // Expected Output: "200"

    // Test case 3
    string num3 = "10";
    int k3 = 2;
    cout << "Result for num3: " << sol.removeKdigits(num3, k3) << endl; // Expected Output: "0"

    // Test case 4
    string num4 = "9";
    int k4 = 1;
    cout << "Result for num4: " << sol.removeKdigits(num4, k4) << endl; // Expected Output: "0"

    return 0;
}
