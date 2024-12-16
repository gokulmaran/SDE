#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//link: https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
class Solution{
public:
    int search(string pat, string txt) {
        unordered_map<char, int> m1, m2;
        int cnt = 0, i = 0, j = 0;
        int n = txt.size(), m = pat.size();

        // Build frequency map for the pattern
        for (int i = 0; i < m; i++) {
            m2[pat[i]]++;
        }

        while (j < n) {
            m1[txt[j]]++;

            // If the window size is less than the pattern length, expand the window
            if (j - i + 1 < m) {
                j++;
            } else {
                // Check if the current window matches the pattern
                if (m1 == m2) {
                    cnt++;
                }

                // Slide the window
                m1[txt[i]]--;
                if (m1[txt[i]] == 0) {
                    m1.erase(txt[i]);
                }
                i++;
                j++;
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;

    // Test case 1: Pattern exists multiple times
    string txt1 = "forxxorfxdofr";
    string pat1 = "for";
    int result1 = solution.search(pat1, txt1);
    cout << "Number of occurrences of pattern '" << pat1 << "' in text '" << txt1 << "': " << result1 << endl;

    // Test case 2: Pattern does not exist
    string txt2 = "abcde";
    string pat2 = "fgh";
    int result2 = solution.search(pat2, txt2);
    cout << "Number of occurrences of pattern '" << pat2 << "' in text '" << txt2 << "': " << result2 << endl;

    // Test case 3: Pattern and text are the same
    string txt3 = "abcd";
    string pat3 = "abcd";
    int result3 = solution.search(pat3, txt3);
    cout << "Number of occurrences of pattern '" << pat3 << "' in text '" << txt3 << "': " << result3 << endl;

    // Test case 4: Pattern length is greater than text length
    string txt4 = "short";
    string pat4 = "longpattern";
    int result4 = solution.search(pat4, txt4);
    cout << "Number of occurrences of pattern '" << pat4 << "' in text '" << txt4 << "': " << result4 << endl;

    // Test case 5: Pattern exists once
    string txt5 = "abcbadef";
    string pat5 = "abc";
    int result5 = solution.search(pat5, txt5);
    cout << "Number of occurrences of pattern '" << pat5 << "' in text '" << txt5 << "': " << result5 << endl;

    return 0;
}
