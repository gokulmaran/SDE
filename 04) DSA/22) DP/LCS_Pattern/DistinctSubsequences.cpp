#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Link: https://leetcode.com/problems/distinct-subsequences/
const long long MOD = 1000000007; // A large prime number for modulo

// Function to compute the number of distinct subsequences of s that match t
long long numDistinct(string s, string t) {
    int m = t.size();
    int n = s.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

    // If t is an empty string, there is exactly one subsequence of s that matches t (the empty subsequence).
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
            } else {
                dp[i][j] = dp[i][j - 1] % MOD;
            }
        }
    }

    return dp[m][n];
}

// Main function to test the numDistinct function
int main() {
    string s = "rabbbit";
    string t = "rabbit";

    cout << "Number of distinct subsequences: " << numDistinct(s, t) << endl;

    return 0;
}
