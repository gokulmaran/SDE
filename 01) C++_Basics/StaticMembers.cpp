#include <iostream>
using namespace std;

class MyClass {
public:
    static int count;  // Static member variable

    MyClass() {
        count++;  // Increment static count whenever an object is created
    }

    ~MyClass() {
        count--;  // Decrement static count when an object is destroyed
    }

    static void displayCount() {
        cout << "Number of objects: " << count << endl;  // Access static variable
    }
};

// Definition and initialization of static member variable
int MyClass::count = 0;

int main() {
    MyClass obj1;
    MyClass obj2;

    MyClass::displayCount();  // Output: Number of objects: 2

    
        MyClass obj3;
        MyClass::displayCount();  // Output: Number of objects: 3
      // obj3 goes out of scope and destructor is called

    MyClass::displayCount();  // Output: Number of objects: 2

    return 0;
}
