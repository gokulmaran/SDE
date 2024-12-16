#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/burning-tree/1
// Solution class with minTime function
class Solution {
  public:
    void createGraph(Node* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;

        if (root->left) {
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
            createGraph(root->left, adj);
        }
        if (root->right) {
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
            createGraph(root->right, adj);
        }
    }

    int minTime(Node* root, int target) {
        unordered_map<int, vector<int>> adj;
        createGraph(root, adj);

        queue<pair<int, int>> q;
        unordered_set<int> vis;

        q.push({target, 0});
        vis.insert(target);

        int ans = 0;
        while (!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            for (auto it : adj[node]) {
                if (vis.find(it) == vis.end()) {
                    q.push({it, time + 1});
                    vis.insert(it);
                }
            }
        }
        return ans;
    }
};

int main() {
    // Create nodes
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    // Construct the binary tree
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    // Create Solution object
    Solution sol;

    // Call minTime function and print the result
    int target = 5; // Example target node
    int result = sol.minTime(root, target);
    cout << "Minimum time to burn the tree from node " << target << " is: " << result << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
