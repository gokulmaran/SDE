#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Solution class with lowestCommonAncestor function
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val > p->val) && (root->val > q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if((root->val < p->val) && (root->val < q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

// Helper function to print the result
void printLCA(TreeNode* lca) {
    if (lca) {
        cout << "LCA Value: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }
}

// Main function to test the lowestCommonAncestor function
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Nodes to find the LCA
    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->left->right->right; // Node with value 5

    // Create Solution object
    Solution sol;

    // Find the LCA of nodes p and q
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    // Print the result
    printLCA(lca);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
