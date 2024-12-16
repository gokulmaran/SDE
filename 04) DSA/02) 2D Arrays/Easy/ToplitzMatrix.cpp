#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/toeplitz-matrix/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns
        
        // Check if all elements in each descending diagonal are the same
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the isToeplitzMatrix function to check if the matrix is a Toeplitz matrix
    bool result = sol.isToeplitzMatrix(matrix);

    // Output the result
    cout << "The matrix is " << (result ? "a Toeplitz matrix." : "not a Toeplitz matrix.") << endl;

    return 0;
}
