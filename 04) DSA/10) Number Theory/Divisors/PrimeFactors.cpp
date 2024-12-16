#include <iostream>
#include <vector>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/prime-factors5052/0
// Define the Solution class with AllPrimeFactors function
class Solution {
public:
    vector<int> AllPrimeFactors(int n) {
        vector<int> ans;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                while (n % i == 0) {
                    n = n / i;
                }
            }
        }
        if (n != 1) ans.push_back(n);
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input value
    int n = 60;
    
    // Get all prime factors
    vector<int> primeFactors = sol.AllPrimeFactors(n);
    
    // Print the results
    cout << "Prime factors of " << n << " are: ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;
    
    return 0;
}
