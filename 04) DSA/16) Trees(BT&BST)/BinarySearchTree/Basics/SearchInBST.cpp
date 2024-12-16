#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Solution class containing the searchBST method
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

// Helper function to print the result node
void printNode(TreeNode* node) {
    if (node) {
        cout << "Node found: " << node->val << endl;
    } else {
        cout << "Node not found." << endl;
    }
}

int main() {
    // Create sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Create Solution object
    Solution solution;

    // Search for a value in the BST
    int searchValue = 3;
    TreeNode* result = solution.searchBST(root, searchValue);
    
    // Print the result
    printNode(result);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
