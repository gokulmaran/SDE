#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Function to get the left view of the binary tree
void rec(Node* root, int level, vector<int>& v) {
    if (root == NULL) {
        return;
    }
    if (level == v.size()) {
        v.push_back(root->data);
    }
    rec(root->left, level + 1, v);
    rec(root->right, level + 1, v);
}

vector<int> leftView(Node* root) {
    vector<int> v;
    rec(root, 0, v);
    return v;
}

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

    // Create Solution object and get the left view of the tree
    vector<int> leftViewNodes = leftView(root);

    // Print the left view of the binary tree
    cout << "Left view of the binary tree: ";
    for (int val : leftViewNodes) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
