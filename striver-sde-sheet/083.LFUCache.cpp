#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

// Problem Statement:
// Design and implement a data structure for Least Frequently Used (LFU) cache.

// Intuition:
// Use a combination of unordered_map and doubly linked list.
// Store key-value pairs in the map where each key maps to a doubly linked list node containing its value.
// Maintain a frequency map where the frequency of each key is stored as a key, and the list of keys with that frequency is stored as a value.
// This helps in quickly accessing and updating elements based on their usage frequency.

// DSA Strategy:
// Doubly Linked List, Hash Map

// Approach:
// 1. Use two data structures: unordered_map for storing key-value pairs and key-frequency mappings, and a doubly linked list for storing nodes in order of their usage frequency.
// 2. When a key is accessed (get operation), update its frequency and move its corresponding node to the front of the list.
// 3. When a new key-value pair is inserted (put operation), if the cache is full, remove the least frequently used node (from the end of the list). Otherwise, simply add the new node to the front of the list.
// 4. Time complexity of both get and put operations is O(1) since unordered_map provides constant time access, and doubly linked list allows constant time node insertion and deletion.

class LFUCache
{
    struct Node
    {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    int capacity;                                    // Maximum capacity of the cache
    int minFreq;                                     // Minimum frequency among all nodes
    unordered_map<int, list<Node>::iterator> keyMap; // Map to store key-node mappings
    unordered_map<int, list<Node>> freqMap;          // Map to store frequency-list mappings

public:
    // Constructor to initialize the LFU cache with a given capacity
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    // Function to get the value associated with a key in the cache
    int get(int key)
    {
        // If the key is not found in the keyMap, return -1
        if (keyMap.find(key) == keyMap.end())
            return -1;

        // Retrieve the iterator to the node from keyMap
        auto nodeIter = keyMap[key];
        Node node = *nodeIter;

        // Remove the node from its current frequency list
        freqMap[node.freq].erase(nodeIter);

        // If the frequency list becomes empty, remove it from freqMap
        if (freqMap[node.freq].empty())
        {
            freqMap.erase(node.freq);
            // If the minimum frequency is the same as the node's frequency, increment minFreq
            if (node.freq == minFreq)
                minFreq++;
        }

        // Increment the frequency of the node
        node.freq++;

        // Add the node to the new frequency list
        freqMap[node.freq].push_front(node);

        // Update the iterator in keyMap
        keyMap[key] = freqMap[node.freq].begin();

        // Return the value associated with the key
        return node.value;
    }

    // Function to insert a key-value pair into the cache
    void put(int key, int value)
    {
        // If capacity is zero, return
        if (capacity == 0)
            return;

        // If the key already exists in the cache, update its value
        if (get(key) != -1)
        {
            keyMap[key]->value = value;
            return;
        }

        // If the cache is full, remove the least frequently used node
        if (keyMap.size() >= capacity)
        {
            auto it = freqMap[minFreq].back();
            keyMap.erase(it.key);
            freqMap[minFreq].pop_back();
            // If the minimum frequency list becomes empty, remove it from freqMap
            if (freqMap[minFreq].empty())
                freqMap.erase(minFreq);
        }

        // Set the minimum frequency to 1
        minFreq = 1;

        // Add the new node to the frequency list with frequency 1
        freqMap[minFreq].push_front(Node(key, value, 1));

        // Update the iterator in keyMap
        keyMap[key] = freqMap[minFreq].begin();
    }
};

// Main function
int main()
{
    // Create an instance of LFUCache with capacity 2
    LFUCache cache(2);

    // Put key-value pairs into the cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Retrieve and print the value corresponding to key 1
    cout << "Value for key 1: " << cache.get(1) << endl; // Expected output: 1

    // Put a new key-value pair into the cache (will evict key 2)
    cache.put(3, 3);

    // Retrieve and print the value corresponding to key 2 (should return -1 as it's been evicted)
    cout << "Value for key 2: " << cache.get(2) << endl; // Expected output: -1

    // Put a new key-value pair into the cache
    cache.put(4, 4);

    // Retrieve and print the value corresponding to key 1 (should still return 1)
    cout << "Value for key 1: " << cache.get(1) << endl; // Expected output: 1

    // Retrieve and print the value corresponding to key 3 (should return 3)
    cout << "Value for key 3: " << cache.get(3) << endl; // Expected output: 3

    // Retrieve and print the value corresponding to key 4 (should return 4)
    cout << "Value for key 4: " << cache.get(4) << endl; // Expected output: 4

    return 0;
}
