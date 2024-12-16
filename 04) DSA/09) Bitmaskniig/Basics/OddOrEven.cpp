#include <iostream>
#include <string>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/odd-or-even3618/1
class Solution {
public:
    string oddEven(int N) {
        // Check if the number is odd or even
        return (N & 1) == 1 ? "odd" : "even";
    }
};

int main() {
    Solution sol;

    // Test case 1
    int num1 = 7;
    cout << "Number: " << num1 << " is " << sol.oddEven(num1) << endl;

    // Test case 2
    int num2 = 20;
    cout << "Number: " << num2 << " is " << sol.oddEven(num2) << endl;

    // Test case 3
    int num3 = 0;
    cout << "Number: " << num3 << " is " << sol.oddEven(num3) << endl;

    return 0;
}
