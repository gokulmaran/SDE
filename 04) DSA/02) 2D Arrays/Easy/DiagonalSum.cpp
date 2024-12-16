#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/matrix-diagonal-sum/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        int ans = 0;

        // Traverse through each element in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if the element is on the main diagonal or anti-diagonal
                if (i == j || i + j == m - 1) {
                    ans += mat[i][j];
                }
            }
        }

        return ans;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the diagonalSum function to find the sum of the diagonals
    int result = sol.diagonalSum(mat);

    // Output the result
    cout << "The sum of the diagonals is: " << result << endl;

    return 0;
}
