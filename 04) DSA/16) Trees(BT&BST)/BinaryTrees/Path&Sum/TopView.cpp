#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Solution class containing the topView function
class Solution {
public:
    // Function to return a list of nodes visible from the top view
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int lvl = it.second;

            // Insert the node's data if its level is not already present in the map
            if (mp.find(lvl) == mp.end()) {
                mp[lvl] = node->data;
            }

            if (node->left != NULL) {
                q.push({node->left, lvl - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, lvl + 1});
            }
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// Function to delete the binary tree (clean up)
void deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Function to print the binary tree (inorder traversal)
void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Create Solution object and get the top view of the tree
    Solution solution;
    vector<int> topViewNodes = solution.topView(root);

    // Print the top view of the binary tree
    cout << "Top view of the binary tree: ";
    for (int val : topViewNodes) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
