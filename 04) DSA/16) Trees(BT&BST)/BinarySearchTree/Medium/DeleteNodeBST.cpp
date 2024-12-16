#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/delete-node-in-a-bst/
// Function to find the minimum value node in the right subtree
int findminfromright(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->val;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->right == nullptr) {
            return root->left;
        }
        else if (root->left == nullptr) {
            return root->right;
        }
        else {
            root->val = findminfromright(root->right);
            root->right = deleteNode(root->right, root->val);
        }
    }
    return root;
}

// Helper function to print the BST in order (left-root-right)
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the deleteNode function
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    cout << "Original BST (in-order): ";
    printInOrder(root);
    cout << endl;

    // Delete a node with a specific key
    int keyToDelete = 50;
    root = deleteNode(root, keyToDelete);

    cout << "BST after deleting " << keyToDelete << " (in-order): ";
    printInOrder(root);
    cout << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
