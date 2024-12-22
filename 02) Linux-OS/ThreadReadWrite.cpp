#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

// Shared resource
vector<int> sharedData;
// Mutex for synchronization
mutex rwMutex;

// Writer function
void writer(int threadId) {
    for (int i = 0; i < 5; i++) {
        // Lock the mutex exclusively
        lock_guard<mutex> lock(rwMutex);
        sharedData.push_back(threadId * 10 + i); // Write operation
        cout << "Writer " << threadId << " added " << threadId * 10 + i << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate delay
    }
}

// Reader function
void reader(int threadId) {
    for (int i = 0; i < 5; i++) {
        // Lock the mutex for reading
        lock_guard<mutex> lock(rwMutex);
        cout << "Reader " << threadId << " reads: ";
        for (int val : sharedData) {
            cout << val << " ";
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate delay
    }
}

int main() {
    // Create threads
    thread writer1(writer, 1);
    thread writer2(writer, 2);
    thread reader1(reader, 1);
    thread reader2(reader, 2);

    // Join threads
    writer1.join();
    writer2.join();
    reader1.join();
    reader2.join();

    return 0;
}
