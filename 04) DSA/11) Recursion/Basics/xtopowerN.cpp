#include <iostream>
using namespace std;

// Function to compute x^n
int power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return x * power(x, n - 1);
}

int main() {
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    // Call the power function and store the result
    int result = power(base, exponent);

    // Print the result
    cout << "Result: " << result << endl;

    return 0;
}
