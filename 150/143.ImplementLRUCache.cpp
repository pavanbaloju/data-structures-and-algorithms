#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    struct Node
    {
        int key, val;
        Node *next, *prev;
        Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
        Node(int key, int val, Node *next, Node *prev) : key(key), val(val), next(next), prev(prev) {}
    };

    unordered_map<int, Node *> map;
    Node *head = new Node(), *tail = new Node();
    int cap = 0;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newnode)
    {
        Node *nxt = head->next;

        newnode->next = nxt;
        newnode->prev = head;

        head->next = newnode;
        nxt->prev = newnode;
    }

    void deleteNode(Node *delnode)
    {
        Node *pre = delnode->prev;
        Node *nxt = delnode->next;

        pre->next = nxt;
        nxt->prev = pre;
        delete delnode;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            Node *curr = map[key];
            deleteFromMap(key);
            deleteNode(curr);
        }

        if (map.size() == cap)
        {
            deleteFromMap(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        insertInMap(key, head->next);
    }

    void deleteFromMap(int key)
    {
        map.erase(key);
    }

    void insertInMap(int key, Node *node)
    {
        map[key] = node;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *resNode = map[key];
            int ans = resNode->val;

            deleteNode(resNode);
            deleteFromMap(key);

            addNode(resNode);
            insertInMap(key, head->next);
            return ans;
        }
        return -1;
    }
};