#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/0
// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to construct a linked list from a vector of integers
Node* constructLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr;
    int size, value;

    cout << "Enter the number of elements in the list: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> value;
        arr.push_back(value);
    }

    Node* head = constructLL(arr);

    cout << "Constructed linked list is: ";
    printList(head);

    // Free the allocated memory (optional, for cleanup)
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
