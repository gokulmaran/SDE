#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/
int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int i = 0, j = 0, unique = 0, res = 0, cnt[26] = {};
    unordered_map<string, int> m;

    // Slide the window across the string
    while (j < s.size()) {
        // Increment count of current character
        if (++cnt[s[j++] - 'a'] == 1) ++unique;

        // Adjust window size and unique count
        while (unique > maxLetters || j - i > minSize)
            if (--cnt[s[i++] - 'a'] == 0) --unique;

        // Check if the current window size matches minSize
        if (j - i == minSize)
            res = max(res, ++m[s.substr(i, minSize)]);
    }
    return res;
}

int main() {
    // Test case 1
    string s1 = "abcabcabc";  // Input string
    int maxLetters1 = 2;      // Maximum number of unique letters
    int minSize1 = 2;         // Minimum size of the substring
    int maxSize1 = 3;         // Maximum size of the substring (not used in the function)
    
    // Print result for test case 1
    cout << "Max frequency for \"" << s1 << "\" with maxLetters=" << maxLetters1
         << ", minSize=" << minSize1 << ", maxSize=" << maxSize1 << " : " 
         << maxFreq(s1, maxLetters1, minSize1, maxSize1) << endl;
    // Expected output: 2

    // Test case 2
    string s2 = "aaaa";       // Input string
    int maxLetters2 = 1;      // Maximum number of unique letters
    int minSize2 = 2;         // Minimum size of the substring
    int maxSize2 = 3;         // Maximum size of the substring (not used in the function)
    
    // Print result for test case 2
    cout << "Max frequency for \"" << s2 << "\" with maxLetters=" << maxLetters2
         << ", minSize=" << minSize2 << ", maxSize=" << maxSize2 << " : " 
         << maxFreq(s2, maxLetters2, minSize2, maxSize2) << endl;
    // Expected output: 3

    // Test case 3
    string s3 = "ababbcb";    // Input string
    int maxLetters3 = 2;      // Maximum number of unique letters
    int minSize3 = 2;         // Minimum size of the substring
    int maxSize3 = 3;         // Maximum size of the substring (not used in the function)
    
    // Print result for test case 3
    cout << "Max frequency for \"" << s3 << "\" with maxLetters=" << maxLetters3
         << ", minSize=" << minSize3 << ", maxSize=" << maxSize3 << " : " 
         << maxFreq(s3, maxLetters3, minSize3, maxSize3) << endl;
    // Expected output: 2

    // Test case 4
    string s4 = "abcd";       // Input string
    int maxLetters4 = 2;      // Maximum number of unique letters
    int minSize4 = 1;         // Minimum size of the substring
    int maxSize4 = 4;         // Maximum size of the substring (not used in the function)
    
    // Print result for test case 4
    cout << "Max frequency for \"" << s4 << "\" with maxLetters=" << maxLetters4
         << ", minSize=" << minSize4 << ", maxSize=" << maxSize4 << " : " 
         << maxFreq(s4, maxLetters4, minSize4, maxSize4) << endl;
    // Expected output: 1

    return 0;
}
