#include <iostream>
#include <cstring>
using namespace std;
//Link: https://classroom.codingninjas.com/app/classroom/me/18751/content/372777/offering/5270078/problem/38
// Function to replace occurrences of "pi" with "3.14"
void replacePi(char input[]) {
    int size = strlen(input) - 1;

    // Base case
    if (size < 0) {
        return;
    }

    // Operations
    if (input[0] == 'p' && input[1] == 'i') {
        // Shift characters to the right to make space for "3.14"
        int len = strlen(input);
        for (int i = len; i >= 2; i--) {
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

    // Recursive call
    replacePi(input + 1);
}

int main() {
    const int MAX_SIZE = 1000; // Define maximum size for the input string
    char input[MAX_SIZE];

    cout << "Enter a string: ";
    cin.getline(input, MAX_SIZE);

    // Call the replacePi function to modify the input string
    replacePi(input);

    // Print the modified string
    cout << "Modified string: " << input << endl;

    return 0;
}
