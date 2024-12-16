#include <iostream>
using namespace std;

// Function to find the last index of x in the array
int lastIndex(int input[], int size, int x) {
    if (size < 0) {
        return -1;
    }
    if (input[size] == x) {
        return size;
    }
    return lastIndex(input, size - 1, x);
}

int main() {
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* input = new int[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    cout << "Enter the value to find the last index of: ";
    cin >> x;

    // Call the lastIndex function and store the result
    int result = lastIndex(input, n - 1, x);

    // Print the result
    cout << "Last index of " << x << ": " << result << endl;

    // Clean up dynamically allocated memory
    delete[] input;

    return 0;
}
