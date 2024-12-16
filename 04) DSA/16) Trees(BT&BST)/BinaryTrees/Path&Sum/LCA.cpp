#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Solution class with lowestCommonAncestor function
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};

// Function to delete the binary tree (clean up)
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // Construct the binary tree
    root->left = node5;
    root->right = node1;
    node5->left = node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;

    // Create Solution object
    Solution sol;

    // Example: Find the LCA of nodes 5 and 1
    TreeNode* lca = sol.lowestCommonAncestor(root, node5, node1);
    cout << "Lowest Common Ancestor of 5 and 1: " << (lca ? lca->val : -1) << endl;

    // Example: Find the LCA of nodes 5 and 4
    lca = sol.lowestCommonAncestor(root, node5, node4);
    cout << "Lowest Common Ancestor of 5 and 4: " << (lca ? lca->val : -1) << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
