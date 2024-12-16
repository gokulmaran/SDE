#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
//Link: https://leetcode.com/problems/rotting-oranges/description/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0, cnt = 0;
        queue<pair<int, int>> q;

        // Inserting rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] != 0) {
                    tot++;
                }
            }
        }

        // Directions for right, left, down, and up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int ans = 0;

        // Process the queue
        while (!q.empty()) {
            int k = q.size();
            cnt += k;
            while (k--) {
                int y = q.front().second;
                int x = q.front().first;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) {
                        continue;
                    }
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if (!q.empty()) {
                ans++;
            }
        }

        if (tot == cnt) {
            return ans;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {
        {2, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Minimum time for all oranges to rot (Example 1): " << sol.orangesRotting(grid1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {2, 2, 2, 2, 2},
        {2, 1, 1, 1, 2},
        {2, 1, 1, 1, 2},
        {2, 2, 2, 2, 2}
    };
    cout << "Minimum time for all oranges to rot (Example 2): " << sol.orangesRotting(grid2) << endl;

    // Example 3
    vector<vector<int>> grid3 = {
        {2, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    cout << "Minimum time for all oranges to rot (Example 3): " << sol.orangesRotting(grid3) << endl;

    return 0;
}
