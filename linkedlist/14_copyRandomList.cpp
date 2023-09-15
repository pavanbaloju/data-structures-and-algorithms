#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

struct Node
{
    int val;
    Node *next, *random;

    Node(int x)
    {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};
Node *copyRandomList2(Node *head)
{

    unordered_map<Node*, Node*> map;
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->val);
        map[temp] = newNode;
        temp = temp->next;
    }
    map[nullptr] = nullptr;
    temp = head;

    while (temp)
    {
        Node *copy = map[temp];
        copy->next = map[temp->next];
        copy->random = map[temp->random];
        temp = temp->next;
    }

    return map[head];
}

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    temp = head;
    while (temp)
    {
        temp->next->random = temp->random ? temp->random->next : nullptr;
        temp = temp->next->next;
    }

    Node *dummy = new Node(0), *tempNew = dummy;
    temp = head;
    while (temp)
    {
        Node *nxt = temp->next->next;
        tempNew->next = temp->next;
        tempNew = tempNew->next;

        temp->next = nxt;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->random = head;
    head->next->next = new Node(8);
    head->next->next->random = head->next;
    Node *res = copyRandomList(head);

    while (res && head)
    {
        cout << (res == head) << " ";
        res = res->next;
        head = head->next;
    }
    cout << endl;

    while (res )
    {
        cout << res->val << "&" << (res->random ? res->random->val: 0)<<" ";
        res = res->next;
        head = head->next;
    }
    cout << endl;
    return 0;
}