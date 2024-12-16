#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
class Solution {
public:
    // Function to find the first non-repeating character in the string
    string FirstNonRepeating(string A) {
        string ans = "";
        unordered_map<char, int> m; // Map to store frequency of characters
        queue<char> q; // Queue to maintain the order of characters
        
        for (char c : A) {
            q.push(c); // Add character to the queue
            m[c]++; // Increment character frequency
            
            // Remove characters from the queue that are repeating
            while (!q.empty() && m[q.front()] > 1) {
                q.pop();
            }
            
            // Check if the queue is empty and append to answer
            if (q.empty()) {
                ans += '#'; // No non-repeating character
            } else {
                ans += q.front(); // First non-repeating character
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string input1 = "aabccxb";
    string input2 = "abcabc";
    
    // Test the function with different inputs
    cout << "First non-repeating characters for \"" << input1 << "\": " << sol.FirstNonRepeating(input1) << endl;
    cout << "First non-repeating characters for \"" << input2 << "\": " << sol.FirstNonRepeating(input2) << endl;

    return 0;
}
