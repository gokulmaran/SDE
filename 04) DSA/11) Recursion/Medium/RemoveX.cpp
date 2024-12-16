#include <iostream>
#include <cstring>
using namespace std;
//Link: https://classroom.codingninjas.com/app/classroom/me/18751/content/372777/offering/5270078/problem/39?leftPanelTabValue=PROBLEM
// Recursive function to remove 'x' characters from the string
void remoeX(char input[], int i) {
    if (input[i] == '\0') {
        return;
    }
    remoeX(input, i + 1);
    if (input[i] == 'x') {
        int len = strlen(input);
        int j;
        for (j = i + 1; j < len; j++) {
            input[j - 1] = input[j];
        }
        input[j - 1] = '\0';
    }
}

// Function to initialize the recursive removal
void removeX(char input[]) {
    remoeX(input, 0);
}

int main() {
    const int MAX_SIZE = 1000; // Define maximum size for the input string
    char input[MAX_SIZE];

    cout << "Enter a string: ";
    cin.getline(input, MAX_SIZE);

    // Call the removeX function to modify the input string
    removeX(input);

    // Print the modified string
    cout << "Modified string: " << input << endl;

    return 0;
}
