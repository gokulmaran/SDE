#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit;
                if (buy) {
                    int buyAction = -p[i] + dp[i + 1][0];
                    int notBuy = dp[i + 1][1];
                    profit = max(buyAction, notBuy);
                } else {
                    int sellAction = p[i] + dp[i + 1][1];
                    int notSell = dp[i + 1][0];
                    profit = max(sellAction, notSell);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = solution.maxProfit(prices);

    cout << "Maximum profit is: " << result << endl;

    return 0;
}
