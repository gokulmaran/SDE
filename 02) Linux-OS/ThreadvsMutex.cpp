#include <iostream>
#include <thread>
#include <mutex>
#include <chrono> // For sleep_for

using namespace std;

// Shared variable
int counter = 0;
// Mutex to protect the shared variable
mutex mtx;

// Function without using a mutex (unsafe access)
void incrementWithoutMutex() {
    for (int i = 0; i < 1000000; i++) { // Increased loop count
        counter++; // Unsafe increment
    }
}

// Function using a mutex (safe access)
void incrementWithMutex() {
    for (int i = 0; i < 1000000; i++) { // Increased loop count
        mtx.lock(); // Lock the mutex
        counter++;  // Safe increment
        mtx.unlock(); // Unlock the mutex
    }
}

int main() {
    // Demonstration without Mutex
    cout << "Without Mutex:" << endl;
    counter = 0; // Reset counter
    thread t1(incrementWithoutMutex);
    thread t2(incrementWithoutMutex);
    t1.join();
    t2.join();
    cout << "Final Counter Value (No Mutex): " << counter << endl;

    // Demonstration with Mutex
    cout << "\nWith Mutex:" << endl;
    counter = 0; // Reset counter
    thread t3(incrementWithMutex);
    thread t4(incrementWithMutex);
    t3.join();
    t4.join();
    cout << "Final Counter Value (With Mutex): " << counter << endl;

    return 0;
}
