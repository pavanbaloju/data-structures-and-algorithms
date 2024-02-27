#include <iostream>
#include <unordered_map>

using namespace std;

// Problem Statement:
// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and put.

// Intuition:
// We can use a combination of doubly linked list and hash map to implement an efficient LRUCache.
// Doubly linked list helps us maintain the order of elements based on their usage (recently used elements are moved to the front),
// while hash map provides O(1) access for each key.

// DSA Strategy:
// Doubly Linked List, Hash Map

// Approach:
// 1. Maintain a doubly linked list to store the keys in the order of their usage, with the most recently used key at the front and least recently used key at the end.
// 2. Use a hash map to store key-value pairs, where each key maps to its corresponding node in the doubly linked list.
// 3. For the get operation, if the key is present in the cache, move the corresponding node to the front of the list and return its value. Otherwise, return -1.
// 4. For the put operation, if the key is already present in the cache, update its value and move the corresponding node to the front of the list.
//    If the key is not present and the cache is full, remove the least recently used key from the end of the list and the hash map.
//    Then, add the new key-value pair to the front of the list and the hash map.
// 5. Time complexity of both get and put operations is O(1) since hash map provides constant time access and doubly linked list allows constant time node insertion and deletion.

class LRUCache
{
public:
    struct Node
    {
        int key, val;      // Key and value stored in the node
        Node *next, *prev; // Pointers to the next and previous nodes

        Node() : key(0), val(0), next(nullptr), prev(nullptr) {}                                       // Default constructor
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}                   // Constructor with key and value
        Node(int key, int val, Node *next, Node *prev) : key(key), val(val), next(next), prev(prev) {} // Constructor with key, value, next, and previous pointers
    };

    unordered_map<int, Node *> map;              // Hash map to store key-value pairs (key is the cache key, value is the corresponding node)
    Node *head = new Node(), *tail = new Node(); // Dummy head and tail nodes for the doubly linked list
    int cap = 0;                                 // Capacity of the cache

    // Constructor to initialize the LRUCache with a given capacity
    LRUCache(int capacity)
    {
        cap = capacity;    // Set the capacity
        head->next = tail; // Initialize head's next pointer to tail
        tail->prev = head; // Initialize tail's prev pointer to head
    }

    /**
     * @brief Adds a new node to the front of the doubly linked list
     *
     * @param newnode The new node to be added
     */
    void addNodeToFront(Node *newnode)
    {
        Node *nxt = head->next; // Get the next node after head

        newnode->next = nxt;  // Set new node's next pointer
        newnode->prev = head; // Set new node's prev pointer

        head->next = newnode; // Update head's next pointer
        nxt->prev = newnode;  // Update next node's prev pointer
    }

    /**
     * @brief Deletes a node from the doubly linked list
     *
     * @param delnode The node to be deleted
     */
    void deleteNode(Node *delnode)
    {
        Node *pre = delnode->prev; // Get the previous node
        Node *nxt = delnode->next; // Get the next node

        pre->next = nxt; // Update previous node's next pointer
        nxt->prev = pre; // Update next node's prev pointer
    }

    /**
     * @brief Inserts a key-value pair into the hash map
     *
     * @param key The key to be inserted
     * @param node The corresponding node in the doubly linked list
     */
    void insertInMap(int key, Node *node)
    {
        map[key] = node; // Insert key-value pair into the map
    }

    /**
     * @brief Deletes a key-value pair from the hash map
     *
     * @param key The key to be deleted
     */
    void deleteFromMap(int key)
    {
        map.erase(key); // Erase the key from the map
    }

    /**
     * @brief Get the value corresponding to a key from the cache
     *
     * @param key The key to be searched for
     * @return int The value corresponding to the key, -1 if key doesn't exist
     */
    int get(int key)
    {
        if (map.find(key) != map.end())
        {                             // If key exists in the cache
            Node *resNode = map[key]; // Get the corresponding node
            int ans = resNode->val;   // Get the value

            deleteNode(resNode); // Delete the node from the list
            deleteFromMap(key);  // Delete the key from the map

            addNodeToFront(resNode);      // Add the node to the front of the list
            insertInMap(key, head->next); // Insert key-value pair into the map
            return ans;                   // Return the value
        }
        return -1; // Return -1 if key doesn't exist
    }

    /**
     * @brief Put a key-value pair into the cache
     *
     * @param key The key to be inserted/updated
     * @param value The corresponding value
     */
    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {                          // If key exists in the cache
            Node *curr = map[key]; // Get the corresponding node
            curr->val = value;     // Update the node's value
            deleteFromMap(key);    // Delete the key from the map
            deleteNode(curr);      // Delete the node from the list
        }

        if (map.size() == cap)
        {                                   // If cache is full
            deleteFromMap(tail->prev->key); // Delete the least recently used key from the map
            deleteNode(tail->prev);         // Delete the least recently used node from the list
        }
        addNodeToFront(new Node(key, value)); // Add new node to the front of the list
        insertInMap(key, head->next);         // Insert key-value pair into the map}
    }
};

// Main function
int main()
{
    // Create an instance of LRUCache with capacity 2
    LRUCache lRUCache(2);

    // Put key-value pairs into the cache
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);

    // Retrieve and print the value corresponding to key 1
    cout << "Value for key 1: " << lRUCache.get(1) << endl; // Expected output: 1

    // Put a new key-value pair into the cache (will evict key 2)
    lRUCache.put(3, 3);

    // Retrieve and print the value corresponding to key 2 (should return -1 as it's been evicted)
    cout << "Value for key 2: " << lRUCache.get(2) << endl; // Expected output: -1

    // Put a new key-value pair into the cache
    lRUCache.put(4, 4);

    // Retrieve and print the value corresponding to key 1 (should still return 1)
    cout << "Value for key 1: " << lRUCache.get(1) << endl; // Expected output: 1

    // Retrieve and print the value corresponding to key 3 (should return 3)
    cout << "Value for key 3: " << lRUCache.get(3) << endl; // Expected output: 3

    // Retrieve and print the value corresponding to key 4 (should return 4)
    cout << "Value for key 4: " << lRUCache.get(4) << endl; // Expected output: 4

    return 0;
}
