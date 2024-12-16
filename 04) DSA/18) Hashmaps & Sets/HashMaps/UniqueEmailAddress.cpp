#include <iostream>
#include <vector>
#include <map>

using namespace std;
//Link: https://leetcode.com/problems/unique-email-addresses/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> m;
        for (auto s : emails) {
            string temp = "";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '.')
                    continue;
                if (s[i] == '+' || s[i] == '@') {
                    while (s[i] != '@')
                        i++;
                    temp += s.substr(i, s.length());
                    break;
                } else {
                    temp += s[i];
                }
            }
            m[temp]++;
        }
        return m.size();
    }
};

int main() {
    Solution sol;

    // Example input
    vector<string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    
    // Calculate the number of unique emails
    int uniqueEmailsCount = sol.numUniqueEmails(emails);
    
    // Output the result
    cout << "Number of unique emails: " << uniqueEmailsCount << endl;

    return 0;
}
