#include <iostream>
#include <vector>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/sums-of-i-th-row-and-i-th-column3054/1
int sumOfRowCol(int n, int m, vector<vector<int>> a) {
    // Iterate through rows
    for (int i = 0; i < n; i++) {
        int sum1 = 0, sum2 = 0;
        // Calculate the sum of the i-th row
        for (int j = 0; j < m; j++) {
            sum1 += a[i][j];
        }

        // Calculate the sum of the i-th column
        for (int j = 0; j < n; j++) {
            sum2 += a[j][i];
        }

        // Check if the row sum equals the column sum
        if (sum1 == sum2) {
            return 1; // Found a row where the sum equals the column sum
        }
    }
    return 0; // No row sum matches any column sum
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Number of rows and columns in the matrix
    int n = matrix.size();
    int m = matrix[0].size();

    // Calling the sumOfRowCol function to check the condition
    int result = sumOfRowCol(n, m, matrix);

    // Output the result
    cout << "Is there a row sum equal to the corresponding column sum? " << (result ? "Yes" : "No") << endl;

    return 0;
}
