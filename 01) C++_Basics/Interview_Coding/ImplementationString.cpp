#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;  // Pointer to the character array
    int len;    // Length of the string

public:
    // Default Constructor
    String() : str(nullptr), len(0) {}

    // Parameterized Constructor
    String(const char* input) {
        len = strlen(input);               // Get the length of the input string
        str = new char[len + 1];           // Allocate memory for the string
        strcpy(str, input);                // Copy the input string to the class member
    }

    // Copy Constructor
    String(const String& other) {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }

    // Assignment Operator
    String& operator=(const String& other) {
        if (this != &other) {              // Self-assignment check
            delete[] str;                  // Free existing memory
            len = other.len;
            str = new char[len + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Concatenation
    String operator+(const String& other) const {
        char* temp = new char[len + other.len + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // Comparison
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Get Length
    int length() const {
        return len;
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Display the string
    void display() const {
        if (str) {
            cout << str;
        } else {
            cout << "Empty String";
        }
    }
};

int main() {
    // Example usage of the String class
    String s1("Hello");
    String s2("World");

    cout << "s1: ";
    s1.display();
    cout << "\ns2: ";
    s2.display();

    // Concatenation
    String s3 = s1 + s2;
    cout << "\ns1 + s2: ";
    s3.display();

    // Comparison
    if (s1 == s2) {
        cout << "\ns1 and s2 are equal";
    } else {
        cout << "\ns1 and s2 are not equal";
    }

    // Assignment
    String s4 = s1;
    cout << "\ns4 (copy of s1): ";
    s4.display();

    cout << "\nLength of s1: " << s1.length() << endl;

    return 0;
}
