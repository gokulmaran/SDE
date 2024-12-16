#include <iostream>
#include <string>
using namespace std;

string key[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Function to insert all possible combinations of the integer number into the output string array
int keypad(int num, string output[]) {
    if (num == 0 || num == 1) {
        output[0] = "";
        return 1;
    }

    int ans = keypad(num / 10, output);

    string temp = key[num % 10];
    int tempSize = temp.size();
    
    // Create new combinations by appending current digit's characters to the existing combinations
    for (int i = 1; i < tempSize; i++) {
        for (int j = 0; j < ans; j++) {
            output[ans * i + j] = output[j];
        }
    }

    for (int i = 0; i < tempSize; i++) {
        for (int j = 0; j < ans; j++) {
            output[ans * i + j] += temp[i];
        }
    }

    return ans * tempSize;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Determine the maximum number of combinations
    int maxCombinations = 1;
    while (num > 0) {
        maxCombinations *= key[num % 10].size();
        num /= 10;
    }

    // Reset num for function call
    num = 0;
    cout << "Enter the number again: ";
    cin >> num;

    // Create an array to store the combinations
    string* output = new string[maxCombinations];

    // Call the keypad function
    int count = keypad(num, output);

    // Print the combinations
    cout << "Possible combinations for " << num << ":" << endl;
    for (int i = 0; i < count; i++) {
        cout << output[i] << endl;
    }

    // Free allocated memory
    delete[] output;

    return 0;
}
