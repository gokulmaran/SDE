#include <iostream>
using namespace std;

class Base {
public:
    // Virtual function
    virtual void display() {
        cout << "Display function in Base class" << endl;
    }

    // Destructor
    virtual ~Base() {
        cout << "Base Destructor called!" << endl;
    }
};

class Derived : public Base {
public:
    // Overriding the virtual function
    void display() override {
        cout << "Display function in Derived class" << endl;
    }

    // Destructor
    ~Derived() {
        cout << "Derived Destructor called!" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    // Pointing base class pointer to derived class object
    basePtr = &derivedObj;

    // Calling virtual function, this will call the derived class version
    basePtr->display();

    return 0;
}
