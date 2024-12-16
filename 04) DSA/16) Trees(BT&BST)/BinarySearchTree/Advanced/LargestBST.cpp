#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/largest-bst/1
// Solution class with largestBst function
class Solution {
public:
    int countNodes(Node* node) {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool isBST(Node* node, int min, int max) {
        if (node == NULL) return true;
        if (node->data < min || node->data > max) return false;
        return isBST(node->left, min, node->data - 1) && isBST(node->right, node->data + 1, max);
    }

    int largestBst(Node* root) {
        if (isBST(root, INT_MIN, INT_MAX)) {
            return countNodes(root);
        }
        int left = largestBst(root->left);
        int right = largestBst(root->right);
        return max(left, right);
    }
};

// Helper function to print the result
void printLargestBst(Node* root) {
    Solution sol;
    int result = sol.largestBst(root);
    cout << "Size of the largest BST in the given tree: " << result << endl;
}

// Main function to test the largestBst function
int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7); // Non-BST subtree

    // Test the largestBst function
    printLargestBst(root);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
