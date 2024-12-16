#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if (s.size() < p.size()) return {};
        
        vector<int> freq_p(26, 0);
        vector<int> window(26, 0);
        
        // Initialize frequency vectors
        for (int i = 0; i < p_len; i++) {
            freq_p[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        
        vector<int> ans;
        if (freq_p == window) ans.push_back(0);
        
        // Sliding window
        for (int i = p_len; i < s_len; i++) {
            window[s[i - p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if (freq_p == window) ans.push_back(i - p_len + 1);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> result1 = solution.findAnagrams(s1, p1);
    cout << "Anagrams of '" << p1 << "' in '" << s1 << "': ";
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    // Test case 2
    string s2 = "abab";
    string p2 = "ab";
    vector<int> result2 = solution.findAnagrams(s2, p2);
    cout << "Anagrams of '" << p2 << "' in '" << s2 << "': ";
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
