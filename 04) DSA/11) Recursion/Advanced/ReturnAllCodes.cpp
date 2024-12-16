#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Link: https://classroom.codingninjas.com/app/classroom/me/18751/content/372778/offering/5270096/problem/1387?leftPanelTabValue=PROBLEM
// Helper function to generate codes based on the input string
void help(string input, string out, vector<string> &str) {
    if (input.size() == 0) {
        str.push_back(out);
        return;
    }

    char c1 = (input[0] - '0') + 96;
    if (input[0] == '0')
        return;
    help(input.substr(1), out + c1, str);

    if (input.size() > 1) {
        int d = (input[0] - '0') * 10 + (input[1] - '0');
        if (d > 26)
            return;
        char c2 = 96 + d;
        help(input.substr(2), out + c2, str);
    }
}

// Function to get all possible codes from the input string
int getCodes(string input, string output[10000]) {
    vector<string> str;
    string out = "";
    help(input, out, str);

    for (int i = 0; i < str.size(); i++)
        output[i] = str[i];

    return str.size();
}

int main() {
    string input;
    cout << "Enter the numeric string: ";
    cin >> input;

    // Ensure the input string length does not exceed 10000 codes
    string output[10000];
    
    // Get all possible codes and store them in output
    int count = getCodes(input, output);

    // Print the results
    cout << "Possible codes are:" << endl;
    for (int i = 0; i < count; i++) {
        cout << output[i] << endl;
    }

    return 0;
}
