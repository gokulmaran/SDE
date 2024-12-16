#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
//link: https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < s1.length(); i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (m1 == m2) return true;
            
            // Slide the window
            m2[s2[i]]--;
            if (m2[s2[i]] == 0) {
                m2.erase(s2[i]);
            }
            if (i + s1.length() < s2.length()) {
                m2[s2[i + s1.length()]]++;
            }
        }
        
        return m1 == m2;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1_1 = "ab";
    string s2_1 = "eidbaooo";
    bool result1 = solution.checkInclusion(s1_1, s2_1);
    cout << "Does s2 contain a permutation of s1? " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    string s1_2 = "ab";
    string s2_2 = "eidboaoo";
    bool result2 = solution.checkInclusion(s1_2, s2_2);
    cout << "Does s2 contain a permutation of s1? " << (result2 ? "Yes" : "No") << endl;

    // Test case 3
    string s1_3 = "abc";
    string s2_3 = "ccccbbbbaaaa";
    bool result3 = solution.checkInclusion(s1_3, s2_3);
    cout << "Does s2 contain a permutation of s1? " << (result3 ? "Yes" : "No") << endl;

    return 0;
}
