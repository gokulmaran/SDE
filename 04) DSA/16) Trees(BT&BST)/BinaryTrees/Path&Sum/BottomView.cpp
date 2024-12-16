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
//link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Solution class containing the bottomView function
class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        map<int, int> m; // To store the last node at each horizontal distance
        queue<pair<Node*, int>> q; // Queue to perform level order traversal
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            m[line] = node->data; // Update the map with the latest node at this distance
            
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Extract the bottom view from the map
        for (auto it : m) {
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
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    // Create Solution object and get the bottom view of the tree
    Solution solution;
    vector<int> bottomViewNodes = solution.bottomView(root);

    // Print the bottom view of the binary tree
    cout << "Bottom view of the binary tree: ";
    for (int val : bottomViewNodes) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
