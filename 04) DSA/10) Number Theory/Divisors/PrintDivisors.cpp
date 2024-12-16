#include <iostream>
#include <vector>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
// Define the Solution class with print_divisors function
class Solution {
public:
    void print_divisors(int n) {
        vector<int> lastHalf;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";
                if (n / i != i)
                    lastHalf.push_back(n / i);
            }
        }
        for (int i = lastHalf.size() - 1; i >= 0; i--)
            cout << lastHalf[i] << " ";
    }
};

int main() {
    Solution sol;
    
    // Example input value
    int n = 36;
    
    // Print all divisors of n
    cout << "Divisors of " << n << " are: ";
    sol.print_divisors(n);
    cout << endl;
    
    return 0;
}
