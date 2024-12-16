#include <iostream>
using namespace std;

// Function to print numbers from 1 to n
void printNos(int n) {
    if (n == 0) {
        return;
    }
    printNos(n - 1); // Recursive call
    cout << n << " "; // Print number after the recursive call
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Call the function to print numbers from 1 to 'number'
    printNos(number);

    return 0;
}
