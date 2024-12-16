#include <iostream>
using namespace std;
//Link: https://classroom.codingninjas.com/app/classroom/me/18751/content/372776/offering/5270074/problem/1135
// Function to find all indexes of the element x in the input array
int allIndexes(int input[], int size, int x, int output[]) {
    if (size == 0) {
        return 0;
    }

    int ans = allIndexes(input + 1, size - 1, x, output);

    if (input[0] == x) {
        for (int i = ans - 1; i >= 0; i--) {
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        ans++;
    } else {
        for (int i = ans - 1; i >= 0; i--) {
            output[i] = output[i] + 1;
        }
    }

    return ans;
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int input[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int x;
    cout << "Enter the element to find indexes of: ";
    cin >> x;

    // Create an output array large enough to hold all possible indexes
    int output[size];
    
    // Get all indexes of x in the input array
    int count = allIndexes(input, size, x, output);

    // Print the results
    cout << "Indexes of " << x << " are: ";
    for (int i = 0; i < count; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
