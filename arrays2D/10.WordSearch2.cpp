#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a 2D board and a list of words from the dictionary, find all words in the board.
// Each word must be constructed from letters of sequentially adjacent cells, where "adjacent"
// cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// Intuition:
// We can solve this problem using a Trie data structure to efficiently search for words in the board.
// First, we insert all words from the dictionary into the Trie. Then, we perform a depth-first search
// (DFS) on the board, starting from each cell. During the DFS, we check if the current sequence of
// characters forms a word in the Trie. If it does, we add the word to the result. We mark visited
// cells to avoid revisiting them in the same word.

// DSA Strategy/Pattern: Trie, Depth-First Search (DFS)

// Approach:
// Explanation:
// 1. Define a TrieNode structure with links to child nodes, flags to mark the end of a word and visited nodes,
//    and a string to associate a word with the node.
// 2. Implement functions in the TrieNode class to insert words, search for words, and find words on the board.
// 3. Define a Solution class that encapsulates the Trie and the findWords function to search for words in the board.
// 4. Insert all words from the dictionary into the Trie.
// 5. Start DFS from each cell on the board and search for words using the Trie.
// 6. If a word is found during DFS, add it to the result.
// 7. Mark visited cells during DFS to avoid revisiting them in the same word.
// 8. Define the main function to create a sample input board and dictionary, and call the findWords function.
// 9. Print the found words.

// Time Complexity: O(m * n * 4^l), where m is the number of rows, n is the number of columns, and l is the length of the longest word.
//                  The DFS algorithm has a time complexity of O(4^l) for each cell on the board.
// Space Complexity: O(k * l), where k is the total number of characters in all words and l is the length of the longest word.
//                   The space complexity is mainly due to the Trie data structure used to store the dictionary.

// Trie Node structure
struct Node
{
    Node *links[26];      // Links to child nodes
    bool flag = false;    // Flag to mark end of a word
    bool visited = false; // Flag to mark if the node has been visited
    string word;          // Word associated with the node

    // Function to check if the node contains a key character
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // Function to insert a child node for a character
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // Function to get the child node for a character
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // Function to mark the node as the end of a word
    void setEnd()
    {
        flag = true;
    }

    // Function to check if the node marks the end of a word
    bool isEnd()
    {
        return flag;
    }

    // Function to check if the node has been visited
    bool isVisited()
    {
        return visited;
    }

    // Function to mark the node as visited
    void setVisited()
    {
        visited = true;
    }

    // Function to set the word associated with the node
    void setWord(string &word)
    {
        this->word = word;
    }
};

class Solution
{
private:
    Node *root; // Root node of the Trie

public:
    // Constructor to initialize the Trie
    Solution()
    {
        root = new Node();
    }

    // Function to insert a word into the Trie
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();      // Mark the last node as the end of the word
        node->setWord(word); // Associate the word with the last node
    }

    // Function to search for a word in the Trie
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd(); // Check if the last node marks the end of a word
    }

    // Function to find words in the board using the Trie
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        for (string word : words)
            insert(word); // Insert all words into the Trie

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                find(i, j, 0, board, root, ans); // Start finding words from each cell in the board
            }
        }
        return ans;
    }

    // Function to recursively find words starting from a given cell
    bool find(int br, int bc, int ind, vector<vector<char>> &board, Node *node, vector<string> &ans)
    {
        if (br < 0 || br >= board.size() || bc < 0 || bc >= board[0].size() || board[br][bc] == 'X')
            return false;

        char ch = board[br][bc];
        node = node->get(ch);
        if (node == nullptr)
            return false;

        if (node->isEnd() && !node->isVisited())
        {
            ans.push_back(node->word); // Add the found word to the answer
            node->setVisited();
        }

        bool exists = false;
        board[br][bc] = 'X';                                            // Mark the cell as visited
        exists = exists || find(br - 1, bc, ind + 1, board, node, ans); // Up
        exists = exists || find(br + 1, bc, ind + 1, board, node, ans); // Down
        exists = exists || find(br, bc - 1, ind + 1, board, node, ans); // Left
        exists = exists || find(br, bc + 1, ind + 1, board, node, ans); // Right
        board[br][bc] = ch;                                             // Restore the original character
        return exists;
    }
};

int main()
{
    vector<vector<char>> board{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words{"oath", "pea", "eat", "rain"};

    vector<string> ans = Solution().findWords(board, words);
    for (string s : ans)
        cout << s << endl; // Print the found words

    return 0;
}
