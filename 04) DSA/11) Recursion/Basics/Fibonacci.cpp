#include <iostream>
using namespace std;

// Function to compute the nth Fibonacci number
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Call the fib function and store the result
    int result = fib(number);

    // Print the result
    cout << "Fibonacci number at position " << number << " is: " << result << endl;

    return 0;
}
