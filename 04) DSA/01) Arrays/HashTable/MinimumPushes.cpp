#include <iostream>
#include <vector>
#include <algorithm> // For sort
#include <string>

using namespace std;
//Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> freq(26, 0); // Frequency array for each character
        
        // Calculate frequency of each character in the word
        for (char it : word) {
            freq[it - 'a']++;
        }

        // Sort the frequency array in decreasing order
        sort(freq.begin(), freq.end(), greater<int>());
        
        // Calculate the minimum number of pushes required
        for (int i = 0; i < 26; i++) {
            if (i < 8) {
                ans += freq[i];       // 1st row
            } else if (i < 16) {
                ans += freq[i] * 2;   // 2nd row
            } else if (i < 24) {
                ans += freq[i] * 3;   // 3rd row
            } else {
                ans += freq[i] * 4;   // 4th row
            }
        }

        return ans;
    }
};

int main() {
    // Example string
    string word = "abcdefghijklmnopqrstuvwxyz";

    // Create an instance of the Solution class
    Solution sol;

    // Calling the minimumPushes function to calculate the minimum pushes
    int result = sol.minimumPushes(word);

    // Output the result
    cout << "The minimum number of pushes required is: " << result << endl;

    return 0;
}
