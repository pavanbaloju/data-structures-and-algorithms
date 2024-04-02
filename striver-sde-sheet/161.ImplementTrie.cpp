#include <iostream>
using namespace std;

struct Node
{
    Node *links[26];
    bool end = false;

    bool contains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        end = true;
    }

    bool isEnd()
    {
        return end;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->contains(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->contains(ch))
                return false;

            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->contains(ch))
                return false;

            node = node->get(ch);
        }
        return true;
    }
};

int main()
{
    Trie trie = Trie();
    trie.insert("app");
    trie.insert("apps");
    cout << trie.search("app") << endl;
    cout << trie.startsWith("ap") << endl;
    return 0;
}