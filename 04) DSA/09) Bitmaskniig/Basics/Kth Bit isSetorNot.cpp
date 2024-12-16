#include <bits/stdc++.h>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
class Solution {
public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        // Check if the kth bit (0-based index) is set (1)
        return (n & (1 << k)) != 0;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int num1 = 29;  // Binary: 11101
    int k1 = 3;     // Check the 3rd bit (0-based index from the right)
    //cout << "Number: " << num1 << " (Binary: " << bitset<5>(num1) << ")" << endl;
    cout << "Is bit " << k1 << " set? " << (sol.checkKthBit(num1, k1) ? "Yes" : "No") << endl;

    cout << endl;

    // Test case 2
    int num2 = 14;  // Binary: 01110
    int k2 = 2;     // Check the 2nd bit (0-based index from the right)
    cout << "Number: " << num2 << " (Binary: " << bitset<5>(num2) << ")" << endl;
    cout << "Is bit " << k2 << " set? " << (sol.checkKthBit(num2, k2) ? "Yes" : "No") << endl;

    cout << endl;

    // Test case 3
    int num3 = 7;   // Binary: 00111
    int k3 = 1;     // Check the 1st bit (0-based index from the right)
    cout << "Number: " << num3 << " (Binary: " << bitset<5>(num3) << ")" << endl;
    cout << "Is bit " << k3 << " set? " << (sol.checkKthBit(num3, k3) ? "Yes" : "No") << endl;

    return 0;
}
