#include <iostream>
#include <vector>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/1
// Function to compute the factorial of n
long long fact(long long n) {
    if (n == 0 || n == 1) {
        return 1; // Corrected base case for factorial
    }
    return n * fact(n - 1);
}

// Function to find all factorial numbers less than or equal to n
vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    for (int i = 1; ; i++) {
        long long res = fact(i);
        if (res <= n) {
            ans.push_back(res);
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    long long number;
    cout << "Enter a number: ";
    cin >> number;

    // Call the factorialNumbers function and store the result
    vector<long long> result = factorialNumbers(number);

    // Print the result
    cout << "Factorial numbers less than or equal to " << number << " are: ";
    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
