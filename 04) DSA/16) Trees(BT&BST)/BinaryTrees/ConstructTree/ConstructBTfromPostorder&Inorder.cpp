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
//Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Solution class with buildTree function
class Solution {
public:
    TreeNode* solver(vector<int>& postorder, vector<int>& inorder, int size, int& postIndex, int start, int end, unordered_map<int, int>& m) {
        if (postIndex < 0 || start > end) {
            return NULL;
        }

        int ele = postorder[postIndex];
        postIndex--;
        int pos = m[ele];
        TreeNode* root = new TreeNode(ele);
        root->right = solver(postorder, inorder, size, postIndex, pos + 1, end, m);
        root->left = solver(postorder, inorder, size, postIndex, start, pos - 1, m);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int postIndex = size - 1;
        int start = 0;
        int end = size - 1;
        unordered_map<int, int> m;
        for (int i = 0; i < size; i++) {
            m[inorder[i]] = i;
        }
        return solver(postorder, inorder, size, postIndex, start, end, m);
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
    // Sample inorder and postorder vectors
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Create Solution object
    Solution sol;

    // Build the tree
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print in-order traversal of the constructed tree
    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
