#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/count-primes/
class Solution {
public:
    // Function to generate a prime number sieve
    vector<bool> primeSieve(int n) {
        vector<bool> isPrime(n + 1, true);  // Initialize the prime status array
        isPrime[0] = isPrime[1] = false;   // 0 and 1 are not prime numbers

        // Mark non-prime numbers using the Sieve of Eratosthenes
        for (int i = 2; i <= n; ++i) {
            if (!isPrime[i] || (long long)i * i > n) 
                continue;
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }

        return isPrime;
    }

    // Function to count the number of prime numbers less than n
    int countPrimes(int n) {
        vector<bool> p = primeSieve(n);  // Get the sieve of primes up to n
        int ans = 0;
        for (int i = 2; i < n; ++i)   // Count primes less than n
            if (p[i])
                ans++;
        return ans;
    }
};

int main() {
    Solution sol;
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    // Get the count of prime numbers less than n
    int count = sol.countPrimes(n);
    
    // Output the result
    cout << "Number of primes less than " << n << " is: " << count << endl;
    
    return 0;
}
