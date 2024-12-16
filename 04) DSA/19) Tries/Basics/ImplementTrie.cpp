#include <iostream>
#include <string>
using namespace std;
//Link: https://leetcode.com/problems/implement-trie-prefix-tree/
class TrieNode {
public:
    bool is_word;
    TrieNode* children[26];

    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < word_len; i++) {
            k = word[i] - 'a';
            if (cur->children[k] == NULL) {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->is_word = true;
    }

    // Function to search for a word in the Trie
    bool search(string word) {
        int len = word.length();
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < len; i++) {
            k = word[i] - 'a';
            cur = cur->children[k];
            if (cur == NULL) {
                return false;
            }
        }
        return cur->is_word;
    }

    // Function to check if any word in the Trie starts with the given prefix
    bool startsWith(string prefix) {
        int len = prefix.length();
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < len; i++) {
            k = prefix[i] - 'a';
            cur = cur->children[k];

            if (cur == NULL) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Create a new Trie instance
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Search for words in the Trie
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'banana': " << (trie.search("banana") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'ban': " << (trie.search("ban") ? "Found" : "Not Found") << endl;

    // Check if any prefix exists in the Trie
    cout << "Prefix 'app' exists: " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Prefix 'ban' exists: " << (trie.startsWith("ban") ? "Yes" : "No") << endl;
    cout << "Prefix 'bat' exists: " << (trie.startsWith("bat") ? "Yes" : "No") << endl;
    cout << "Prefix 'appl' exists: " << (trie.startsWith("appl") ? "Yes" : "No") << endl;

    return 0;
}
