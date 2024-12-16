#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;
//link: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
class Solution {
public:
    int find_max(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        int curr_sum = 0;
        set<int> s;
        s.insert(0);
        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];
            auto it = s.lower_bound(curr_sum - k);
            if (it != s.end()) {
                maxi = max(maxi, curr_sum - *it);
            }
            s.insert(curr_sum);
        }
        return maxi;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;

        for (int start_row = 0; start_row < n; start_row++) {
            vector<int> col_array(m, 0);
            for (int end_row = start_row; end_row < n; end_row++) {
                for (int col = 0; col < m; col++) {
                    col_array[col] += matrix[end_row][col];
                }
                int curr_max = find_max(col_array, k);
                maxi = max(maxi, curr_max);
            }
        }

        return maxi;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> matrix1 = {
        {1, 2, -1},
        {-1, -1, 1},
        {1, 2, 1}
    };
    int k1 = 2;
    cout << "Max sum submatrix for test case 1: " << sol.maxSumSubmatrix(matrix1, k1) << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {
        {{5, -4, -3},
         {-2, 7, 6},
         {4, 2, 4}}
    };
    int k2 = 15;
    cout << "Max sum submatrix for test case 2: " << sol.maxSumSubmatrix(matrix2, k2) << endl;

    // Test case 3
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k3 = 20;
    cout << "Max sum submatrix for test case 3: " << sol.maxSumSubmatrix(matrix3, k3) << endl;

    // Test case 4
    vector<vector<int>> matrix4 = {
        {-1, -2},
        {-3, -4}
    };
    int k4 = -3;
    cout << "Max sum submatrix for test case 4: " << sol.maxSumSubmatrix(matrix4, k4) << endl;

    return 0;
}
