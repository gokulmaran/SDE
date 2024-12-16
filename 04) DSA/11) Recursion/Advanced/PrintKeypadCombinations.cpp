#include <iostream>
#include <string>
using namespace std;
//Link:https://classroom.codingninjas.com/app/classroom/me/18751/content/372778/offering/5270094/problem/1392
// Array representing the keypad mappings
string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Recursive function to generate all possible combinations
void print(int num, string output) {
    if (num == 0) {
        if (output != " ") { // Avoid printing for the initial empty output
            cout << output << endl;
        }
        return;
    }
    string temp = keypad[num % 10];
    for (int i = 0; i < temp.size(); i++) {
        print(num / 10, temp[i] + output);
    }
}

// Function to handle the initial call for print combinations
void printKeypad(int num) {
    // Handle case when num is 0
    if (num == 0) {
        cout << " " << endl; // Edge case for input 0
        return;
    }
    string output = "";
    print(num, output);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Call the printKeypad function to print all combinations
    cout << "Possible combinations for " << num << ":" << endl;
    printKeypad(num);

    return 0;
}
