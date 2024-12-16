#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
class Solution {
public:
    int solve(vector<int>& prices, int day, int transactionsLeft, vector<vector<int>>& Memo) {
        if (day == prices.size()) {
            return 0;
        }
        if (transactionsLeft == 0) {
            return 0;
        }
        int &ans = Memo[day][transactionsLeft];
        if (ans != -1) {
            return ans;
        }

        // Choice 1: No transaction on this day
        int ans1 = solve(prices, day + 1, transactionsLeft, Memo);

        // Choice 2: Doing the possible transaction
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);

        if (buy) {
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1, Memo);
        } else {
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1, Memo);
        }
        return ans = max(ans1, ans2);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> Memo(prices.size(), vector<int>(5, -1));
        int ans = solve(prices, 0, 4, Memo);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = solution.maxProfit(prices);

    cout << "Maximum profit is: " << result << endl;

    return 0;
}
