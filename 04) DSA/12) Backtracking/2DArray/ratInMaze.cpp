#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution {
public:
    bool isSafe(int newx, int newy, vector<vector<bool>>& visited, vector<vector<int>>& m, int n) {
        if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && m[newx][newy] == 1) {
            return true;
        }
        else return false;
    }

    void solve(int x, int y, vector<vector<int>>& m, int n, vector<string>& ans, vector<vector<bool>>& visited, string path) {
        if (x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;

        // Move Down
        if (isSafe(x + 1, y, visited, m, n)) {
            solve(x + 1, y, m, n, ans, visited, path + 'D');
        }
        
        // Move Left
        if (isSafe(x, y - 1, visited, m, n)) {
            solve(x, y - 1, m, n, ans, visited, path + 'L');
        }

        // Move Right
        if (isSafe(x, y + 1, visited, m, n)) {
            solve(x, y + 1, m, n, ans, visited, path + 'R');
        } 

        // Move Up
        if (isSafe(x - 1, y, visited, m, n)) {
            solve(x - 1, y, m, n, ans, visited, path + 'U');
        }

        visited[x][y] = 0; // Backtrack
    }

    vector<string> findPath(vector<vector<int>>& m) {
        vector<string> ans;
        string path = "";
        int n = m.size();
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return ans;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        solve(0, 0, m, n, ans, visited, path);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<string> paths = sol.findPath(maze);

    if (paths.empty()) {
        cout << "No paths found." << endl;
    } else {
        cout << "Paths found:" << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
