#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
//link:https://leetcode.com/problems/binary-search-tree-iterator/description/

// Class for BST Iterator
class BSTIterator {
public:
    // Constructor to initialize the iterator
    BSTIterator(TreeNode* root) {
        // Perform inorder traversal and store values
        inorderTraversal(root);
        // Initialize index to -1 (before first element)
        index = -1;
    }
    
    // Check if there are more elements in the BST
    bool hasNext() {
        // True if there are more elements
        return index + 1 < values.size();
    }
    
    // Return the next element in the BST
    int next() {
        // Increment index and return the next value
        return values[++index];
    }

private:
    // Vector to store inorder traversal values
    vector<int> values;
    // Index to track the current position
    int index;

    // Helper function to perform inorder traversal
    void inorderTraversal(TreeNode* node) {
        // Base case: if node is null, return
        if (node == nullptr) return;
        // Recur on the left subtree
        inorderTraversal(node->left);
        // Add the current node's value to the vector
        values.push_back(node->data);
        // Recur on the right subtree
        inorderTraversal(node->right);
    }
};

// Main method to demonstrate the usage of BSTIterator
int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Instantiate the BSTIterator with the root of the tree
    BSTIterator* iterator = new BSTIterator(root);

    // Use the iterator to get the elements in sorted order
    while (iterator->hasNext()) {
        cout << iterator->next() << " ";
    }

    // Output: 3 7 9 15 20

    return 0;
}
