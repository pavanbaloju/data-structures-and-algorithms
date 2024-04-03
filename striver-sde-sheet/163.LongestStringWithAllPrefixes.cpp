#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a list of words, find the longest word such that all its prefixes are also present in the list.

// Intuition:
// We can use a Trie data structure to efficiently store the list of words and check if all prefixes of a word exist in the Trie.

// DSA Strategy/Pattern:
// Trie, String Manipulation

// Approach:
// 1. Create a Trie data structure to store the list of words.
// 2. Insert all the words into the Trie.
// 3. For each word in the list, check if all its prefixes exist in the Trie.
// 4. If a word has all its prefixes present in the Trie, update the longest word found so far.
// 5. Return the longest word found, or "NONE" if no such word exists.

// Time Complexity: O(N * M), where N is the number of words and M is the average length of a word
// Space Complexity: O(N * M)

// Node structure for the Trie
struct Node
{
    Node *links[26];  // Array of links to child nodes
    bool end = false; // Indicates if the node marks the end of a word

    // Checks if a child node exists for the given character
    bool contains(char ch)
    {
        return links[ch - 'a'] != nullptr;
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

    // Marks the node as the end of a word
    void setEnd()
    {
        end = true;
    }

    // Checks if the node marks the end of a word
    bool isEnd()
    {
        return end;
    }
};

// Trie class
class Trie
{
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
        for (char ch : word)
        {
            // If the character does not have a child node, create one
            if (!node->contains(ch))
            {
                node->put(ch, new Node());
            }
            // Move to the child node for the next character
            node = node->get(ch);
        }
        node->setEnd(); // Mark the last node as the end of the word
    }

    // Checks if all prefixes of a word exist in the Trie
    bool checkIfPrefixesExist(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            // If the character does not exist in the Trie, return false
            if (!node->contains(ch))
                return false;

            node = node->get(ch);
            // If the current node does not mark the end of a word, return false
            if (!node->isEnd())
                return false;
        }
        return true; // All prefixes exist in the Trie
    }
};

// Function to find the longest word with all its prefixes present in the given list of words
string longestString(vector<string> words)
{
    Trie trie; // Initialize Trie
    // Insert all words into the Trie
    for (string word : words)
        trie.insert(word);

    string longest = ""; // Initialize longest word found so far

    // Iterate over each word
    for (string word : words)
    {
        // Check if all prefixes of the word exist in the Trie
        if (trie.checkIfPrefixesExist(word))
        {
            // Update the longest word if the current word is longer
            if (word.length() > longest.length())
            {
                longest = word;
            }
            // If the lengths are equal, choose lexicographically smaller word
            else if (word.length() == longest.length() && word < longest)
            {
                longest = word;
            }
        }
    }
    // Return the longest word found, or "NONE" if no such word exists
    return longest.empty() ? "NONE" : longest;
}

int main()
{
    int n = 5;                                                                      // Number of words in the list
    vector<string> words = {"n", "ninja", "ni", "nin", "ninga", "ninj"}; // List of words

    // Find the longest word with all its prefixes present using the Trie approach
    string longestWord = longestString(words);

    // Print the longest word found
    cout << "Longest word with all its prefixes present: " << longestWord << endl;
    return 0;
}