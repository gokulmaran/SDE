#include <iostream>
#include <algorithm>
#include <string>
//Link:https:leetcode.com/problems/shortest-common-supersequence/description/
class Solution {
public:
    std::string shortestCommonSupersequence(std::string a, std::string b) {
        int n = a.length();
        int m = b.length();

        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        std::string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(a[i-1] == b[j-1]) {
                ans += a[i-1];
                i--, j--;
            } else {
                if(dp[i][j-1] > dp[i-1][j]) {
                    ans += b[j-1];
                    j--;
                } else {
                    ans += a[i-1];
                    i--;
                }
            }
        }
        while(i > 0) {
            ans += a[i-1];
            i--;
        }
        while(j > 0) {
            ans += b[j-1];
            j--;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    std::string a1 = "abac";
    std::string b1 = "cab";
    std::cout << "Shortest Common Supersequence of \"" << a1 << "\" and \"" << b1 << "\" is: " 
              << sol.shortestCommonSupersequence(a1, b1) << std::endl;

    // Example 2
    std::string a2 = "geek";
    std::string b2 = "eke";
    std::cout << "Shortest Common Supersequence of \"" << a2 << "\" and \"" << b2 << "\" is: " 
              << sol.shortestCommonSupersequence(a2, b2) << std::endl;

    // Example 3
    std::string a3 = "abc";
    std::string b3 = "def";
    std::cout << "Shortest Common Supersequence of \"" << a3 << "\" and \"" << b3 << "\" is: " 
              << sol.shortestCommonSupersequence(a3, b3) << std::endl;

    return 0;
}
