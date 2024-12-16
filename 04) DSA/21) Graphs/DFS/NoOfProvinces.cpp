#include <iostream>
#include <vector>

using namespace std;

//Link: https://leetcode.com/problems/number-of-provinces/

// Solution class definition
class Solution {
public:
    void dfs(vector<int>& vis, vector<int> ad[], int i) {
        vis[i] = 1;
        for (auto k : ad[i]) {
            if (!vis[k]) {
                dfs(vis, ad, k);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& g) {
        // Convert adjacency matrix to adjacency list
        int n = g.size();
        vector<int> ad[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }

        // Call DFS to find connected components
        int c = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c++;
                dfs(vis, ad, i);
            }
        }
        return c;
    }
};

// Main function
int main() {
    Solution sol;
    // Example test case
    vector<vector<int>> graph = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int result = sol.findCircleNum(graph);
    cout << "Number of provinces: " << result << endl; // Output should be 2

    return 0;
}
