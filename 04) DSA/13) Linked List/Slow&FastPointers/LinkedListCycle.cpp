#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//Link: https://leetcode.com/problems/linked-list-cycle/
// Class containing the hasCycle function
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

// Function to create a linked list with or without a cycle
ListNode* createListWithCycle(bool withCycle) {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    if (withCycle) {
        // Create a cycle: fifth node points back to the second node
        fifth->next = second;
    }

    return head;
}

// Function to print whether the list has a cycle
void printCycleStatus(ListNode* head) {
    Solution solution;
    bool result = solution.hasCycle(head);
    if (result) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }
}

int main() {
    // Test with a linked list that does not have a cycle
    ListNode* headNoCycle = createListWithCycle(false);
    cout << "Testing linked list without cycle: ";
    printCycleStatus(headNoCycle);

    // Clean up the list without cycle
    ListNode* temp;
    while (headNoCycle) {
        temp = headNoCycle;
        headNoCycle = headNoCycle->next;
        delete temp;
    }

    // Test with a linked list that has a cycle
    ListNode* headWithCycle = createListWithCycle(true);
    cout << "Testing linked list with cycle: ";
    printCycleStatus(headWithCycle);

    // Clean up the list with cycle
    // To prevent infinite loop during deletion, break the cycle first
    ListNode* node = headWithCycle;
    while (node->next != headWithCycle) {
        node = node->next;
    }
    node->next = nullptr; // Break the cycle
    while (headWithCycle) {
        temp = headWithCycle;
        headWithCycle = headWithCycle->next;
        delete temp;
    }

    return 0;
}
