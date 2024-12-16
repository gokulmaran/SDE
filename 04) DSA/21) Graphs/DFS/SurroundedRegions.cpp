#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/surrounded-regions/description/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return; // If the board is empty, return immediately
        int row = board.size();
        int col = board[0].size();

        // Check the first and last columns
        for (int i = 0; i < row; i++) {
            check(board, i, 0);       // First column
            check(board, i, col - 1); // Last column
        }

        // Check the first and last rows
        for (int j = 1; j < col - 1; ++j) {
            check(board, 0, j);       // First row
            check(board, row - 1, j); // Last row
        }

        // Convert remaining 'O's to 'X' and '1's back to 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }

    void check(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1'; // Mark the cell as visited
            // Check all four possible directions
            if (i > 0) check(board, i - 1, j); // Up
            if (j > 0) check(board, i, j - 1); // Left
            if (i + 1 < board.size()) check(board, i + 1, j); // Down
            if (j + 1 < board[0].size()) check(board, i, j + 1); // Right
        }
    }
};

// Main function
int main() {
    Solution sol;

    // Example board configuration
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board:" << endl;
    for (const auto& row : board) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }

    sol.solve(board);

    cout << "\nBoard After Solve:" << endl;
    for (const auto& row : board) {
        for (char c : row) cout << c << ' ';
        cout << endl;
    }

    return 0;
}
