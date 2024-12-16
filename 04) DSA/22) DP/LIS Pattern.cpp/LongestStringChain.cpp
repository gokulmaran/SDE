#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/longest-string-chain/description/
static bool compare(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& words) {
    unordered_map<string, int> dp;

    sort(words.begin(), words.end(), compare);

    int len = 1;
    for (const auto& word : words) {
        dp[word] = 1;
        for (int i = 0; i < word.length(); i++) {
            string pred = word.substr(0, i) + word.substr(i + 1);
            if (dp.find(pred) != dp.end()) {
                dp[word] = max(dp[word], dp[pred] + 1);
                len = max(len, dp[word]);
            }
        }
    }
    return len;
}

int main() {
    vector<string> words = {"a", "ab", "bac", "bca", "b", "ac", "abc", "abca"};

    int result = longestStrChain(words);
    
    cout << "Length of the longest string chain is: " << result << endl;

    return 0;
}
