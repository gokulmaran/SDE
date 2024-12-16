#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};
//Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
Node* flatten(Node* root) {
    // Your code here
    std::multimap<int, Node*> mpp;
    Node* temp = root;
    Node* bot;

    // Traverse the list and populate the multimap
    while (temp) {
        bot = temp;
        while (bot) {
            mpp.insert({bot->data, bot});
            bot = bot->bottom;
        }
        temp = temp->next;
    }

    // Create the new flattened list
    if (mpp.empty()) return NULL;

    auto it = mpp.begin();
    Node* newHead = new Node(it->first);
    Node* newTemp = newHead;
    it++;

    while (it != mpp.end()) {
        newTemp->next = new Node(it->first);
        newTemp = newTemp->next;
        it++;
    }

    return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create sample nodes for testing
    Node* root = new Node(3);
    root->next = new Node(5);
    root->next->next = new Node(11);
    
    root->bottom = new Node(8);
    root->bottom->bottom = new Node(7);
    
    root->next->bottom = new Node(2);
    
    // Flatten the list
    Node* flattenedList = flatten(root);
    
    // Print the flattened list
    std::cout << "Flattened list: ";
    printList(flattenedList);
    
    // Clean up memory (not shown here for brevity)
    return 0;
}

