#include <iostream>
#include <cstring>
using namespace std;

// Function to insert '*' between identical adjacent characters
void pairStar(char input[]) {
    // Base case: end of string
    if (input[0] == '\0') {
        return;
    }

    // Recursive call for the rest of the string
    pairStar(input + 1);

    // Check for consecutive identical characters
    if (input[0] == input[1]) {
        int len = strlen(input);
        // Shift characters to make space for '*'
        for (int i = len; i >= 1; i--) {
            input[i + 1] = input[i];
        }
        input[1] = '*'; // Insert '*'
    }
}

int main() {
    const int MAX_SIZE = 1000; // Define maximum size for the input string
    char input[MAX_SIZE];

    cout << "Enter a string: ";
    cin.getline(input, MAX_SIZE);

    // Call the pairStar function to modify the input string
    pairStar(input);

    // Print the modified string
    cout << "Modified string: " << input << endl;

    return 0;
}
