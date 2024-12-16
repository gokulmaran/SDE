#include <iostream>
#include <cstring>

class MyClass {
public:
    char* data;  // Dynamically allocated memory for storing a string
    // Constructor
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];  // Allocate memory
        strcpy(data, str);  // Copy the string to the allocated memory
        std::cout << "Constructor called: Memory allocated and data copied." << std::endl;
    }

    // Copy Constructor (Deep Copy)
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];  // Allocate new memory
        strcpy(data, other.data);  // Copy the content of the string
        std::cout << "Copy Constructor called: Deep copy performed." << std::endl;
    }

    // Display method to show the data
    void display() const {
        std::cout << "Data: " << data << std::endl;
    }

    // Destructor
    ~MyClass() {
        delete[] data;  // Free the allocated memory
        std::cout << "Destructor called: Memory deallocated." << std::endl;
    }
};

int main() {
    MyClass obj1("Hello, Deep Copy!");  // Constructor is called
    MyClass obj2 = obj1;  // Deep copy happens here using Copy Constructor

    // Display data of both objects
    obj1.display();
    obj2.display();

    // Modify obj1's data (deep copy ensures obj2 is unaffected)
    std::cout << "After modifying obj1:" << std::endl;
    strcpy(obj1.data, "Modified!");  // Safe to modify obj1's data
    obj1.display();
    obj2.display();  // obj2 remains unchanged

    return 0;
}
