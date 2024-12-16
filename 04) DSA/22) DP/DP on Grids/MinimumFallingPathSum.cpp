#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX
using namespace std;
//Link:https://leetcode.com/problems/minimum-falling-path-sum/description/
// Define the Solution class with the minFallingPathSum method
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Populate the dp for the first row
        for(int i = 0; i < dp.size(); i++){
            dp[0][i] = A[0][i];
        }

        // Loop for the rest of the DP matrix
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                // INT_MAX for boundary conditions
                int prevCol = (j >= 1) ? dp[i-1][j-1] + A[i][j] : INT_MAX;
                int nextCol = (j < n-1) ? dp[i-1][j+1] + A[i][j] : INT_MAX;
                int sameCol = dp[i-1][j] + A[i][j];
                dp[i][j] = min(prevCol, min(nextCol, sameCol));
            }
        }

        // Calculating the minimum value in the last row
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Define a sample grid
    vector<vector<int>> grid = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    // Call the minFallingPathSum method
    int result = sol.minFallingPathSum(grid);

    // Output the result
    cout << "Minimum Falling Path Sum: " << result << endl;

    return 0;
}
