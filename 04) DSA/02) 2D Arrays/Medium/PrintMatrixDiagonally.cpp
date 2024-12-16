#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // For std::reverse

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
vector<int> matrixDiagonally(vector<vector<int>>& mat) {
    map<int, vector<int>> m; // To store diagonals
    int n = mat.size();      // Number of rows
    int p = mat[0].size();   // Number of columns

    // Collect elements by diagonal indices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            m[i + j].push_back(mat[i][j]);
        }
    }

    // Prepare the result vector
    vector<int> ans;
    for (auto& it : m) {
        if (it.first % 2 == 0) {
            reverse(it.second.begin(), it.second.end());
        }
        ans.insert(ans.end(), it.second.begin(), it.second.end());
    }
    return ans;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Calling the matrixDiagonally function to get the diagonal traversal
    vector<int> result = matrixDiagonally(matrix);

    // Output the result
    cout << "Matrix diagonal traversal is:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
