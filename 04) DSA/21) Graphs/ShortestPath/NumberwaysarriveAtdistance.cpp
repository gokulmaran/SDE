#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
//LinK: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
// Solution class definition
class Solution {
public:
    int MOD = 1e9 + 7; // Modulo value to avoid overflow

    // Function to count the number of paths from node 0 to node n-1
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n); // Adjacency list for graph representation

        // Build the graph from the road information
        for(auto &road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time}); // Add edge u -> v
            graph[v].push_back({u, time}); // Add edge v -> u (undirected graph)
        }

        // Call Dijkstra's algorithm to find the number of shortest paths
        return dijkstra(graph, n, 0);
    }

    // Function to perform Dijkstra's algorithm to find the number of shortest paths
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LLONG_MAX); // Distance array initialized to infinity
        vector<ll> ways(n, 0); // Array to store the number of shortest paths to each node

        ways[src] = 1; // There is exactly one way to reach the source node: starting from it
        dist[src] = 0; // Distance to the source node is 0

        // Min-heap priority queue to process nodes by shortest distance
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, src}); // Push the source node into the priority queue with distance 0

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top(); // Extract the node with the smallest distance
            minHeap.pop();

            // Skip this node if its distance is not up-to-date
            if (d > dist[u]) continue;

            // Explore all adjacent nodes
            for (auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    // Found a shorter path to node v
                    dist[v] = d + time;
                    ways[v] = ways[u]; // Update the number of ways to reach node v
                    minHeap.push({dist[v], v}); // Add node v to the priority queue
                } else if (dist[v] == d + time) {
                    // Found another shortest path to node v
                    ways[v] = (ways[v] + ways[u]) % MOD; // Update the number of ways modulo MOD
                }
            }
        }

        // Return the number of ways to reach node n-1
        return ways[n-1];
    }
};

// Main function to drive the code
int main() {
    int n; // Number of nodes
    int m; // Number of edges
    cin >> n >> m; // Read the number of nodes and edges

    vector<vector<int>> roads(m, vector<int>(3)); // To store edge information
    for (int i = 0; i < m; ++i) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2]; // Read each edge
    }

    Solution obj; // Create Solution object
    cout << obj.countPaths(n, roads) << endl; // Compute and output the number of shortest paths

    return 0;
}
