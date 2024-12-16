#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
//Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
class Solution {
    int fi(int i, vector<int>& par) {
        if (i == par[i]) return i;
        return par[i] = fi(par[i], par);
    }
    
    void dsu(int u, int v, vector<int>& par, vector<int>& siz) {
        u = fi(u, par);
        v = fi(v, par);
        if (u == v) return;
        if (siz[v] > siz[u]) {
            swap(u, v);
        }
        par[v] = u;
        siz[u] += siz[v];
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Check if there are enough connections to connect all nodes
        if (connections.size() < n - 1) {
            return -1;
        }

        unordered_set<int> ans;
        vector<int> par(n), siz(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        // Apply Union-Find to process connections
        for (auto& conn : connections) {
            dsu(conn[0], conn[1], par, siz);
        }

        // Count the number of connected components
        for (int i = 0; i < n; i++) {
            ans.insert(fi(i, par));
        }

        // Return the number of additional connections needed to connect all components
        return ans.size() - 1;
    }
};

int main() {
    Solution solution;
    
    // Number of nodes
    int n = 6;

    // List of connections where each connection is represented as {u, v}
    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    // Call the makeConnected function to get the number of operations needed
    int result = solution.makeConnected(n, connections);

    // Print the result
    if (result == -1) {
        cout << "Not enough connections to connect all nodes." << endl;
    } else {
        cout << "Minimum number of operations required to connect all nodes: " << result << endl;
    }

    return 0;
}
