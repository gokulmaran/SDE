#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF INT_MAX
//Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Define the spanningTree function
int spanningTree(int V, vector<vector<int>> adj[]) {
    // Initialize visited vector to keep track of visited nodes
    vector<bool> vis(V, false);
    
    // Initialize priority queue for Prim's algorithm
    // The priority queue stores pairs of (weight, (node, parent))
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;
    
    // Start with node 0 (or any node as the starting point) with weight 0
    pq.push({0, {0, -1}});
    
    int ans = 0; // To store the total weight of the Minimum Spanning Tree (MST)
    
    while (!pq.empty()) {
        // Get the node with the minimum weight edge
        auto it = pq.top();
        pq.pop();
        
        int wt = it.first; // Weight of the edge
        int node = it.second.first; // Current node
        int parent = it.second.second; // Parent node (not used in this version)
        
        // If the node is already visited, skip it
        if (vis[node]) continue;
        
        // Mark the node as visited and add the weight to the MST weight
        vis[node] = true;
        ans += wt;
        
        // Traverse all adjacent nodes of the current node
        for (auto &it : adj[node]) {
            int adjN = it[0]; // Adjacent node
            int adjW = it[1]; // Weight of the edge to the adjacent node
            // If the adjacent node is not visited, add it to the priority queue
            if (!vis[adjN]) {
                pq.push({adjW, {adjN, node}});
            }
        }
    }
    
    return ans; // Return the total weight of the MST
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Create adjacency list for the graph
    vector<vector<int>> adj[V];

    // Add edges to the graph
    // Each edge is represented as {destination, weight}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});
    
    // Call the spanningTree function to compute the MST
    int result = spanningTree(V, adj);

    // Print the result: total weight of the MST
    cout << "The weight of the Minimum Spanning Tree is: " << result << endl;

    return 0;
}
