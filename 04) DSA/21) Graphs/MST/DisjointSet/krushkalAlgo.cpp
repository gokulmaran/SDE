#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Union-Find functions
int find(int x, vector<int>& par) {
    if (x == par[x]) {
        return x;
    }
    return par[x] = find(par[x], par);
}

void Union(int x, int y, vector<int>& par, vector<int>& rank) {
    int par_x = find(x, par);
    int par_y = find(y, par);

    if (par_x == par_y) return;

    if (rank[par_x] > rank[par_y]) {
        par[par_y] = par_x;
    } else if (rank[par_x] < rank[par_y]) {
        par[par_x] = par_y;
    } else {
        par[par_x] = par_y;
        rank[par_y]++;
    }
}

// Function to find the weight of the Minimum Spanning Tree (MST)
int spanningTree(int V, vector<vector<int>> adj[]) {
    // Create a list of edges
    vector<vector<int>> vec;
    for (int i = 0; i < V; i++) {
        for (auto& it : adj[i]) {
            vec.push_back({it[1], i, it[0]}); // {weight, node1, node2}
        }
    }

    // Sort edges by weight
    sort(vec.begin(), vec.end());

    int ans = 0; // To store the total weight of the MST
    vector<int> par(V), rank(V, 0);

    // Initialize disjoint set
    for (int i = 0; i < V; i++) {
        par[i] = i;
    }

    // Kruskal's algorithm
    for (auto& it : vec) {
        int u = it[1];
        int v = it[2];
        int wt = it[0];

        int par_u = find(u, par);
        int par_v = find(v, par);

        // If u and v are not in the same set, add this edge to the MST
        if (par_u != par_v) {
            ans += wt;
            Union(u, v, par, rank);
        }
    }

    return ans; // Return the weight of the MST
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
