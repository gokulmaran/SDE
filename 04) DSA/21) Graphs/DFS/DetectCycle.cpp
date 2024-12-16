#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
public:
    bool detectCycle(int Node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[Node] = 1;
        for (int j = 0; j < adj[Node].size(); j++) {
            if (parent == adj[Node][j]) {
                continue;
            }
            if (visited[adj[Node][j]] == 1) {
                return true;
            }
            if (detectCycle(adj[Node][j], Node, adj, visited)) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && detectCycle(i, -1, adj, visited)) {
                return true;
            }
        }
        return false;
    }
};

// Main function
int main() {
    Solution sol;

    // Example test case
    int V = 5; // Number of vertices
    vector<int> adj[V];
    
    // Adding edges to the graph
    // Example graph:
    // 0 - 1 - 2
    // |   |
    // 3 - 4
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[1].push_back(4);
    adj[4].push_back(1);

    // Check if the graph contains a cycle
    bool hasCycle = sol.isCycle(V, adj);

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
