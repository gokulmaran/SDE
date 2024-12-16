#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;
//Link: https://leetcode.com/problems/modify-the-matrix/
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns
        vector<vector<int>> answer = matrix; // Initialize answer matrix with the original matrix

        // Process each column
        for (int c = 0; c < n; c++) {
            int maxVal = INT_MIN; // Initialize maxVal to the smallest possible integer
            // Find the maximum value in the current column
            for (int r = 0; r < m; r++) {
                maxVal = max(maxVal, matrix[r][c]);
            }
            // Replace all occurrences of -1 in the current column with maxVal
            for (int r = 0; r < m; r++) {
                if (matrix[r][c] == -1) {
                    answer[r][c] = maxVal;
                }
            }
        }

        return answer;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, -1, 3},
        {-1, 5, -1},
        {7, -1, 9}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the modifiedMatrix function to modify the matrix
    vector<vector<int>> result = sol.modifiedMatrix(matrix);

    // Output the result
    cout << "Modified matrix is:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
