#include <iostream>
using namespace std;
//Link:https://classroom.codingninjas.com/app/classroom/me/18751/content/372776/offering/5270066/problem/1123
// Function to compute the sum of the first n elements of the array
int sum(int input[], int n) {
    if (n == 0) return 0;
    return input[n - 1] + sum(input, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* input = new int[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    // Call the sum function and store the result
    int result = sum(input, n);

    // Print the result
    cout << "Sum of elements: " << result << endl;

    // Clean up dynamically allocated memory
    delete[] input;

    return 0;
}
