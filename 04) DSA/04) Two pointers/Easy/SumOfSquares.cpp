#include <iostream>
#include <cmath>  // For sqrt function

using namespace std;
//Link: https://leetcode.com/problems/sum-of-square-numbers/description/
class Solution {
public:
    // Function to determine if 'c' can be expressed as a sum of two squares
    bool judgeSquareSum(int c) {
        long long i = 0;
        long long j = sqrt(c); // Start with the largest possible square root

        while (i <= j) {
            long long sum = (i * i) + (j * j);
            if (sum == c) {
                return true; // Found a valid pair
            } else if (sum > c) {
                j--; // Decrease the larger number
            } else {
                i++; // Increase the smaller number
            }
        }
        return false; // No valid pair found
    }
};

int main() {
    Solution sol;

    // Test cases
    int c1 = 5;   // 5 = 1^2 + 2^2
    int c2 = 3;   // 3 cannot be expressed as a sum of two squares
    int c3 = 13;  // 13 = 2^2 + 3^2

    // Check if the number can be expressed as a sum of two squares
    bool result1 = sol.judgeSquareSum(c1);
    bool result2 = sol.judgeSquareSum(c2);
    bool result3 = sol.judgeSquareSum(c3);

    // Output the results
    cout << "Can " << c1 << " be expressed as a sum of two squares? " 
         << (result1 ? "Yes" : "No") << endl;

    cout << "Can " << c2 << " be expressed as a sum of two squares? " 
         << (result2 ? "Yes" : "No") << endl;

    cout << "Can " << c3 << " be expressed as a sum of two squares? " 
         << (result3 ? "Yes" : "No") << endl;

    return 0;
}
