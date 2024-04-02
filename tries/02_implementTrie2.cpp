#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement a Trie (prefix tree) data structure that supports the following operations:
// 1. Insert a word into the Trie.
// 2. Count the number of words equal to a given word.
// 3. Count the number of words that have a given prefix.
// 4. Erase a word from the Trie.

// Intuition:
// Extending the Trie data structure to support additional operations such as counting words equal to a given word and erasing a word involves keeping track of counts for each node.
// By maintaining counters for words ending with the node and words having the prefix up to the node, these operations can be efficiently implemented.

// DSA Strategy/Pattern:
// Trie Data Structure

// Approach:
// Trie Implementation with Counters:
// 1. Define a Node structure representing each node in the Trie. Each node contains an array of links to child nodes (26 for lowercase English letters) and integer counters for words ending with the node and words having the prefix up to the node.
// 2. Implement methods within the Node structure to perform Trie operations:
//    - containKey(char ch): Check if a child node exists for the given character.
//    - put(char ch, Node* node): Create a link to the given node for the specified character.
//    - get(char ch): Retrieve the child node corresponding to the given character.
//    - incrementEndsWith(): Increment the counter for words ending with the current node.
//    - incrementCountPrefix(): Increment the counter for words having the prefix up to the current node.
//    - decrementEndsWith(): Decrement the counter for words ending with the current node.
//    - decrementCountPrefix(): Decrement the counter for words having the prefix up to the current node.
//    - getEndsWith(): Get the count of words ending with the current node.
//    - getCountPrefix(): Get the count of words having the prefix up to the current node.
// 3. Define a Trie class encapsulating the Trie operations:
//    - insert(string word): Insert a word into the Trie by iterating over its characters, creating nodes as necessary, and updating the counters.
//    - countWordsEqualTo(string word): Count the number of words equal to a given word by traversing the Trie based on the characters of the word and retrieving the counter at the corresponding node.
//    - countWordsStartsWith(string word): Count the number of words starting with a given prefix by traversing the Trie based on the characters of the prefix and retrieving the counter at the corresponding node.
//    - erase(string word): Erase a word from the Trie by traversing the Trie based on the characters of the word, updating the counters, and removing nodes as necessary.
// 4. Perform the specified operations (insert, countWordsEqualTo, countWordsStartsWith, erase) on the Trie based on the provided input.

// Time Complexity:
// - Insertion: O(m), where m is the length of the inserted word.
// - Counting words equal to a given word: O(m), where m is the length of the given word.
// - Counting words starting with a given prefix: O(p), where p is the length of the prefix.
// - Erasing a word: O(m), where m is the length of the word to be erased.
// Space Complexity: O(N * M), where N is the number of inserted words and M is the average length of the words.

// Node structure for the Trie
struct Node
{
    Node *links[26];                   // Array of links to child nodes
    int endsWith = 0, countPrefix = 0; // Counter variables for words ending with and prefix count

    // Checks if a child node exists for the given character
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // Creates a link to the given node for the specified character
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // Retrieves the child node corresponding to the given character
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // Increment the counter for words ending with the current node
    void incrementEndsWith()
    {
        endsWith++;
    }

    // Increment the counter for words having the prefix up to the current node
    void incrementCountPrefix()
    {
        countPrefix++;
    }

    // Decrement the counter for words ending with the current node
    void decrementEndsWith()
    {
        endsWith--;
    }

    // Decrement the counter for words having the prefix up to the current node
    void decrementCountPrefix()
    {
        countPrefix--;
    }

    // Get the count of words ending with the current node
    int getEndsWith()
    {
        return endsWith;
    }

    // Get the count of words having the prefix up to the current node
    int getCountPrefix()
    {
        return countPrefix;
    }
};

// Trie class
class Trie
{
private:
    Node *root; // Root node of the Trie

public:
    // Constructor to initialize the Trie
    Trie()
    {
        root = new Node(); // Create a new root node
    }

    // Inserts a word into the Trie
    void insert(string word)
    {
        Node *node = root; // Initialize node to root
        for (int i = 0; i < word.size(); i++)
        {
            // If the character does not have a child node, create one
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // Move to the child node for the next character
            node = node->get(word[i]);
            node->incrementCountPrefix(); // Increment prefix count
        }
        node->incrementEndsWith(); // Increment ends with count
    }

    // Counts the number of words equal to a given word
    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containKey(ch))
                return 0; // Return 0 if word not found
            node = node->get(ch);
        }
        return node->getEndsWith(); // Return count of words ending with the given word
    }

    // Counts the number of words starting with a given prefix
    int countWordsStartsWith(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containKey(ch))
                return 0; // Return 0 if prefix not found
            node = node->get(ch);
        }
        return node->getCountPrefix(); // Return count of words with the given prefix
    }

    // Erases a word from the Trie
    void erase(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containKey(ch))
                return; // Exit if word not found
            node = node->get(ch);
            node->decrementCountPrefix(); // Decrement prefix count
        }
        node->decrementEndsWith(); // Decrement ends with count
    }
};

int main()
{
    int n = 5;                                                      // Number of operations
    vector<int> type = {1, 1, 2, 3, 2};                             // Operation type (1: insert, 2: search, 3: startsWith)
    vector<string> value = {"hello", "help", "help", "hel", "hel"}; // Values for the operations
    Trie trie;                                                      // Create a Trie object

    // Perform the operations
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            trie.insert(value[i]); // Insert the value into the Trie
        }
        else if (type[i] == 2)
        {
            // Check if the value exists in the Trie and print the result
            if (trie.search(value[i]))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else
        {
            // Check if any word in the Trie starts with the given prefix and print the result
            if (trie.startsWith(value[i]))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }

    return 0;
}
