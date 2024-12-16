#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Solution class with boundary function
class Solution {
private:
    void leftNodes(Node *root, vector<int> &ans) {
        if (root->left == NULL && root->right == NULL)
            return;
        ans.push_back(root->data);
        if (root->left)
            leftNodes(root->left, ans);
        else
            leftNodes(root->right, ans);
    }

    void rightNodes(Node *root, vector<int> &ans) {
        if (root->left == NULL && root->right == NULL)
            return;
        if (root->right)
            rightNodes(root->right, ans);
        else
            rightNodes(root->left, ans);
        ans.push_back(root->data);
    }

    void leafNodes(Node *root, vector<int> &ans) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        if (root->left)
            leafNodes(root->left, ans);
        if (root->right)
            leafNodes(root->right, ans);
    }

public:
    vector<int> boundary(Node *root) {
        vector<int> ans;
        if (!root)
            return ans;
        ans.push_back(root->data);
        if (root->left)
            leftNodes(root->left, ans);
        if (root->left || root->right)
            leafNodes(root, ans);
        if (root->right)
            rightNodes(root->right, ans);
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

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    // Create Solution object and get the boundary of the tree
    Solution sol;
    vector<int> boundaryNodes = sol.boundary(root);

    // Print the boundary nodes of the binary tree
    cout << "Boundary of the binary tree: ";
    for (int val : boundaryNodes) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
