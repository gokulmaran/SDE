#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/unique-paths/description/
/*Tabulation approach
1)Initialize dp &Declare base cases
2)exlore for loops
3)copy recurrence
4)return dp*/
// Function to compute the number of unique paths in an m x n grid
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;

    // Input the dimensions of the grid
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    // Check if the dimensions are valid
    if (m <= 0 || n <= 0) {
        cout << "Both m and n should be positive integers." << endl;
        return 1;  // Return an error code
    }

    // Compute the number of unique paths
    int result = uniquePaths(m, n);

    // Output the result
    cout << "Number of unique paths in a " << m << " x " << n << " grid: " << result << endl;

    return 0;
}
