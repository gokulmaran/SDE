#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& colors) {
        for (auto it : adj[node]) {
            if (colors[it] == -1) {
                colors[it] = !colors[node];
                if (dfs(it, adj, colors) == false) return false;
            } else if (colors[it] == colors[node]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                colors[i] = 0;
                if (dfs(i, graph, colors) == false) return false;
            }
        }
        return true;
    }
};

// Main function
int main() {
    Solution sol;

    // Example graph: adjacency list representation
    vector<vector<int>> graph = {
        {1, 2, 3}, // Node 0 is connected to nodes 1, 2, 3
        {0, 2},    // Node 1 is connected to nodes 0, 2
        {0, 1, 3}, // Node 2 is connected to nodes 0, 1, 3
        {0, 2}     // Node 3 is connected to nodes 0, 2
    };

    // Check if the graph is bipartite
    bool result = sol.isBipartite(graph);
    cout << "The graph is " << (result ? "bipartite" : "not bipartite") << "." << endl;

    return 0;
}
