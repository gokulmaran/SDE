#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;
//Link: https://leetcode.com/problems/rotate-image/description/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the rotate function to rotate the matrix
    sol.rotate(matrix);

    // Output the rotated matrix
    cout << "Rotated matrix is:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
