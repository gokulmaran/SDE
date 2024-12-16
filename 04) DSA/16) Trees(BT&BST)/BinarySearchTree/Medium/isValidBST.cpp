#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/validate-binary-search-tree/
// Solution class with isValidBST function
class Solution {
public:
    bool fun(TreeNode* root, TreeNode* max, TreeNode* min) {
        if (root == NULL) {
            return true;
        }
        if ((min == NULL || root->val > min->val) && (max == NULL || root->val < max->val)) {
            return fun(root->left, root, min) && fun(root->right, max, root);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return fun(root, NULL, NULL);
    }
};

// Helper function to print the BST in order (left-root-right)
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the isValidBST function
int main() {
    // Create a sample valid BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    // Create an invalid BST
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    // Create Solution object
    Solution sol;

    // Test isValidBST function
    bool result1 = sol.isValidBST(root1);
    bool result2 = sol.isValidBST(root2);

    // Print the results
    cout << "Tree 1 is a valid BST: " << (result1 ? "Yes" : "No") << endl;
    cout << "Tree 2 is a valid BST: " << (result2 ? "Yes" : "No") << endl;

    // Clean up the trees (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
