#include <iostream>
#include <thread>
#include <mutex> // Include mutex library

std::mutex mtx; // Declare a global mutex

void task1() {
    // Lock the mutex before accessing shared resource
    mtx.lock();
    std::cout << "Hello world: first" << std::endl;
    std::cout << "Hello world: task1" << std::endl;
    mtx.unlock(); // Unlock after accessing the shared resource
}

void task2() {
    // Lock the mutex before accessing shared resource
    mtx.lock();
    std::cout << "Hello world: second" << std::endl;
    std::cout << "Hello world: task2" << std::endl;
    mtx.unlock(); // Unlock after accessing the shared resource
}

int main() {
    // Create threads to execute task1 and task2 concurrently
    std::thread t1(task1);
    std::thread t2(task2);

    // Wait for both threads to complete
    t1.join();
    t2.join();

    std::cout << "Both tasks completed!" << std::endl;

    return 0;
}
