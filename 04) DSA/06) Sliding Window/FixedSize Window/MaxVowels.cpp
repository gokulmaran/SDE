#include <iostream>
#include <string>
#include <algorithm> // For max function

using namespace std;
//link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
class Solution {
public:
    bool isVowel(char s) {
        // Check if the character is a vowel
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
    }

    int maxVowels(string s, int k) {
        int maxi = 0;
        
        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                maxi++;
            }
        }
        
        int ans = maxi;
        
        // Slide the window across the string
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i])) {
                maxi++;
            }
            if (isVowel(s[i - k])) {
                maxi--;
            }
            ans = max(maxi, ans);
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "abciiidef";
    int k1 = 3;
    cout << "Maximum number of vowels in a substring of size " << k1 << " is: " 
         << solution.maxVowels(s1, k1) << endl;

    // Test case 2
    string s2 = "aeiou";
    int k2 = 2;
    cout << "Maximum number of vowels in a substring of size " << k2 << " is: " 
         << solution.maxVowels(s2, k2) << endl;

    // Test case 3
    string s3 = "leetcode";
    int k3 = 3;
    cout << "Maximum number of vowels in a substring of size " << k3 << " is: " 
         << solution.maxVowels(s3, k3) << endl;

    return 0;
}
