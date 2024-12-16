#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
//Link: https://www.naukri.com/code360/problems/tree-traversal_981269
// Function to perform tree traversal
void solve(TreeNode* root, vector<int>& in, vector<int>& pre, vector<int>& post) {
    if (root == nullptr) {
        return;
    }
    pre.push_back(root->data);
    solve(root->left, in, pre, post);
    in.push_back(root->data);
    solve(root->right, in, pre, post);
    post.push_back(root->data);
}

// Function to get all tree traversals
vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<vector<int>> ans;
    vector<int> In, pre, post;
    solve(root, In, pre, post);
    ans.push_back(pre); // Preorder traversal
    ans.push_back(In);  // Inorder traversal
    ans.push_back(post); // Postorder traversal
    return ans;
}

// Main function to test the getTreeTraversal method
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Get the tree traversals
    vector<vector<int>> traversals = getTreeTraversal(root);

    // Print Preorder traversal
    cout << "Preorder traversal: ";
    for (int val : traversals[0]) cout << val << " ";
    cout << endl;

    // Print Inorder traversal
    cout << "Inorder traversal: ";
    for (int val : traversals[1]) cout << val << " ";
    cout << endl;

    // Print Postorder traversal
    cout << "Postorder traversal: ";
    for (int val : traversals[2]) cout << val << " ";
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
