#include <bits/stdc++.h>
using namespace std;
//Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Solution class definition
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize the adjacency list
        vector<pair<int, int>> adj[n];
        int m = flights.size();
        for (int i = 0; i < m; i++) {
            int p = flights[i][0];
            int q = flights[i][1];
            adj[p].push_back({q, flights[i][2]});
        }

        // Initialize the queue, visited array, and distance array
        queue<pair<int, int>> q;
        vector<bool> vis(n, 0);
        q.push({0, src});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        k += 1; // Increment k to account for the starting node

        // Perform BFS-like traversal with distance updates
        while (!q.empty()) {
            int size = q.size();
            k--;
            if (k < 0) {
                break;
            }
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                int node = p.second;
                int wt = p.first;
                q.pop();
                for (auto x : adj[node]) {
                    if (x.second + wt < dist[x.first]) {
                        dist[x.first] = x.second + wt;
                        q.push({dist[x.first], x.first});
                    }
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// Main function for testing
int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n, m; 
        cin >> n >> m; // Read number of nodes and edges

        vector<vector<int>> flights(m, vector<int>(3));
        for (int i = 0; i < m; ++i) {
            cin >> flights[i][0] >> flights[i][1] >> flights[i][2]; // Read each edge
        }

        int src, dst, k;
        cin >> src >> dst >> k; // Read source, destination, and maximum number of stops

        Solution obj;
        int result = obj.findCheapestPrice(n, flights, src, dst, k);
        cout << result << "\n"; // Print the result for the current test case
    }
    return 0;
}
