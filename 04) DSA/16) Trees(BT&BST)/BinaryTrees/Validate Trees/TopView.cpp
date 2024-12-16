#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Function to find the top view of the binary tree
void TopView(Node* root, vector<int>& ans) {
    if (root == nullptr) return; // Handle empty tree

    map<int, int> m; // Maps horizontal distance to node data
    queue<pair<Node*, int>> q; // Queue to hold nodes and their horizontal distances
    q.push({root, 0}); // Start with root at horizontal distance 0
    
    while (!q.empty()) {
        Node* temp = q.front().first;
        int level = q.front().second;
        q.pop();

        // Add the node data to map if not already present
        if (m.find(level) == m.end()) {
            m[level] = temp->data;
        }
        
        // Push left and right children to the queue with updated horizontal distances
        if (temp->left) {
            q.push({temp->left, level - 1});
        }
        if (temp->right) {
            q.push({temp->right, level + 1});
        }
    }
    
    // Collect results from the map in order of their horizontal distances
    for (auto it : m) {
        ans.push_back(it.second);
    }
}

vector<int> topView(Node *root) {
    vector<int> ans;
    TopView(root, ans);
    return ans;
}

// Main function to test the topView function
int main() {
    // Creating a sample tree:
    //       1
    //     /   \
    //    2     3
    //   / \     \
    //  4   5     6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> result = topView(root);

    cout << "Top View of the Tree:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

