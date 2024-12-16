#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1
class Solution {
public:
    vector<int> primeRange(int m, int n) {
        vector<int> ans;
        vector<int> primes(n + 1, 0); // Use n+1 to handle range up to n

        // Edge cases
        if (n < 2) return ans; // No primes less than 2
        if (m < 2) m = 2; // Adjust m to be at least 2

        // Sieve of Eratosthenes to find primes up to n
        primes[0] = primes[1] = 1;
        for (int i = 2; i * i <= n; i++) {
            if (primes[i] == 0) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = 1;
                }
            }
        }

        // Collect all primes in the range [m, n]
        for (int i = m; i <= n; i++) {
            if (primes[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    int m, n;
    cout << "Enter the range (m n): ";
    cin >> m >> n;
    
    // Get the primes in the range [m, n]
    vector<int> primeNumbers = sol.primeRange(m, n);
    
    // Output the result
    cout << "Prime numbers between " << m << " and " << n << " are: ";
    for (int prime : primeNumbers) {
        cout << prime << " ";
    }
    cout << endl;
    
    return 0;
}
