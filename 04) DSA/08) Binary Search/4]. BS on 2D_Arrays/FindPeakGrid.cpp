#include <iostream>
#include <vector>

using namespace std;
//Link:https://leetcode.com/problems/find-a-peak-element-ii/description/
class Solution {
public:
    // Function to find the index of the row with the maximum value in a specific column
    int maxindex(vector<vector<int>>& mat, int mid, int n) {
        int ind = 0;
        int maxi = mat[0][mid];
        for (int i = 0; i < n; i++) {
            if (mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }

    // Function to find a peak element in the matrix
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s = 0, e = mat[0].size() - 1; // Initialize search space for columns
        int m = mat[0].size(); // Number of columns
        int n = mat.size(); // Number of rows
        int l = 0;
        int h = m - 1;

        while (l <= h) {
            int mid = (l + h) / 2; // Middle column index
            int eleindex = maxindex(mat, mid, n); // Find row with maximum value in the middle column
            int left = mid - 1 >= 0 ? mat[eleindex][mid - 1] : -1; // Value to the left of mid column
            int right = mid + 1 < m ? mat[eleindex][mid + 1] : -1; // Value to the right of mid column

            // Check if the current middle element is greater than its neighbors
            if (mat[eleindex][mid] > left && mat[eleindex][mid] > right) {
                return {eleindex, mid}; // Return the position of the peak
            }
            else if (left < mat[eleindex][mid]) {
                l = mid + 1; // Move to the right half
            }
            else {
                h = mid - 1; // Move to the left half
            }
        }
        return {-1, -1}; // Return -1, -1 if no peak is found (should not happen in a valid input)
    }
};

int main() {
    Solution sol;

    // Test Case 1: Basic test case with a clear peak
    vector<vector<int>> mat1 = {
        {1, 4, 3},
        {2, 5, 4},
        {3, 6, 5}
    };
    vector<int> result1 = sol.findPeakGrid(mat1);
    cout << "Test Case 1: Peak found at (" << result1[0] << ", " << result1[1] << ")\n";

    // Test Case 2: Peak is in the middle of the matrix
    vector<vector<int>> mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result2 = sol.findPeakGrid(mat2);
    cout << "Test Case 2: Peak found at (" << result2[0] << ", " << result2[1] << ")\n";

    // Test Case 3: Peak is on the edge of the matrix
    vector<vector<int>> mat3 = {
        {1, 2, 3},
        {4, 6, 5},
        {7, 8, 6}
    };
    vector<int> result3 = sol.findPeakGrid(mat3);
    cout << "Test Case 3: Peak found at (" << result3[0] << ", " << result3[1] << ")\n";

    // Test Case 4: Matrix with only one row
    vector<vector<int>> mat4 = {
        {1, 2, 3, 4, 5}
    };
    vector<int> result4 = sol.findPeakGrid(mat4);
    cout << "Test Case 4: Peak found at (" << result4[0] << ", " << result4[1] << ")\n";

    // Test Case 5: Matrix with only one column
    vector<vector<int>> mat5 = {
        {1},
        {3},
        {2},
        {4}
    };
    vector<int> result5 = sol.findPeakGrid(mat5);
    cout << "Test Case 5: Peak found at (" << result5[0] << ", " << result5[1] << ")\n";

    return 0;
}
