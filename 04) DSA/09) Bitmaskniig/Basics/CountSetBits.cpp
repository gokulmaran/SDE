#include <iostream>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
class Solution {
public:
    // Function to return the sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i <<= 1) {
            int quotient = (n + 1) / (i << 1);
            int remainder = (n + 1) % (i << 1);
            count += quotient * i + max(0, remainder - i);
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int num1 = 5;
    cout << "Number of set bits from 1 to " << num1 << " is " << sol.countSetBits(num1) << endl;

    // Test case 2
    int num2 = 10;
    cout << "Number of set bits from 1 to " << num2 << " is " << sol.countSetBits(num2) << endl;

    // Test case 3
    int num3 = 15;
    cout << "Number of set bits from 1 to " << num3 << " is " << sol.countSetBits(num3) << endl;

    return 0;
}
