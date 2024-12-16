#include <iostream>
#include <algorithm>
#include <cstdlib> // For abs function
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link:https://leetcode.com/problems/balanced-binary-tree/
// Solution class containing the isBalanced function
class Solution {
public:
    bool ans;

    int checkbalance(TreeNode* root) {
        if (!root) return 0;
        if (!ans) return 0;

        int leftsubtree = checkbalance(root->left);
        int rightsubtree = checkbalance(root->right);

        if (abs(leftsubtree - rightsubtree) > 1) {
            ans = false;
        }
        return 1 + max(leftsubtree, rightsubtree);
    }

    bool isBalanced(TreeNode* root) {
        ans = true;
        checkbalance(root);
        return ans;
    }
};

// Function to delete the binary tree (clean up)
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Function to print the binary tree (inorder traversal)
void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7); // This makes the tree unbalanced

    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;

    // Create Solution object and check if the tree is balanced
    Solution solution;
    bool balanced = solution.isBalanced(root);
    cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
