#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement a Trie (prefix tree) data structure that supports the following operations:
// 1. Insert a word into the Trie.
// 2. Search for a word in the Trie.
// 3. Check if any word in the Trie starts with a given prefix.

// Intuition:
// A Trie is a tree-like data structure used for efficient retrieval of strings. Each node of the Trie represents a single character of the string.
// The Trie allows for quick search, insertion, and prefix search operations. It is commonly used in text processing applications.

// DSA Strategy/Pattern:
// Trie Data Structure

// Approach:
// Trie Implementation:
// 1. Define a Node structure representing each node in the Trie. Each node contains an array of links to child nodes (26 for lowercase English letters) and a boolean flag indicating if the node represents the end of a word.
// 2. Implement methods within the Node structure to perform Trie operations:
//    - containKey(char ch): Check if a child node exists for the given character.
//    - put(char ch, Node* node): Create a link to the given node for the specified character.
//    - get(char ch): Retrieve the child node corresponding to the given character.
//    - setEnd(): Mark the current node as the end of a word.
//    - isEnd(): Check if the current node represents the end of a word.
// 3. Define a Trie class encapsulating the Trie operations:
//    - insert(string word): Insert a word into the Trie by iterating over its characters and creating nodes as necessary.
//    - search(string word): Search for a word in the Trie by traversing the nodes based on the characters of the word.
//    - startsWith(string prefix): Check if the Trie contains words with a given prefix by traversing the nodes based on the characters of the prefix.
// 4. Perform the specified operations (insert, search, startsWith) on the Trie based on the provided input.

// Time Complexity:
// - Insertion: O(m), where m is the length of the inserted word.
// - Search: O(m), where m is the length of the searched word.
// - Prefix Search (startsWith): O(p), where p is the length of the prefix.
// Space Complexity: O(N * M), where N is the number of inserted words and M is the average length of the words.

// Node structure for the Trie
struct Node
{
    Node *links[26];   // Array of links to child nodes
    bool flag = false; // Flag indicating if the node represents the end of a word

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

    // Marks the current node as the end of a word
    void setEnd()
    {
        flag = true;
    }

    // Checks if the current node represents the end of a word
    bool isEnd()
    {
        return flag;
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
        }
        // Mark the last node as the end of the word
        node->setEnd();
    }

    // Searches for a word in the Trie
    bool search(string word)
    {
        Node *node = root; // Initialize node to root
        for (int i = 0; i < word.size(); i++)
        {
            // If the character does not have a child node, the word does not exist
            if (!node->containKey(word[i]))
            {
                return false;
            }
            // Move to the child node for the next character
            node = node->get(word[i]);
        }
        // Check if the last node represents the end of a word
        return node->isEnd();
    }

    // Checks if the Trie contains words with a given prefix
    bool startsWith(string prefix)
    {
        Node *node = root; // Initialize node to root
        for (int i = 0; i < prefix.size(); i++)
        {
            // If the character does not have a child node, the prefix does not exist
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            // Move to the child node for the next character
            node = node->get(prefix[i]);
        }
        return true;
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
