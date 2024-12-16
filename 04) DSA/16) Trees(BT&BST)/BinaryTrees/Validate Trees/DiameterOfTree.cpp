#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Solution class containing the diameter function
class Solution {
public:
    int ans = 0;

    int height(Node* node) {
        if (node == NULL) return 0;
        int left = height(node->left);
        int right = height(node->right);
        ans = max(ans, 1 + left + right);
        return 1 + max(left, right);
    }

    int diameter(Node* root) {
        height(root);
        return ans;
    }
};

// Function to delete the binary tree (clean up)
void deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Function to print the binary tree (inorder traversal)
void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;

    // Create Solution object and calculate diameter
    Solution solution;
    int diameter = solution.diameter(root);
    cout << "Diameter of the tree: " << diameter << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
