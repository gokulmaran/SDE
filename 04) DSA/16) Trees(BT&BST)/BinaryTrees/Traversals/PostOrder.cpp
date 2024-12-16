#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution {
public:
    void postorder(TreeNode* node, vector<int>& res) {
        if (!node) {
            return;
        }
        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

// Helper function to print the vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Create a binary tree
    //     1
    //    / \
    //   2   3
    //  /
    // 4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // Create an instance of Solution
    Solution solution;

    // Get post-order traversal
    vector<int> result = solution.postorderTraversal(root);

    // Print the result
    cout << "Post-order traversal: ";
    printVector(result);

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
