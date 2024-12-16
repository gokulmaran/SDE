#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Find indegree
        int indegree[V] = {0};
        for(int u = 0; u < V; u++) {
            for(auto &v : adj[u]) {
                indegree[v]++;
            }
        }
        
        // Insert to queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Queue traversal BFS
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto &it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main() {
    Solution sol;
    
    // Number of vertices
    int V = 6;
    
    // Adjacency list representation of the graph
    vector<int> adj[V];
    
    // Adding edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    // Get topological sort
    vector<int> topo = sol.topoSort(V, adj);
    
    // Print the topological order
    cout << "Topological Sort: ";
    for(int node : topo) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
