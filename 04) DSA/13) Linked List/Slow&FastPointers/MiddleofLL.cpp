#include <iostream>

using namespace std;
//Link:https://leetcode.com/problems/middle-of-the-linked-list/
// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Class containing the middleNode function
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Function to create a linked list
ListNode* createList() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a linked list
    ListNode* head = createList();

    // Print the original linked list
    cout << "Linked list: ";
    printList(head);

    // Create a Solution object and find the middle node
    Solution solution;
    ListNode* middle = solution.middleNode(head);

    // Print the middle node
    if (middle) {
        cout << "Middle node value: " << middle->val << endl;
    } else {
        cout << "No middle node found" << endl;
    }

    // Free the allocated memory
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
