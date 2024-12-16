#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
//Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = m - 1; i >= 1; i--) {
            for (int j = i; j <= m - 2; j++) {
                int mini = INT_MAX;
                for (int ind = i; ind <= j; ind++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][cuts.size() - 2];
    }
};

int main() {
    Solution solution;
    
    // Example input
    int n = 7; // Length of the stick
    vector<int> cuts = {1, 3, 4, 5}; // Positions where cuts are to be made
    
    // Call the minCost function
    int result = solution.minCost(n, cuts);
    
    // Output the result
    cout << "Minimum cost to make all cuts: " << result << endl;
    
    return 0;
}
