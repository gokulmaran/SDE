#include <iostream>

using namespace std;
//Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal; // XOR to find differing bits
        int cnt = 0;

        // Count the number of 1s in the result
        for (int i = 0; i < 31; i++) {
            if (ans & (1 << i)) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int start1 = 10; // Binary: 1010
    int goal1 = 7;   // Binary: 0111
    cout << "Minimum bit flips required: " << sol.minBitFlips(start1, goal1) << endl; // Expected output: 3

    // Test case 2
    int start2 = 29; // Binary: 11101
    int goal2 = 15;  // Binary: 01111
    cout << "Minimum bit flips required: " << sol.minBitFlips(start2, goal2) << endl; // Expected output: 3

    // Test case 3
    int start3 = 0;  // Binary: 00000
    int goal3 = 31;  // Binary: 11111
    cout << "Minimum bit flips required: " << sol.minBitFlips(start3, goal3) << endl; // Expected output: 5

    // Test case 4
    int start4 = 12345; // Binary: 11000000111001
    int goal4 = 54321;  // Binary: 11010100001100101
    cout << "Minimum bit flips required: " << sol.minBitFlips(start4, goal4) << endl; // Expected output: 13

    return 0;
}
