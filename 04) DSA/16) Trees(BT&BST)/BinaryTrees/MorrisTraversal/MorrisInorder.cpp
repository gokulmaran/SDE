
#include <iostream>
#include <vector>

using namespace std;
//Link:https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1
// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Solution class containing the inOrder method
class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        Node* curr = root;
        Node* pre;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                pre = curr->left;
                
                while (pre->right != NULL && pre->right != curr) {
                    pre = pre->right;
                }
                
                if (pre->right == NULL) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};

// Helper function to print the vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Create sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    // Create Solution object
    Solution solution;
    
    // Get in-order traversal
    vector<int> inOrderTraversal = solution.inOrder(root);
    
    // Print in-order traversal
    cout << "In-order traversal: ";
    printVector(inOrderTraversal);

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
