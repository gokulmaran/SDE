#include <iostream>
#include <cstring> // For strlen and strcpy

class String {
private:
    char *data;       // Pointer to store the string
    size_t length;    // Length of the string

public:
    // Default Constructor
    String() : data(nullptr), length(0) {}

    // Parameterized Constructor
    String(const char *str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // Copy Constructor
    String(const String &other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Move Constructor
    String(String &&other) noexcept {
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Assignment Operator (Copy)
    String &operator=(const String &other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        delete[] data; // Free existing memory
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);

        return *this;
    }

    // Assignment Operator (Move)
    String &operator=(String &&other) noexcept {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        delete[] data; // Free existing memory
        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;

        return *this;
    }

    // Concatenation Operator
    String operator+(const String &other) const {
        size_t newLength = length + other.length;
        char *newData = new char[newLength + 1];

        strcpy(newData, data);
        strcat(newData, other.data);

        return String(newData);
    }

    // Equality Operator
    bool operator==(const String &other) const {
        return strcmp(data, other.data) == 0;
    }

    // Index Operator
    char &operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Length Getter
    size_t size() const {
        return length;
    }

    // Print the string
    void print() const {
        if (data) {
            std::cout << data;
        } else {
            std::cout << "(empty)";
        }
    }
};

int main() {
    // Test default constructor
    String s1;
    std::cout << "s1: ";
    s1.print();
    std::cout << "\n";

    // Test parameterized constructor
    String s2("Hello");
    std::cout << "s2: ";
    s2.print();
    std::cout << "\n";

    // Test copy constructor
    String s3 = s2;
    std::cout << "s3 (copy of s2): ";
    s3.print();
    std::cout << "\n";

    // Test assignment operator
    String s4;
    s4 = s2;
    std::cout << "s4 (assigned from s2): ";
    s4.print();
    std::cout << "\n";

    // Test move constructor
    String s5 = String("World");
    std::cout << "s5: ";
    s5.print();
    std::cout << "\n";

    // Test concatenation
    String s6 = s2 + s5;
    std::cout << "s6 (s2 + s5): ";
    s6.print();
    std::cout << "\n";

    // Test equality operator
    std::cout << "s2 == s3: " << (s2 == s3 ? "true" : "false") << "\n";
    std::cout << "s2 == s5: " << (s2 == s5 ? "true" : "false") << "\n";

    // Test indexing
    std::cout << "s2[1]: " << s2[1] << "\n";

    // Test length
    std::cout << "Length of s6: " << s6.size() << "\n";

    return 0;
}