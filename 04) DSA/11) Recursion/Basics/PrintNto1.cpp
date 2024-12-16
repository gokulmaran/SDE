#include <iostream>
using namespace std;

// Function to print numbers from N to 1
void printNos(int N) {
    if (N == 0) return;
    cout << N << " "; // Print the current number
    printNos(N - 1); // Recursive call with N-1
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Call the function to print numbers from 'number' to 1
    printNos(number);

    return 0;
}
