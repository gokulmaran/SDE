#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
class Solution {
public:
    // Function to find the median in a matrix where each row is sorted
    int median(vector<vector<int>> &mat, int r, int c) {
        // Initialize the minimum and maximum values
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        // Find the minimum and maximum values in the matrix
        for (int i = 0; i < r; i++) {
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][c-1]);
        }
        
        // Calculate the position of the median
        int pred = (r * c + 1) / 2;

        // Binary search for the median
        while (mini < maxi) {
            int mid = (mini + maxi) / 2;
            int t = 0;
            
            // Count the number of elements less than or equal to mid
            for (int i = 0; i < r; i++) {
                t += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            // Adjust the search range based on the count
            if (t < pred) {
                mini = mid + 1;
            } else {
                maxi = mid;
            }
        }
        
        // Return the median value
        return maxi;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Basic 3x3 matrix
    vector<vector<int>> mat1 = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median of matrix 1: " << sol.median(mat1, 3, 3) << endl;

    // Test Case 2: 2x3 matrix with different values
    vector<vector<int>> mat2 = {
        {1, 3, 5},
        {2, 6, 8}
    };
    cout << "Median of matrix 2: " << sol.median(mat2, 2, 3) << endl;

    // Test Case 3: Single row matrix
    vector<vector<int>> mat3 = {
        {1, 2, 3, 4, 5}
    };
    cout << "Median of matrix 3: " << sol.median(mat3, 1, 5) << endl;

    // Test Case 4: Single column matrix
    vector<vector<int>> mat4 = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };
    cout << "Median of matrix 4: " << sol.median(mat4, 5, 1) << endl;

    // Test Case 5: Matrix with duplicated values
    vector<vector<int>> mat5 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    cout << "Median of matrix 5: " << sol.median(mat5, 3, 3) << endl;

    return 0;
}
