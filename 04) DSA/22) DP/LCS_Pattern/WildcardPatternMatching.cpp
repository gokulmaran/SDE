#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link:https://leetcode.com/problems/wildcard-matching/
class Solution {
public:
    // Tabulation approach
    bool isMatchTabulation(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[0][j + 1] = true;
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[s.size()][p.size()];
    }

    // Memoization approach
    bool isMatchMemoization(string s, string p) {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return isMatchHelper(s, p, 0, 0, memo);
    }

private:
    bool isMatchHelper(const string& s, const string& p, int i, int j, vector<vector<int>>& memo) {
        if (j == p.size()) return i == s.size();
        if (i == s.size()) {
            while (j < p.size() && p[j] == '*') ++j;
            return j == p.size();
        }
        if (memo[i][j] != -1) return memo[i][j] == 1;

        bool match = false;
        if (p[j] == '*') {
            match = isMatchHelper(s, p, i + 1, j, memo) || isMatchHelper(s, p, i, j + 1, memo);
        } else {
            match = (s[i] == p[j] || p[j] == '?') && isMatchHelper(s, p, i + 1, j + 1, memo);
        }

        memo[i][j] = match ? 1 : 0;
        return match;
    }
};

int main() {
    Solution solution;

    string s = "adceb";
    string p = "*a*b";

    bool tabulationResult = solution.isMatchTabulation(s, p);
    cout << "Tabulation - Does the string \"" << s << "\" match the pattern \"" << p << "\"? " << (tabulationResult ? "Yes" : "No") << endl;

    bool memoizationResult = solution.isMatchMemoization(s, p);
    cout << "Memoization - Does the string \"" << s << "\" match the pattern \"" << p << "\"? " << (memoizationResult ? "Yes" : "No") << endl;

    return 0;
}
