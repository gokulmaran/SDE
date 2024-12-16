//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
//Link:https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Initialization
        vector<int> ans(N, INT_MAX);  // Initialize distances to all nodes as INT_MAX (infinity)
        vector<int> adj[N];           // Adjacency list representation of the graph
        
        ans[src] = 0;  // Distance from source to itself is 0

        // Build the adjacency list from the edges
        for(int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);  // Since the graph is undirected
        }

        // Priority queue for Dijkstra's algorithm
        // Stores pairs of (distance from source, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});  // Push the source node with distance 0

        // Process the priority queue
        while(!pq.empty()) {
            auto f = pq.top();  // Get the node with the smallest distance
            int dist = f.first;  // Current distance to this node
            int node = f.second; // Current node
            pq.pop();
            
            // Traverse the adjacency list of the current node
            for(auto x : adj[node]) {
                int d = 1;  // Since each edge has a weight of 1
                int adjNode = x;  // Adjacent node

                // Check if the distance through the current node is shorter
                if(d + dist < ans[adjNode]) {
                    ans[adjNode] = d + dist;  // Update the shortest distance
                    pq.push({d + dist, adjNode});  // Push the new distance and node into the priority queue
                }
            }
        }

        // Replace all unreachable nodes with -1
        for(int i = 0; i < N; i++) {
            if(ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n, m; 
        cin >> n >> m;  // Number of nodes (n) and edges (m)
        
        vector<vector<int>> edges;
        
        // Read the edges
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j = 0; j < 2; ++j) {
                int x; 
                cin >> x;  // Read each node of the edge
                temp.push_back(x);
            }
            edges.push_back(temp);  // Add the edge to the edges list
        }

        int src; 
        cin >> src;  // Source node
        
        Solution obj;  // Create an object of the Solution class

        vector<int> res = obj.shortestPath(edges, n, m, src);  // Call the shortestPath function

        // Print the result
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
// } Driver Code Ends
