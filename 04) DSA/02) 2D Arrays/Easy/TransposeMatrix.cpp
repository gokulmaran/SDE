#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/transpose-matrix/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();      // Number of rows in the input matrix
        int n = matrix[0].size();   // Number of columns in the input matrix
        
        // Create a new matrix with dimensions transposed
        vector<vector<int>> arr(n, vector<int>(m, 0));
        
        // Fill in the transposed matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[j][i] = matrix[i][j];
            }
        }
        
        return arr;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the transpose function to compute the transpose of the matrix
    vector<vector<int>> result = sol.transpose(matrix);

    // Output the result
    cout << "The transposed matrix is:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
