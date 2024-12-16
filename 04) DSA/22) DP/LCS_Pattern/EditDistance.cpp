#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//Link:https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) { // same characters
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], 
                                    dp[i - 1][j], dp[i][j - 1]}) + 1;
                    // replace      // delete    // insert
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solution;

    string word1 = "kitten";
    string word2 = "sitting";

    int result = solution.minDistance(word1, word2);
    cout << "Minimum distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << result << endl;

    return 0;
}
