#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isAlphanumeric(char s){
        if(s >= 'a' && s <= 'z') return true;
        if(s >= '0' && s <= '9') return true;
        if(s >= 'A' && s <= 'Z') return true;
        return false;
    }

    bool isPalindrome(string s) {
        string x;
        for(int i = 0; i < s.length(); i++){
            if(isAlphanumeric(s[i])){
                // Convert to lowercase and add to the filtered string
                x.push_back(tolower(s[i]));
            }
        }
        string revstr = x;
        reverse(revstr.begin(), revstr.end());
        return revstr == x;
    }
};

int main() {
    Solution sol;

    // Prompt the user for input
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Call the method to check if the string is a palindrome
    bool result = sol.isPalindrome(input);

    // Output the result
    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
