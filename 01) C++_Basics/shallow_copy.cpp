#include <iostream>
#include <cstring>

class ShallowCopyExample {
public:
    char* data; // Dynamically allocated resource
    // Constructor
    ShallowCopyExample(const char* value) {
        data = new char[strlen(value) + 1];
        strcpy(data, value);
    }

    // Copy Constructor (Shallow Copy)
    ShallowCopyExample(const ShallowCopyExample& other) {
        data = other.data; // Pointer copied directly, no new memory allocated
    }

    // Display the value
    void display() const {
        std::cout << "Data: " << data << std::endl;
    }

    // Destructor
    ~ShallowCopyExample() {
       // delete[] data; // May cause issues if shallow copied
        std::cout << "Destructor called!" << std::endl;
    }
};

int main() {
    ShallowCopyExample obj1("Hello");
    ShallowCopyExample obj2 = obj1; // Shallow copy happens here

    obj1.display();
    obj2.display();

    // Modify obj1's data (deep copy ensures obj2 is unaffected)
    std::cout << "After modifying obj1:" << std::endl;
    strcpy(obj1.data, "Modified!");  // Safe to modify obj1's data
    obj1.display();
    obj2.display();  // obj2 remains unchanged
    return 0; // Double delete issue occurs here
}
