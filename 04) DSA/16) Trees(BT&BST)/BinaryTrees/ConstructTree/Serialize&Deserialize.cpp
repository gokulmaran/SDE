#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Codec class for serialization and deserialization
class Codec {
public:
    void buildString(TreeNode* root, string &res) {
        if (root == NULL) {
            res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    string serialize(TreeNode* root) { 
        string res = "";
        buildString(root, res);
        return res;
    }
    
    TreeNode* buildTree(queue<string> &q) {
        string s = q.front();
        q.pop();
        
        if (s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        string s = "";
        queue <string> q;
        
        for (char c: data) {
            if (c == ',') {
                q.push(s);
                s = "";
            } else {
                s += c;
            }
        }
        if (!s.empty()) { // push the last part of the data
            q.push(s);
        }
        
        return buildTree(q);
    }
};

// Helper function to print the tree in-order (for verification)
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    // Create Codec object
    Codec codec;
    
    // Serialize the tree
    string serializedTree = codec.serialize(root);
    cout << "Serialized tree: " << serializedTree << endl;
    
    // Deserialize the tree
    TreeNode* deserializedRoot = codec.deserialize(serializedTree);
    
    // Print in-order traversal of the deserialized tree
    cout << "In-order traversal of deserialized tree: ";
    printInOrder(deserializedRoot);
    cout << endl;

    // Clean up the tree (optional, to avoid memory leaks)
    // Implement a function to delete the tree if needed

    return 0;
}
