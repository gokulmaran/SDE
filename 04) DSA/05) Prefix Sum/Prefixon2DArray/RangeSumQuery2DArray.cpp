#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = dp[i + 1][j] + matrix[i][j] + dp[i][j + 1] - dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};

int main() {
    // Test case 1
    vector<vector<int>> matrix1 = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix numMatrix1(matrix1);
    cout << "Sum of region (2, 1, 4, 3): " << numMatrix1.sumRegion(2, 1, 4, 3) << endl;
    cout << "Sum of region (1, 1, 2, 2): " << numMatrix1.sumRegion(1, 1, 2, 2) << endl;
    cout << "Sum of region (1, 2, 2, 4): " << numMatrix1.sumRegion(1, 2, 2, 4) << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    NumMatrix numMatrix2(matrix2);
    cout << "Sum of region (0, 0, 1, 1): " << numMatrix2.sumRegion(0, 0, 1, 1) << endl;
    cout << "Sum of region (1, 1, 2, 2): " << numMatrix2.sumRegion(1, 1, 2, 2) << endl;
    cout << "Sum of region (0, 0, 2, 2): " << numMatrix2.sumRegion(0, 0, 2, 2) << endl;

    return 0;
}
