#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Solution class with verticalTraversal function
class Solution {
public:
    void traverse(TreeNode* node, int x, int y, map<int, multiset<pair<int, int>>>& mp) {
        if (!node) return;
        mp[x].insert({y, node->val});
        traverse(node->left, x - 1, y + 1, mp);
        traverse(node->right, x + 1, y + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> m;
        traverse(root, 0, 0, m);
        vector<vector<int>> res;
        for (auto& [x, st] : m) {
            res.push_back({});
            for (auto& [y, val] : st) {
                res.back().push_back(val);
            }
        }
        return res;
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
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create Solution object and get the vertical order traversal of the tree
    Solution sol;
    vector<vector<int>> verticalOrder = sol.verticalTraversal(root);

    // Print the vertical order traversal of the binary tree
    cout << "Vertical order traversal of the binary tree:" << endl;
    for (const auto& column : verticalOrder) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up the tree
    deleteTree(root);

    return 0;
}
