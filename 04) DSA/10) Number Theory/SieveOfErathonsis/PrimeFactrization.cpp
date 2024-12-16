#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/0
class Solution {
public:
    void sieve() {}
    
    void mySieve(vector<int>& prime, int n) {
        // Initialize the prime array
        for (int i = 1; i <= n; i++) {
            prime[i] = i;
        }
        // Sieve of Eratosthenes to find the smallest prime factors
        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (prime[j] == j) {
                        prime[j] = i;
                    }
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {
        // Vector to store the smallest prime factors
        vector<int> prime(N + 1);
        mySieve(prime, N);
        
        // Vector to store the prime factors of N
        vector<int> ans;
        
        // Find all prime factors of N
        while (N != 1) {
            ans.push_back(prime[N]);
            N = N / prime[N];
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    int N;
    cout << "Enter a number: ";
    cin >> N;
    
    // Get the prime factors of the number
    vector<int> primeFactors = sol.findPrimeFactors(N);
    
    // Output the result
    cout << "Prime factors of " << N << " are: ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;
    
    return 0;
}
