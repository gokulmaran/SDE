#include <iostream>
#include <string>
using namespace std;

//link: https://www.naukri.com/code360/problems/count-distinct-substrings_985292
// TrieNode class
class TrieNode {
public:
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Trie class
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    int insert(string& str) {
        int newNode = 0;
        TrieNode* node = root;
        for (char ch : str) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
                newNode++;
            }
            node = node->children[idx];
        }
        return newNode;
    }
};

// Function to count distinct substrings
int countDistinctSubstrings(string &s) {
    Trie trie;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        string suffix = s.substr(i);
        cnt += trie.insert(suffix);
    }
    return cnt + 1; // +1 to account for the empty substring
}

// Main function to test the code
int main() {
    string s = "ababa";
    
    int distinctCount = countDistinctSubstrings(s);
    cout << "Number of distinct substrings: " << distinctCount << endl;
    
    return 0;
}
