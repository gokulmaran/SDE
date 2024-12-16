#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Check if the preorder list is empty
        if (preorder.empty()) return nullptr;

        // The first element is the root
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);

        // Iterate through the rest of the elements
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = s.top();
            TreeNode* child = new TreeNode(preorder[i]);

            // Adjust the stack and place the node in the right position
            while (!s.empty() && s.top()->data < preorder[i]) {
                node = s.top();
                s.pop();
            }

            // Insert node as left or right child
            if (node->data < preorder[i]) {
                node->right = child;
            } else {
                node->left = child;
            }

            // Push the child node to the stack
            s.push(child);
        }

        return root;
    }
};

// Function to print the tree in-order for testing
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Solution solution;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = solution.bstFromPreorder(preorder);

    // Print the constructed BST
    inorderTraversal(root);

    return 0;
}
