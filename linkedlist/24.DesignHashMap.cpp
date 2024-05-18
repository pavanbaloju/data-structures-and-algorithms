#include <iostream>
using namespace std;

// Node structure to store key-value pairs
struct ListKVNode
{
    int key, value;
    ListKVNode *next;
    ListKVNode(int k, int v) : key(k), value(v), next(nullptr) {}
};

// LinkedList structure to manage collisions
struct LinkedList
{
    ListKVNode *head;
    LinkedList()
    {
        head = new ListKVNode(-1, -1); // Dummy head node
    }

    // Add a new key-value pair or update the value if the key exists
    void add(int key, int value)
    {
        ListKVNode *node = head->next;
        while (node)
        {
            if (node->key == key)
            {
                node->value = value; // Key exists, update the value
                return;
            }
            node = node->next;
        }
        // Key doesn't exist, insert new node at head (after dummy)
        ListKVNode *newNode = new ListKVNode(key, value);
        newNode->next = head->next;
        head->next = newNode;
    }

    // Remove a key-value pair
    void remove(int key)
    {
        ListKVNode *node = head;
        while (node->next)
        {
            if (node->next->key == key)
            {
                ListKVNode *toDelete = node->next;
                node->next = node->next->next;
                delete toDelete;
                return;
            }
            node = node->next;
        }
    }

    // Get the value associated with a key
    int get(int key)
    {
        ListKVNode *node = head->next;
        while (node)
        {
            if (node->key == key)
            {
                return node->value;
            }
            node = node->next;
        }
        return -1; // Key not found
    }

    ~LinkedList()
    {
        ListKVNode *node = head;
        while (node)
        {
            ListKVNode *nextNode = node->next;
            delete node;
            node = nextNode;
        }
    }
};

class MyHashMap
{
private:
    static const int bucketSize = 1000; // Number of buckets
    LinkedList *buckets;                // Array of LinkedLists

    // Hash function to map a key to its bucket index
    int hash(int key)
    {
        return key % bucketSize;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        buckets = new LinkedList[bucketSize];
    }

    /** Add a key-value pair or update the value if the key already exists */
    void put(int key, int value)
    {
        int index = hash(key);
        buckets[index].add(key, value);
    }

    /** Get the value associated with a key or -1 if the key doesn't exist */
    int get(int key)
    {
        int index = hash(key);
        return buckets[index].get(key);
    }

    /** Remove the key-value pair if the key exists */
    void remove(int key)
    {
        int index = hash(key);
        buckets[index].remove(key);
    }

    ~MyHashMap()
    {
        delete[] buckets;
    }
};

int main()
{
    MyHashMap hashMap;

    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << "Get key 1: " << hashMap.get(1) << endl; // Output: 1
    cout << "Get key 3: " << hashMap.get(3) << endl; // Output: -1
    hashMap.put(2, 1);                               // Update the existing value
    cout << "Get key 2: " << hashMap.get(2) << endl; // Output: 1
    hashMap.remove(2);
    cout << "Get key 2: " << hashMap.get(2) << endl; // Output: -1

    return 0;
}
