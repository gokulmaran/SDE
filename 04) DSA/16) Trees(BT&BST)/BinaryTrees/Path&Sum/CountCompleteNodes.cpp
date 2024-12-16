#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/count-complete-tree-nodes/
// Solution class with countNodes function
class Solution {
public:
    int count=0;

    void helper(TreeNode* root) {
        if (root) {
            count++;
        }
        if (root->left) {
            helper(root->left);
        }
        if (root->right) {
            helper(root->right);
        }
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        helper(root);
        return count;
    }
};

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    // Construct the binary tree
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;

    // Create Solution object
    Solution sol;

    // Count the nodes in the binary tree
    int nodeCount = sol.countNodes(root);

    // Print the result
    cout << "Number of nodes in the binary tree: " << nodeCount << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
