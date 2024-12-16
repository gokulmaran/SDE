#include <iostream>
using namespace std;

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) return;
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    // Call the towerOfHanoi function to solve the problem
    cout << "Solution for Tower of Hanoi with " << numDisks << " disks:" << endl;
    towerOfHanoi(numDisks, 'A', 'B', 'C'); // A: source, B: auxiliary, C: destination

    return 0;
}
