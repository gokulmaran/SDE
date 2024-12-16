#include <iostream>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/floor-in-bst/0
// Solution class containing the floor function
class Solution {
public:
    int floor(Node* root, int x) {
        int ans = -1;
        while (root != NULL) {
            if (x >= root->data) {
                ans = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return ans;
    }
};

// Helper function to print the result
void printResult(int result) {
    if (result != -1) {
        cout << "The floor value is: " << result << endl;
    } else {
        cout << "No floor value found." << endl;
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

    // Create Solution object
    Solution solution;

    // Find the floor value for a given integer
    int x = 7;
    int result = solution.floor(root, x);
    
    // Print the result
    printResult(result);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
