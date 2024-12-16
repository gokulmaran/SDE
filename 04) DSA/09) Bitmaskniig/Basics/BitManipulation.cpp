#include <iostream>
#include <bitset>  // For binary representation

using namespace std;
//link: https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/0
class Solution {
public:
    void bitManipulation(int num, int i) {
        // Extract the ith bit (1-based index) from num
        int x = (num >> (i - 1)) & 1;
        cout << "Bit at position " << i << ": " << x << " ";

        // Set the ith bit (1-based index) in num
        cout << "After setting bit at position " << i << ": " << (num | (1 << (i - 1))) << " ";

        // Clear the ith bit (1-based index) in num
        int z = num & (~(1 << (i - 1)));
        cout << "After clearing bit at position " << i << ": " << z << endl;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int num1 = 29;  // Binary: 11101
    int i1 = 3;     // Bit position to manipulate (1-based index)
    cout << "Original number: " << num1 << " (" << bitset<5>(num1) << ")" << endl;
    sol.bitManipulation(num1, i1);  // Bit manipulation on the 3rd bit

    cout << endl;

    // Test case 2
    int num2 = 14;  // Binary: 01110
    int i2 = 2;     // Bit position to manipulate (1-based index)
    cout << "Original number: " << num2 << " (" << bitset<5>(num2) << ")" << endl;
    sol.bitManipulation(num2, i2);  // Bit manipulation on the 2nd bit

    cout << endl;

    // Test case 3
    int num3 = 7;   // Binary: 00111
    int i3 = 1;     // Bit position to manipulate (1-based index)
    cout << "Original number: " << num3 << " (" << bitset<5>(num3) << ")" << endl;
    sol.bitManipulation(num3, i3);  // Bit manipulation on the 1st bit

    return 0;
}
