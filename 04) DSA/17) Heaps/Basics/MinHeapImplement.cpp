#include <iostream>
#include <climits> // For INT_MIN
using namespace std;
//link: https://www.naukri.com/code360/problems/min-heap-implementation_5480527
class minHeap {
public:
    int capacity, heapSize;
    int* heapArray;

    // Constructor for the class.
    minHeap(int cap) {
        heapSize = 0;
        capacity = cap;
        heapArray = new int[capacity];
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        if (heapSize <= 0) {
            return -1; // Heap is empty
        }
        if (heapSize == 1) {
            heapSize--;
            return heapArray[0]; // Only one element in heap
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        heapify(0);
        return root;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if (ind < heapSize) {
            decreaseKeyElement(ind, INT_MIN);
            extractMinElement();
        }
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        if (heapSize == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        
        int ind = heapSize;
        heapSize++;
        heapArray[ind] = val;

        // Fix the min heap property if it's violated
        while (ind != 0 && heapArray[ind] < heapArray[parent(ind)]) {
            swap(heapArray[ind], heapArray[parent(ind)]);
            ind = parent(ind);
        }
    }

    void decreaseKeyElement(int ind, int new_val) {
        heapArray[ind] = new_val;
        while (ind != 0 && heapArray[parent(ind)] > heapArray[ind]) {
            swap(heapArray[ind], heapArray[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int ind) {
        int l = left(ind);
        int r = right(ind);
        int smallest = ind;

        if (l < heapSize && heapArray[l] < heapArray[smallest]) {
            smallest = l;
        }
        if (r < heapSize && heapArray[r] < heapArray[smallest]) {
            smallest = r;
        }

        if (smallest != ind) {
            swap(heapArray[ind], heapArray[smallest]);
            heapify(smallest);
        }
    }

    // Utility function to print the heap
    void printHeap() {
        for (int i = 0; i < heapSize; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }

    ~minHeap() {
        delete[] heapArray;
    }
};

int main() {
    minHeap heap(10); // Create a min-heap with capacity 10

    // Insert elements into the heap
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    cout << "Min-Heap elements: ";
    heap.printHeap();

    cout << "Extracting min: " << heap.extractMinElement() << endl;
    cout << "Min-Heap elements after extraction: ";
    heap.printHeap();

    cout << "Deleting element at index 2" << endl;
    heap.deleteElement(2);
    cout << "Min-Heap elements after deletion: ";
    heap.printHeap();

    cout << "Inserting element 10" << endl;
    heap.insert(10);
    cout << "Min-Heap elements after insertion: ";
    heap.printHeap();

    cout << "Decreasing key of element at index 1 to 1" << endl;
    heap.decreaseKeyElement(1, 1);
    cout << "Min-Heap elements after decreasing key: ";
    heap.printHeap();

    return 0;
}
