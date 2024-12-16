#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Function to perform preorder traversal
void preorder(TreeNode* node, vector<int>& result) {
    if (node == NULL) {
        return;
    }
    result.push_back(node->val);
    preorder(node->left, result);
    preorder(node->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}

// Main function to test the preorderTraversal function
int main() {
    // Creating a sample tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

