#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/recover-binary-search-tree/
// Solution class with recoverTree function
class Solution {
public:
    void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, prev, first, end);
        if (prev != NULL) {
            if (root->val < prev->val) {
                if (first == NULL) {
                    first = prev;
                }
                end = root;
            }
        }
        prev = root;
        inorder(root->right, prev, first, end);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* end = nullptr;
        inorder(root, prev, first, end);
        if (first && end) {
            swap(first->val, end->val);
        }
    }
};

// Helper function to print the inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function to test the recoverTree function
int main() {
    // Create a sample BST with swapped nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2); // Swapped node

    cout << "Original BST (inorder): ";
    printInorder(root);
    cout << endl;

    // Create Solution object
    Solution sol;

    // Recover the BST
    sol.recoverTree(root);

    cout << "Recovered BST (inorder): ";
    printInorder(root);
    cout << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
