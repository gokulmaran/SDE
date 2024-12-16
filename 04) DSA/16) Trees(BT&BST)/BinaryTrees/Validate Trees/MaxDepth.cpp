#include <iostream>
#include <algorithm> // For std::max

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Function to calculate the maximum depth of a binary tree.
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int maxleft = maxDepth(root->left);
    int maxright = maxDepth(root->right);
    return max(maxleft, maxright) + 1;
}

// Main function to test the maxDepth function.
int main() {
    // Constructing the binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    // Create nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Calculate the maximum depth
    int depth = maxDepth(root);

    // Output the result
    cout << "The maximum depth of the binary tree is: " << depth << endl;

    // Clean up dynamically allocated memory
    // (In a real program, you should also delete the nodes to avoid memory leaks)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

