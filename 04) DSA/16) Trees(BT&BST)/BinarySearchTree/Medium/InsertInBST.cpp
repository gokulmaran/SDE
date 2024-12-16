#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Function to insert a value into a BST
TreeNode* insertIntoBST(TreeNode* node, int val) {
    if (!node) {
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }
    if (val < node->val) {
        node->left = insertIntoBST(node->left, val);
    } else {
        node->right = insertIntoBST(node->right, val);
    }
    return node;
}

// Helper function to print the BST in order (left-root-right)
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the insertIntoBST function
int main() {
    // Create an initial BST
    TreeNode* root = nullptr;

    // Insert values into the BST
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 15);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 12);
    root = insertIntoBST(root, 18);

    // Print the BST in order to verify the insertion
    cout << "In-order traversal of the BST: ";
    printInOrder(root);
    cout << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
