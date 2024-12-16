#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case
        dp[n][0] = 0;
        dp[n][1] = 0;

        // Explore all paths (bottom-up)
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 1; canBuy >= 0; canBuy--) {
                int buy = -1e9, sell = -1e9;
                if (canBuy) {
                    buy = -prices[idx] + dp[idx + 1][!canBuy];
                } else {
                    sell = prices[idx] - fee + dp[idx + 1][!canBuy];
                }
                int move_on = dp[idx + 1][canBuy];
                dp[idx][canBuy] = max({buy, sell, move_on});
            }
        }

        return dp[0][1];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {1, 3, 2, 8, 4, 9}; // Example prices
    int fee = 2; // Transaction fee

    int result = solution.maxProfit(prices, fee);

    cout << "Maximum profit with a transaction fee of " << fee << " is: " << result << endl;

    return 0;
}
