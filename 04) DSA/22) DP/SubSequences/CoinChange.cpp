#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//Link: https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int coinMemo(vector<int>& coins, int amt, int n, vector<vector<int>>& dp) {
        if (amt == 0) return 0;
        if (n < 0 || amt < 0) return INT_MAX - 1;
        if (dp[n][amt] != -1) return dp[n][amt];
        int take = coinMemo(coins, amt, n - 1, dp);
        int notTake = 1 + coinMemo(coins, amt - coins[n], n, dp);
        return dp[n][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = coinMemo(coins, amount, coins.size() - 1, dp);
        return (ans < INT_MAX - 1) ? ans : -1;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int result1 = solution.coinChange(coins1, amount1);
    cout << "Minimum coins required for amount 11 with coins [1, 2, 5]: " << result1 << endl;

    // Test case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    int result2 = solution.coinChange(coins2, amount2);
    cout << "Minimum coins required for amount 3 with coins [2]: " << result2 << endl;

    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    int result3 = solution.coinChange(coins3, amount3);
    cout << "Minimum coins required for amount 0 with coins [1]: " << result3 << endl;

    return 0;
}
