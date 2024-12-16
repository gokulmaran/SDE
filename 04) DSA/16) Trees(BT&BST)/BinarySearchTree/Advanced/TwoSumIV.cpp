#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Solution class with findTarget function
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        stack<TreeNode*> s1, s2;

        TreeNode* temp1 = root;
        TreeNode* temp2 = root;

        while (1) {
            while (temp1) {
                s1.push(temp1);
                temp1 = temp1->left;
            }
            while (temp2) {
                s2.push(temp2);
                temp2 = temp2->right;
            }
            if (s1.empty() || s2.empty()) break;

            temp1 = s1.top();
            temp2 = s2.top();

            if (temp1->val + temp2->val == k) {
                if (temp1 == temp2) return false;
                return true;
            } else if (temp1->val + temp2->val < k) {
                s1.pop();
                temp1 = temp1->right;
                temp2 = nullptr;
            } else {
                s2.pop();
                temp2 = temp2->left;
                temp1 = nullptr;
            }
        }
        return false;
    }
};

// Helper function to print the result
void printFindTargetResult(bool result) {
    if (result) {
        cout << "There are two numbers in the BST that add up to the target." << endl;
    } else {
        cout << "No two numbers in the BST add up to the target." << endl;
    }
}

// Main function to test the findTarget function
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // Create Solution object
    Solution sol;

    // Test findTarget with a target sum
    int target = 9;
    bool result = sol.findTarget(root, target);

    // Print the result
    printFindTargetResult(result);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
