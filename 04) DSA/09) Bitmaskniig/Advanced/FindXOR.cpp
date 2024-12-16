#include <iostream>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
class Solution {
public:
    int f(int n) {
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        if (n % 4 == 3) return 0;
        else return n;
    }

    int findXOR(int l, int r) {
        return f(l - 1) ^ f(r);
    }
};

int main() {
    Solution sol;

    // Test case 1
    int l1 = 3, r1 = 9;
    cout << "XOR of range [" << l1 << ", " << r1 << "] is " << sol.findXOR(l1, r1) << endl;

    // Test case 2
    int l2 = 0, r2 = 5;
    cout << "XOR of range [" << l2 << ", " << r2 << "] is " << sol.findXOR(l2, r2) << endl;

    // Test case 3
    int l3 = 10, r3 = 15;
    cout << "XOR of range [" << l3 << ", " << r3 << "] is " << sol.findXOR(l3, r3) << endl;

    return 0;
}
