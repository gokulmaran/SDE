#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Solution class with distanceK function
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> m; // To store parent pointers

    void dfs(TreeNode* root, TreeNode* parent) {
        if (!root)
            return;
        if (parent) {
            m[root] = parent; // Map the current node to its parent
        }
        dfs(root->left, root);  // Recur for left subtree
        dfs(root->right, root); // Recur for right subtree
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        set<TreeNode*> st;

        dfs(root, NULL); // Build the parent pointers map

        q.push(target);    // Start BFS from the target node
        st.insert(target); // Mark the target as visited

        int cnt = 0;     // Distance counter
        vector<int> res; // Result vector to store nodes at distance k

        while (!q.empty()) {
            int sz = q.size(); // Number of nodes at the current level
            if (cnt == k) {    // Check if current level is distance k
                while (sz--) {
                    res.push_back(q.front()->val); // Collect node values
                    q.pop();                       // Remove node from queue
                }
                break; // Exit the loop as we've collected all nodes at distance k
            }

            while (sz--) {
                auto node = q.front(); // Get the front node
                q.pop();               // Remove node from queue

                if (node->left && !st.count(node->left)) { // Check left child
                    q.push(node->left);    // Add left child to queue
                    st.insert(node->left); // Mark left child as visited
                }
                if (node->right && !st.count(node->right)) { // Check right child
                    q.push(node->right);      // Add right child to queue
                    st.insert(node->right);   // Mark right child as visited
                }
                if (m.count(node) && !st.count(m[node])) { // Check parent
                    q.push(m[node]);    // Add parent to queue
                    st.insert(m[node]); // Mark parent as visited
                }
            }

            cnt++; // Move to the next level
        }

        return res; // Return the result vector
    }
};

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // Construct the binary tree
    root->left = node5;
    root->right = node1;
    node5->left = node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;

    // Create Solution object
    Solution sol;

    // Example: Find all nodes at distance 2 from node 5
    vector<int> result = sol.distanceK(root, node5, 2);

    // Print the result
    cout << "Nodes at distance 2 from node 5: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the tree
    // (Implement a function to delete the tree if needed)

    return 0;
}
