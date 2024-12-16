#include <iostream>
#include <vector>

using namespace std;

//Link:https://www.geeksforgeeks.org/problems/articulation-point-1/1
// The Solution class provided by the user
class Solution {
  public:
   vector<int> tin, vis, low, mark;
   int timer = 0;

   // Function to perform DFS and find articulation points
   void findArticularPoint(int node, int parent, vector<int> adj[]) {
        tin[node] = low[node] = timer;
        timer++;
        vis[node] = 1;

        int child = 0;
        for(auto it : adj[node]) {
            if(it == parent) continue; // Skip the edge back to parent
            if(!vis[it]) {
                findArticularPoint(it, node, adj); // Recursively visit child
                low[node] = min(low[node], low[it]);

                // If the lowest reachable vertex from child is not above the current node
                if(low[it] >= tin[node] && parent != -1) 
                    mark[node] = 1;

                child++;
            } else {
                // Update low value based on the back edge
                low[node] = min(tin[it], low[node]);
            }
        }
        // Special case for root node
        if(child > 1 && parent == -1) mark[node] = 1;
    }

    // Main function to find articulation points
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        tin.resize(V);
        vis.resize(V, 0);
        low.resize(V);
        mark.resize(V, 0);

        // Start DFS from the first node
        findArticularPoint(0, -1, adj);
        
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i] == 1) ans.push_back(i); // Collect all articulation points
        }
        if(ans.size() == 0) return {-1}; // Return -1 if no articulation points found
        return ans;
    }
};

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Initialize adjacency list representation of the graph
    vector<int> adj[V];
    
    // Example edges (Bidirectional)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    // Create an instance of Solution
    Solution sol;

    // Find articulation points in the graph
    vector<int> articulationPoints = sol.articulationPoints(V, adj);

    // Output the articulation points
    cout << "Articulation points in the graph are: ";
    for(int point : articulationPoints) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
