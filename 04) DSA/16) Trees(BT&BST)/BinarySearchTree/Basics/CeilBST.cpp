#include <iostream>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// Function to find the ceiling value in a BST
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    int ans = -1;
    while (root != NULL) {
        if (input <= root->data) {
            ans = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}

// Helper function to print the result
void printResult(int result) {
    if (result != -1) {
        cout << "The ceiling value is: " << result << endl;
    } else {
        cout << "No ceiling value found." << endl;
    }
}

int main() {
    // Create sample BST
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    // Find the ceiling value for a given integer
    int input = 7;
    int result = findCeil(root, input);

    // Print the result
    printResult(result);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
