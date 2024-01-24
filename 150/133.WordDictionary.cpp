#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    vector<TrieNode *> nodes;
    bool flag;

    TrieNode()
    {
        nodes = vector<TrieNode *>(26, nullptr);
        flag = false;
    }

    bool containsKey(char ch)
    {
        return nodes[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode *node)
    {
        nodes[ch - 'a'] = node;
    }

    TrieNode *get(char ch)
    {
        return nodes[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool searchHelper(string word, TrieNode *node, int ind)
    {
        if (ind == word.size())
            return node->isEnd();

        char ch = word[ind];
        if (ch == '.')
        {
            for (auto n : node->nodes)
                if (n && searchHelper(word, n, ind + 1))
                    return true;
            return false;
        }
        if (!node->containsKey(ch))
            return false;

        return searchHelper(word, node->get(ch), ind + 1);
    }

    bool search(string word)
    {
        return searchHelper(word, root, 0);
    }
};

int main()
{

    WordDictionary obj = WordDictionary();
    obj.addWord("word");
    cout << obj.search("wo.d") << endl;
}