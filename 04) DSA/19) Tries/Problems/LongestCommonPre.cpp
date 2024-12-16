#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Link: https://leetcode.com/problems/longest-common-prefix/
// TrieNode class
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childcnt;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        this->isTerminal = false;
        this->childcnt = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

// Trie class
class Trie {
public:
    TrieNode* root;

    Trie() {
        this->root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        int ind = word[0] - 'a';
        if (root->children[ind] != NULL) {
            insertUtil(root->children[ind], word.substr(1));
        } else {
            root->children[ind] = new TrieNode(word[0]);
            root->childcnt++;
            insertUtil(root->children[ind], word.substr(1));
        }
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lsp(string str, string &ans) {
        TrieNode* node = root; // Use a local variable to avoid modifying the root
        for (auto c : str) {
            if (node->childcnt == 1) {
                ans.push_back(c);
                int ind = c - 'a';
                node = node->children[ind]; // Move to the child node
            } else {
                break;
            }
            if (node->isTerminal) break;
        }
    }
};

// Solution class
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        for (auto word : strs) {
            if (word.empty()) {
                return "";
            }
            t->insertWord(word);
        }
        string ans = "";
        t->lsp(strs[0], ans);
        delete t; // Clean up Trie instance
        return ans;
    }
};

// Main function to test the code
int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};

    string lcp = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << lcp << endl;

    return 0;
}
