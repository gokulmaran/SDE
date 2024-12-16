#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Solution class with kthSmallest function
class Solution {
public:
    void solve(TreeNode* root, int& cnt, int& ans, int k) {
        if (root == NULL) return;

        solve(root->left, cnt, ans, k);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        solve(root->right, cnt, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = 0;
        solve(root, cnt, ans, k);
        return ans;
    }
};

// Helper function to print the BST in order (left-root-right)
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the kthSmallest function
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    // Print BST in order
    cout << "BST (in-order): ";
    printInOrder(root);
    cout << endl;

    // Create Solution object
    Solution sol;

    // Test kthSmallest function
    int k = 3;
    int result = sol.kthSmallest(root, k);

    // Print the result
    cout << "The " << k << "-th smallest element is: " << result << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
