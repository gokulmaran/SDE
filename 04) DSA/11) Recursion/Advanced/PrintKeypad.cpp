#include <iostream>
using namespace std;
//Link:https://classroom.codingninjas.com/app/classroom/me/18751/content/372778/offering/5270096/problem/49?leftPanelTabValue=PROBLEM
// Function to print all subsets of the array
void printSubsetsOfArray(int input[], int size, int output[], int outputSize) {
    if (size == 0) {
        for (int i = 0; i < outputSize; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive call without including the current element
    printSubsetsOfArray(input + 1, size - 1, output, outputSize);

    // Recursive call including the current element
    int newOutput[20] = {};
    for (int i = 0; i < outputSize; i++) {
        newOutput[i] = output[i];
    }
    newOutput[outputSize] = input[0];
    
    printSubsetsOfArray(input + 1, size - 1, newOutput, outputSize + 1);
}

// Function to initialize the recursive process
void printSubsetsOfArray(int input[], int size) {
    int ans[20] = {};
    printSubsetsOfArray(input, size, ans, 0);
}

int main() {
    const int MAX_SIZE = 20;
    int size;
    cout << "Enter the number of elements in the array (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Size exceeds maximum allowed size." << endl;
        return 1;
    }

    int input[MAX_SIZE];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    cout << "Subsets of the array:" << endl;
    printSubsetsOfArray(input, size);

    return 0;
}
