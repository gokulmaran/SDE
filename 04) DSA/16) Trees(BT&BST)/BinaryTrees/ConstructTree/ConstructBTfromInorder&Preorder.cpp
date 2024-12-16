#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Solution class with buildTree function
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, unordered_map<int, int>& m, int& index, int i, int j) {
        if (i > j) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index++]);

        int mid = m[root->val];

        root->left = construct(preorder, m, index, i, mid - 1);
        root->right = construct(preorder, m, index, mid + 1, j);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        int index = 0;
        return construct(preorder, m, index, 0, inorder.size() - 1);
    }
};

// Helper function to print tree in-order (for verification)
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Sample preorder and inorder vectors
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Create Solution object
    Solution sol;

    // Build the tree
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Print in-order traversal of the constructed tree
    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
