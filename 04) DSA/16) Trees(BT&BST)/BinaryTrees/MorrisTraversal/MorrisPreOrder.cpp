#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
//link: https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1
class Solution {
public:
    vector<int> preorder(TreeNode* root) {
        // Vector to store the preorder traversal result
        vector<int> preorder;
        // Pointer to the current node, starting with the root
        TreeNode* cur = root;

        /* 
        Iterate until the current node becomes null
        If the current node has no left child
        Add the value of the current node to the preorder list
        */
        while (cur != NULL) {
            if (cur->left == NULL) {
                preorder.push_back(cur->data);
                cur = cur->right;
            } 
        /* 
        If the current node has a left child create a pointer 
        to traverse to the rightmost node in the left subtree
        or until we find a node whose right child is not yet processed
        */     
            else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
        /* 
        If the right child of the rightmost node is null 
        set the right child of the rightmost node to the current node
        Add the value of the current node to the preorder list
        and move to the left child
        */        

                if (prev->right == NULL) {
                    prev->right = cur;
                    preorder.push_back(cur->data);
                    cur = cur->left;
                } 

        /* If the right child of the rightmost node is not null
        Reset the right child to null and move to the right child */ 

                else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        // Return the resulting preorder traversal list
        return preorder;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(2);

    Solution sol;
    vector<int> preorder = sol.preorder(root);

    cout << "Binary Tree Morris Preorder Traversal: ";
    for (int i : preorder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
