#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

void reverseEachWord(std::string &input) {
    std::istringstream iss(input); // To split the string into words
    std::string word;
    std::string result;

    while (iss >> word) {
        // Reverse the current word
        std::reverse(word.begin(), word.end());
        result += word + " "; // Append the reversed word to the result
    }

    // Remove the trailing space
    if (!result.empty()) {
        result.pop_back();
    }

    // Update the input string with the result
    input = result;
}
void reverseEachWord2(std::string &input) {
    std::string result = "";
    std::string currentWord = "";

    // Iterate through each character in the string
    for (int i = 0; i <= input.length(); i++) {
        if (i < input.length() && input[i] != ' ') {
            currentWord += input[i]; // Build the current word
        } else {
            // Reverse the current word manually
            for (int j = currentWord.length() - 1; j >= 0; j--) {
                result += currentWord[j];
            }
            if (i < input.length()) {
                result += ' '; // Add a space after the reversed word
            }
            currentWord = ""; // Reset the word for the next iteration
        }
    }

    // Update the input string with the result
    input = result;
}
void reverseEachWord3(std::string &input) {
    std::string result = "";
    std::string word = "";

    for (char c : input) {
        if (c != ' ') {
            word += c; // Build the current word
        } else {
            // Reverse the current word manually
            for (int i = word.length() - 1; i >= 0; i--) {
                result += word[i];
            }
            result += ' '; // Add a space after reversing the word
            word = ""; // Reset the word
        }
    }

    // Reverse the last word
    for (int i = word.length() - 1; i >= 0; i--) {
        result += word[i];
    }

    input = result; // Update the input string
}
int main() {
    std::string str = "Hello World! Let's reverse each word.";
    std::cout << "Original string: " << str << std::endl;

    reverseEachWord(str);
    reverseEachWord2(str);
    reverseEachWord3(str);

    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}
//===============================================