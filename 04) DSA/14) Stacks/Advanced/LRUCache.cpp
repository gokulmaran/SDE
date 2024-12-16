#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key, data;
    Node *next, *prev;
    Node(int k, int v) : key(k), data(v), next(NULL), prev(NULL) {}
};

class LRUCache {
    int size;
    unordered_map<int, Node*> mp;
    Node *head = NULL, *tail = NULL;

    void deleteNode(Node* num) {
        int k = num->key;

        if (num->prev == NULL) head = head->next;
        if (num->next == NULL) tail = tail->prev;

        if (num->prev != NULL) num->prev->next = num->next;
        if (num->next != NULL) num->next->prev = num->prev;

        mp.erase(k);
        delete num;
    }

    void insert(int k, int v) {
        Node* num = new Node(k, v);
        mp[k] = num;

        if (head == NULL) {
            head = tail = num;
            return;
        }

        tail->next = num;
        num->prev = tail;
        tail = num;
    }

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key) {
        if (mp.count(key) == 0) return -1;

        int val = mp[key]->data;
        deleteNode(mp[key]);
        insert(key, val);
        return val;
    }

    void put(int key, int value) {
        if (mp.count(key) == 0) {
            if (mp.size() == size) deleteNode(head);
        } else {
            deleteNode(mp[key]);
        }

        insert(key, value);
    }
};

int main() {
    // Create an LRU Cache with a capacity of 2
    LRUCache cache(2);

    // Put some values into the cache
    cache.put(1, 1); // Cache is {1=1}
    cache.put(2, 2); // Cache is {1=1, 2=2}

    // Get the value for key 1 (should return 1)
    cout << "get(1): " << cache.get(1) << endl; // returns 1

    // Put a new value which causes key 2 to be evicted
    cache.put(3, 3); // Cache is {1=1, 3=3}

    // Try to get the value for key 2 (should return -1, as it was evicted)
    cout << "get(2): " << cache.get(2) << endl; // returns -1

    // Put another value which causes key 1 to be evicted
    cache.put(4, 4); // Cache is {3=3, 4=4}

    // Try to get the value for key 1 (should return -1, as it was evicted)
    cout << "get(1): " << cache.get(1) << endl; // returns -1

    // Get the value for key 3 (should return 3)
    cout << "get(3): " << cache.get(3) << endl; // returns 3

}
