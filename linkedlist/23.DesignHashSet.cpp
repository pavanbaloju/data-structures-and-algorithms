#include <iostream>
#include <vector>
using namespace std;

// Definition for a singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyHashSet
{
private:
    vector<ListNode *> buckets;         // Array of pointers to ListNode (linked lists) to store values
    static const int bucketSize = 1000; // Number of buckets, can be adjusted based on expected size

    // Hash function to map a value to its bucket index
    int hash(int key)
    {
        return key % bucketSize;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        buckets.resize(bucketSize, nullptr);
    }

    void add(int key)
    {
        int index = hash(key);
        ListNode *newNode = new ListNode(key);

        // If bucket is empty, insert newNode as the head
        if (!buckets[index])
        {
            buckets[index] = newNode;
            return;
        }

        // Traverse the linked list to check if key already exists
        ListNode *current = buckets[index];
        while (current)
        {
            if (current->val == key)
            {
                delete newNode; // Key already exists, no need to add again
                return;
            }
            if (!current->next)
                break; // Reached end of linked list
            current = current->next;
        }

        // Insert newNode at the end of the linked list
        current->next = newNode;
    }

    void remove(int key)
    {
        int index = hash(key);
        ListNode *dummy = new ListNode(-1); // Dummy node to handle edge case (removing head)
        dummy->next = buckets[index];

        ListNode *prev = dummy;
        ListNode *current = buckets[index];
        while (current)
        {
            if (current->val == key)
            {
                prev->next = current->next;
                delete current;
                buckets[index] = dummy->next; // Update head if needed
                delete dummy;                 // Delete dummy node
                return;
            }
            prev = current;
            current = current->next;
        }

        delete dummy; // Delete dummy node
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int index = hash(key);
        ListNode *current = buckets[index];
        while (current)
        {
            if (current->val == key)
            {
                return true; // Value found in linked list
            }
            current = current->next;
        }
        return false; // Value not found
    }
};

int main()
{
    MyHashSet hashSet;

    hashSet.add(1);
    hashSet.add(2);
    cout << "HashSet contains 1: " << hashSet.contains(1) << endl; // Output: 1 (true)
    cout << "HashSet contains 3: " << hashSet.contains(3) << endl; // Output: 0 (false)
    hashSet.add(2);
    cout << "HashSet contains 2: " << hashSet.contains(2) << endl; // Output: 1 (true)
    hashSet.remove(2);
    cout << "HashSet contains 2: " << hashSet.contains(2) << endl; // Output: 0 (false)

    return 0;
}
