#include <iostream>
#include <vector>
using namespace std;
//Link:https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the dp array
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        // Fill the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    int m, n;

    // Input the dimensions of the grid
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    // Check if dimensions are valid
    if (m <= 0 || n <= 0) {
        cout << "Both m and n should be positive integers." << endl;
        return 1; // Return an error code
    }

    // Input the grid values
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values row by row:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Create an instance of Solution and compute the minimum path sum
    Solution sol;
    int result = sol.minPathSum(grid);

    // Output the result
    cout << "Minimum path sum from top-left to bottom-right: " << result << endl;

    return 0;
}
