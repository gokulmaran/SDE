#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        cout<<"n value: "<<n<<endl;
        count += (n & 1);  // Add 1 if the least significant bit is 1
        n >>= 1;  // Right shift the number
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Number of set bits: " << countSetBits(n) << endl;
    
    return 0;
}
