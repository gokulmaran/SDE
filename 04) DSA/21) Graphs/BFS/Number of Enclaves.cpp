#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Link: https://leetcode.com/problems/number-of-enclaves/description/
// Function to calculate the number of enclaves
int numEnclaves(vector<vector<int>>& grid) {
    int cnt = 0, m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    // Put all the boundaries in queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    // Check any 1s connected to boundary 1's with the help of the visited array
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    // Calculate not boundary ones
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                ++cnt;
            }
        }
    }

    return cnt;
}

int main() {
    // Define a test case
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // Compute the number of enclaves
    int result = numEnclaves(grid);

    // Print the result
    cout << "Number of enclaves: " << result << endl;

    return 0;
}
