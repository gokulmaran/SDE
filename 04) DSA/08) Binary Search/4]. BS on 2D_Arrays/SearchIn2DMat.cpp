#include <iostream>
#include <vector>
#include <algorithm>  // For binary_search

using namespace std;
//Link: https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            if(binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target is present in the matrix
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target1 = 5;
    // Expected output: 1 (true)
    cout << "Test Case 1: " << (sol.searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;

    // Test Case 2: Target is not present in the matrix
    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target2 = 15;
    // Expected output: 0 (false)
    cout << "Test Case 2: " << (sol.searchMatrix(matrix2, target2) ? "Found" : "Not Found") << endl;

    // Test Case 3: Matrix contains only one element and target matches
    vector<vector<int>> matrix3 = {
        {5}
    };
    int target3 = 5;
    // Expected output: 1 (true)
    cout << "Test Case 3: " << (sol.searchMatrix(matrix3, target3) ? "Found" : "Not Found") << endl;

    // Test Case 4: Matrix contains only one element and target does not match
    vector<vector<int>> matrix4 = {
        {10}
    };
    int target4 = 5;
    // Expected output: 0 (false)
    cout << "Test Case 4: " << (sol.searchMatrix(matrix4, target4) ? "Found" : "Not Found") << endl;

    // Test Case 5: Empty matrix
    vector<vector<int>> matrix5 = {};
    int target5 = 1;
    // Expected output: 0 (false)
    cout << "Test Case 5: " << (sol.searchMatrix(matrix5, target5) ? "Found" : "Not Found") << endl;

    return 0;
}
