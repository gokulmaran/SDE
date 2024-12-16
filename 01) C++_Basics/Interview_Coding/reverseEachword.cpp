#include <iostream>
#include <string>
using namespace std;

void reverseWord(string &s, int i, int j) {
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {
    string s;
    getline(cin, s); // Input the entire line including spaces

    int start = 0; // Start of the current word

    for (int i = 0; i <= s.size(); i++) {
        // If we encounter a space or end of string, reverse the current word
        if (i == s.size() || s[i] == ' ') {
            reverseWord(s, start, i - 1); // Reverse the word between `start` and `i-1`
            start = i + 1; // Move to the start of the next word
        }
    }

    cout << s << endl; // Output the modified string
    return 0;
}
