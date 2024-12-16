#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

void task1() {
    // for (int i = 0; i < 5; i++) {
    //     std::cout << "Task 1 is running: iteration " << i << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    // }
    cout<<"Hello world: first"<<endl;
    sleep(2);
    cout<<"Hello world: task1"<<endl;
}

void task2() {
    // for (int i = 0; i < 5; i++) {
    //     std::cout << "Task 2 is running: iteration " << i << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    // }
    cout<<"Hello world: second"<<endl;
    sleep(2);
    cout<<"Hello world: task2"<<endl;
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
