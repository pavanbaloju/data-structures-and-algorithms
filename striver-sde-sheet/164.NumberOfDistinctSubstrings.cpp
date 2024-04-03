#include <iostream>

using namespace std;

struct Node
{
    Node *links[26];

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
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
    int insert(int index, string word)
    {
        Node *node = root; // Initialize node to root
        int count = 0;
        for (int j = index; j < word.size(); j++)
        {
            // If the character does not have a child node, create one
            char ch = word[j];
            if (!node->containsKey(ch))
            {
                count++;
                node->put(ch, new Node());
            }
            // Move to the child node for the next character
            node = node->get(ch);
        }
        return count;
    }
};

int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int count = 0;
    int n = s.size();

    Trie trie;
    int distinct = 0;
    for (int i = 0; i < n; i++)
    {
        distinct += trie.insert(i, s);
    }
    return distinct + 1;
}

int main()
{
    string s1 = "ababa";
    cout << "Total number of distinct substrings : " << countDistinctSubstrings(s1);
    cout << "\n";

    string s2 = "ccfdf";
    cout << "Total number of distinct substrings : " << countDistinctSubstrings(s2);

    return 0;
}