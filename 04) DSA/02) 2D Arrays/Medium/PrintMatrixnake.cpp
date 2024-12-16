#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1
vector<int> snakePattern(vector<vector<int>> matrix) {   
    vector<int> v;
    int row = matrix.size();    // Number of rows
    int col = matrix[0].size(); // Number of columns

    for (int i = 0; i < row; i++) {
        if (i % 2 == 0) {
            // Traverse left to right for even-indexed rows
            for (int j = 0; j < col; j++) {
                v.push_back(matrix[i][j]);
            }
        } else {
            // Traverse right to left for odd-indexed rows
            for (int j = col - 1; j >= 0; j--) {
                v.push_back(matrix[i][j]);
            }
        }
    }
    return v;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Calling the snakePattern function to get the snake-like traversal
    vector<int> result = snakePattern(matrix);

    // Output the result
    cout << "Snake pattern traversal is:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
