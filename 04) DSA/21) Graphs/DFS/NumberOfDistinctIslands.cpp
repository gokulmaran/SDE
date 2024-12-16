#include <iostream>
#include <vector>
#include <set>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis, vector<pair<int, int>>& vec, int r0, int c0) {
        // Boundary conditions and base cases
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] == 1 || grid[r][c] == 0) {
            return;
        }
        vis[r][c] = 1;
        vec.push_back({r - r0, c - c0}); // Normalize the position relative to the start of the island
        // Explore all 4 directions
        dfs(grid, r + 1, c, vis, vec, r0, c0);
        dfs(grid, r - 1, c, vis, vec, r0, c0);
        dfs(grid, r, c + 1, vis, vec, r0, c0);
        dfs(grid, r, c - 1, vis, vec, r0, c0);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> vec;
                    dfs(grid, i, j, vis, vec, i, j); // Start DFS from the current cell
                    st.insert(vec); // Insert the normalized shape of the island into the set
                }
            }
        }
        return st.size(); // Return the number of distinct islands
    }
};

// Main function
int main() {
    Solution sol;

    // Example grid configuration
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    int result = sol.countDistinctIslands(grid);
    cout << "Number of distinct islands: " << result << endl;

    return 0;
}
