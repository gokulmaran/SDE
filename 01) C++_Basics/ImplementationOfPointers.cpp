#include <iostream>

template <typename T>
class UniquePointer {
private:
    T* ptr; // Raw pointer being managed

public:
    // Constructor
    explicit UniquePointer(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePointer() {
        delete ptr;
        std::cout << "Resource destroyed by UniquePointer." << std::endl;
    }

    // Delete copy constructor and copy assignment to ensure unique ownership
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Move constructor
    UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Overload dereference operator
    T& operator*() const { return *ptr; }

    // Overload arrow operator
    T* operator->() const { return ptr; }

    // Get the raw pointer
    T* get() const { return ptr; }
};

int main() {
    UniquePointer<int> up(new int(42));
    std::cout << "Value: " << *up << std::endl;

    UniquePointer<int> up2 = std::move(up); // Transfer ownership
    if (up.get() == nullptr) {
        std::cout << "up is now null after move." << std::endl;
    }
    return 0;
}
