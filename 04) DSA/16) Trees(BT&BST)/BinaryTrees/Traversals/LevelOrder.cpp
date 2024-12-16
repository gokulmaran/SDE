#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int l = q.size();
            vector<int> temp;
            for (int i = 0; i < l; i++) {
                TreeNode* t = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                temp.push_back(t->val);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Helper function to print the 2D vector
void printLevelOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create a binary tree
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of Solution
    Solution solution;

    // Get level-order traversal
    vector<vector<int>> result = solution.levelOrder(root);

    // Print the result
    cout << "Level-order traversal:" << endl;
    printLevelOrder(result);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
