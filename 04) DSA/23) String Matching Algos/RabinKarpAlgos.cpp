#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
// Rabin-Karp search function
vector<int> search(string p, string t) {
    vector<int> ans;
    int d = 256; // Number of characters in the input alphabet
    int q = INT_MAX; // A prime number for hashing
    int n = t.length();
    int m = p.length();
    int t0 = 0; // Hash value of the text window
    int p0 = 0; // Hash value of the pattern
    
    // Calculate hash value of the pattern and the first window of text
    for(int i = 0; i < m; i++) {
        t0 = (t0 * d + t[i]) % q;
        p0 = (p0 * d + p[i]) % q;
    }
    
    // Precompute the value of d^(m-1) % q
    int x = 1;
    for(int i = 0; i < m - 1; i++) {
        x = (x * d) % q;
    }
    
    int i = 0;
    while(i <= n - m) {
        // If hash values match, check for actual substring match
        if(t0 == p0) {
            int j = 0;
            while(j < m && t[i + j] == p[j]) {
                j++;
            }
            if(j == m) {
                ans.push_back(i + 1); // 1-based index
            }
        }
        // Calculate the hash value of the next window
        if(i < n - m) {
            t0 = ((t0 - t[i] * x) * d + t[i + m]) % q;
            if(t0 < 0) {
                t0 = t0 + q;
            }
        }
        i++;
    }
    
    return ans;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    
    vector<int> positions = search(pattern, text);
    
    if (positions.empty()) {
        cout << "Pattern not found in text." << endl;
    } else {
        for (int pos : positions) {
            cout << "Pattern found at index " << pos << endl;
        }
    }
    
    return 0;
}
