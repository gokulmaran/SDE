#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/set-matrix-zeroes/description/
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();      // Number of rows
        int m = mat[0].size();   // Number of columns
        vector<int> row(n, 0);   // To keep track of rows with zeros
        vector<int> col(m, 0);   // To keep track of columns with zeros

        // Identify rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Set rows to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the setZeroes function to modify the matrix
    sol.setZeroes(matrix);

    // Output the modified matrix
    cout << "Modified matrix is:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
