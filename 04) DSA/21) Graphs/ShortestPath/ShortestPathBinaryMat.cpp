#include <bits/stdc++.h>
using namespace std;
//Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Special condition: Check if the start or end cell is blocked
        if(grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0; // Starting cell distance is 0
        q.push({0, {0, 0}}); // Enqueue starting cell with distance 0

        int delrow[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // Directions for 8 possible moves
        int delcol[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // Directions for 8 possible moves

        while(!q.empty()) {
            auto m = q.front();
            q.pop();
            int dis = m.first; // Current distance
            int row = m.second.first; // Current row
            int col = m.second.second; // Current column
            
            // Explore all 8 directions
            for(int i = 0; i < 8; i++) {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                
                // Check if the new position is within bounds and not blocked
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < n
                   && grid[newrow][newcol] == 0 && dis + 1 < dist[newrow][newcol]) {
                    dist[newrow][newcol] = dis + 1; // Update distance
                    q.push({dis + 1, {newrow, newcol}}); // Enqueue new position
                    if(newrow == n - 1 && newcol == n - 1) return dis + 1 + 1; // Return distance if reached the end
                }
            }
        }
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1] + 1; // Return result
    }
};

// Driver Code
int main() {
    int n;
    cin >> n; // Read the size of the grid
    
    vector<vector<int>> grid(n, vector<int>(n));
    
    // Read the grid
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    Solution obj;
    int result = obj.shortestPathBinaryMatrix(grid);
    
    cout << result << endl; // Output the result
    
    return 0;
}
