#include <iostream>
#include <vector>
#include <algorithm> // For min and max functions

using namespace std;
//Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> rowMin(rows, INT_MAX);
        vector<int> colMax(cols, INT_MIN);

        // Find the minimum value in each row and the maximum value in each column
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        vector<int> res;
        // Identify the lucky numbers
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowMin[i] == matrix[i][j] && colMax[j] == matrix[i][j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the luckyNumbers function to find lucky numbers in the matrix
    vector<int> result = sol.luckyNumbers(matrix);

    // Output the result
    cout << "Lucky numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
