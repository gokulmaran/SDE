#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//Link: https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
    unordered_map<int, vector<int>> adj; // Adjacency list

    void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& bridges) {
        static int time = 0; // Timestamp
        disc[u] = low[u] = time;
        time += 1;

        for (int v : adj[u]) {
            if (disc[v] == -1) { // If v is not visited
                parent[v] = u;
                DFS(v, disc, low, parent, bridges);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    bridges.push_back(vector<int>({u, v}));
                }
            } else if (v != parent[u]) { // Check for back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridges_Tarjan(int V, vector<vector<int>>& bridges) {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        // Apply DFS for each component
        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                DFS(i, disc, low, parent, bridges);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (const auto& conn : connections) { // Make adjacency list
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<vector<int>> bridges; // Store all the bridges as pairs
        findBridges_Tarjan(n, bridges); // Apply Tarjan's algorithm
        return bridges;
    }
};

int main() {
    // Create an instance of Solution
    Solution sol;

    // Define number of nodes and connections
    int n = 5; // Number of nodes
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    // Find critical connections
    vector<vector<int>> result = sol.criticalConnections(n, connections);

    // Print the result
    cout << "Critical Connections:" << endl;
    for (const auto& bridge : result) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]" << endl;
    }

    return 0;
}
