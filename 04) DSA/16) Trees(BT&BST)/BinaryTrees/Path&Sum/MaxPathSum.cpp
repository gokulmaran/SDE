#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Solution class with maxPathSum function
class Solution {
public:
    int maxSum(TreeNode* root, int &ans) {
        if (root == NULL) {
            return 0;
        }

        int leftBS = max(0, maxSum(root->left, ans));
        int rightBS = max(0, maxSum(root->right, ans));

        ans = max(ans, root->val + leftBS + rightBS);

        return root->val + max(leftBS, rightBS);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root, ans);
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

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    // Create Solution object and get the maximum path sum of the tree
    Solution sol;
    int maxPathSum = sol.maxPathSum(root);

    // Print the maximum path sum of the binary tree
    cout << "Maximum path sum of the binary tree: " << maxPathSum << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
