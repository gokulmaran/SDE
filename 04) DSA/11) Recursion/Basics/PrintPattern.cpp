#include <iostream>
#include <vector>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/print-pattern3549/1
// Recursive function to generate the pattern
void pattern1(int n, vector<int>& arr) {
    if (n <= 0) {
        arr.push_back(n);
        return;
    }
    arr.push_back(n);
    pattern1(n - 5, arr);
    arr.push_back(n);
}

// Function to initialize and call the recursive pattern1
vector<int> pattern(int n) {
    vector<int> arr;
    pattern1(n, arr);
    return arr;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Call the pattern function and store the result
    vector<int> result = pattern(number);

    // Print the result
    cout << "Generated pattern: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
