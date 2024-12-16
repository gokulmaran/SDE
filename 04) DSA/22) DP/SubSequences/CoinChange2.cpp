#include <iostream>
#include <vector>

using namespace std;
//Link:https://leetcode.com/problems/coin-change-ii/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (amount == 0) {
            return 1;
        }
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Base case: There's exactly one way to make amount 0, which is to use no coins.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};

// Main function to test the Solution
int main() {
    Solution sol;

    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Number of ways to make amount " << amount1 << ": " 
         << sol.change(amount1, coins1) << endl;

    // Test case 2
    vector<int> coins2 = {2, 5, 3, 6};
    int amount2 = 10;
    cout << "Number of ways to make amount " << amount2 << ": " 
         << sol.change(amount2, coins2) << endl;

    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Number of ways to make amount " << amount3 << ": " 
         << sol.change(amount3, coins3) << endl;

    // Test case 4
    vector<int> coins4 = {1};
    int amount4 = 2;
    cout << "Number of ways to make amount " << amount4 << ": " 
         << sol.change(amount4, coins4) << endl;

    return 0;
}
