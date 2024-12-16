#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int LCSMemo(string& s1, string& s2, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 0; // Base case: one of the strings is empty
        if (dp[m][n] != -1) return dp[m][n]; // Return result if already computed
        
        if (s1[m - 1] == s2[n - 1]) {
            dp[m][n] = 1 + LCSMemo(s1, s2, m - 1, n - 1, dp); // Characters match
        } else {
            dp[m][n] = max(LCSMemo(s1, s2, m, n - 1, dp), LCSMemo(s1, s2, m - 1, n, dp)); // Characters don't match
        }
        return dp[m][n];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // Initialize dp table
        return LCSMemo(text1, text2, m, n, dp); // Start solving
    }
};

// Main function to test the Solution
int main() {
    Solution sol;

    // Test case 1
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Longest Common Subsequence length between \"" << text1 << "\" and \"" << text2 << "\" is: " 
         << sol.longestCommonSubsequence(text1, text2) << endl;

    // Test case 2
    text1 = "abc";
    text2 = "abc";
    cout << "Longest Common Subsequence length between \"" << text1 << "\" and \"" << text2 << "\" is: " 
         << sol.longestCommonSubsequence(text1, text2) << endl;

    // Test case 3
    text1 = "abc";
    text2 = "def";
    cout << "Longest Common Subsequence length between \"" << text1 << "\" and \"" << text2 << "\" is: " 
         << sol.longestCommonSubsequence(text1, text2) << endl;

    // Test case 4
    text1 = "pmjghexybyrgzczy";
    text2 = "hafc";
    cout << "Longest Common Subsequence length between \"" << text1 << "\" and \"" << text2 << "\" is: " 
         << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
