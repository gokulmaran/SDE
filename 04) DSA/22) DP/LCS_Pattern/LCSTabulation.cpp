#include <iostream>
#include <string>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Initialize DP table

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n]; // Return the length of LCS
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
