#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/count-sorted-rows2702/1
int sortedCount(int N, int M, vector<vector<int>> mat) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int ci = 0; // Count of increasing adjacent elements
        int cd = 0; // Count of decreasing adjacent elements
        for (int j = 0; j < M - 1; j++) {
            if (mat[i][j] < mat[i][j + 1]) {
                ci++;
            } else if (mat[i][j + 1] < mat[i][j]) {
                cd++;
            }
        }
        // If the row is either fully non-decreasing or non-increasing
        if (ci == M - 1 || cd == M - 1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 3, 2}
    };

    // Number of rows and columns in the matrix
    int N = matrix.size();
    int M = matrix[0].size();

    // Calling the sortedCount function to get the count of sorted rows
    int result = sortedCount(N, M, matrix);

    // Output the result
    cout << "Number of sorted rows: " << result << endl;

    return 0;
}
