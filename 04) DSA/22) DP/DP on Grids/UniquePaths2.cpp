#include <iostream>
#include <vector>
using namespace std;
//LinK: https://leetcode.com/problems/unique-paths-ii/
//Memorization approach
// 1)functional dp call
// 2)already computed return dp 
// 3)store the dp
// Function to count the number of unique paths in a grid with obstacles using memoization
int solveMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // If the current cell is out of bounds or contains an obstacle, return 0
    if (i < 0 || j < 0 || grid[i][j] == 1) return 0;

    // If the starting cell (0,0) is reached, return 1 as there is exactly one way to stay there
    if (i == 0 && j == 0) return 1;

    // If the result for this cell is already computed, return it from dp table
    if (dp[i][j] != -1) return dp[i][j];

    // Calculate the number of ways to reach this cell by moving from the cell above and the cell to the left
    int up = solveMemo(i - 1, j, grid, dp);
    int left = solveMemo(i, j - 1, grid, dp);

    // Store the result in dp table and return it
    return dp[i][j] = up + left;
}

// Function to calculate the number of unique paths in a grid with obstacles
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(); // Number of rows
    int n = grid[0].size(); // Number of columns

    // Initialize dp table with -1 (uncomputed)
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Start from the bottom-right corner and compute the number of unique paths
    return solveMemo(m - 1, n - 1, grid, dp);
}

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

    // Input the grid
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values (0 for open cell, 1 for obstacle):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Compute the number of unique paths with obstacles
    int result = uniquePathsWithObstacles(grid);

    // Output the result
    cout << "Number of unique paths in the grid with obstacles: " << result << endl;

    return 0;
}
