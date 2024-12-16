#include <bits/stdc++.h>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Bellman-Ford function definition
vector<int> bellman_ford(int v, vector<vector<int>>& edges, int S) {
    vector<int> dis(v, 1e8); // Initialize distances with a large value
    dis[S] = 0; // Distance to the source is 0

    // Relax all edges (v-1) times
    for (int i = 0; i < v - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                dis[v] = dis[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
            return {-1}; // Negative weight cycle detected
        }
    }
    return dis;
}

// Main function to test the Bellman-Ford function
int main() {
    int v, e, S;
    cin >> v >> e; // Read number of vertices and edges
    vector<vector<int>> edges(e, vector<int>(3)); // Initialize edges

    // Read edges
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cin >> S; // Read source vertex

    // Compute shortest distances using Bellman-Ford
    vector<int> distances = bellman_ford(v, edges, S);

    // Print the result
    if (distances.size() == 1 && distances[0] == -1) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        for (int dist : distances) {
            if (dist == 1e8) {
                cout << "INF "; // Print INF for unreachable vertices
            } else {
                cout << dist << " "; // Print distance
            }
        }
        cout << endl;
    }

    return 0;
}
