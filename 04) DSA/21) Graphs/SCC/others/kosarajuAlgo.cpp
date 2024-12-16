#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution {
public:
    void DFS(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                DFS(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    
    void DFS2(int node, vector<int> adj[], vector<bool> &vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                DFS2(it, adj, vis);
            }
        }
    }
    
    int kosaraju(int n, vector<vector<int>>& adj) {
        // Step 1: Store the sorted nodes in a stack
        vector<bool> vis(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                DFS(i, adj, vis, st);
            }
        }
        
        // Step 2: Reverse the edges of the graph
        vector<int> adjT[n];
        for(int i = 0; i < n; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }
        
        // Step 3: Do DFS and count connected components
        int cnt = 0;
        while(!st.empty()) {
            int i = st.top(); st.pop();
            if(!vis[i]) {
                DFS2(i, adjT, vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};

int main() {
    // Create an instance of Solution
    Solution sol;

    // Define test case: number of nodes
    int n = 5;

    // Define adjacency list for the graph
    vector<vector<int>> adj = {
        {1, 2},  // Edges from node 0
        {0, 2},  // Edges from node 1
        {3},     // Edges from node 2
        {4},     // Edges from node 3
        {}       // Edges from node 4
    };

    // Call kosaraju function to find the number of strongly connected components
    int result = sol.kosaraju(n, adj);

    // Print the result
    cout << "Number of Strongly Connected Components: " << result << endl;

    return 0;
}
