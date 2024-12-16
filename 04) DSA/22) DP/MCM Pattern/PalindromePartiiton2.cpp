#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/
class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            int minStep = INT_MAX;
            for (int k = i; k < n; k++) {
                if (isPalindrome(s, i, k)) {
                    int steps = 1 + dp[k + 1];
                    minStep = min(minStep, steps);
                }
            }
            dp[i] = minStep;
        }
        return dp[0] - 1;
    }
};

int main() {
    Solution solution;
    
    // Example input
    string s = "aab"; // The string for which we want to find the minimum cut
    
    // Call the minCut function
    int result = solution.minCut(s);
    
    // Output the result
    cout << "Minimum number of cuts needed: " << result << endl;
    
    return 0;
}
