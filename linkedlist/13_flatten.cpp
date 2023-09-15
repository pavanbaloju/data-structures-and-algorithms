#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *prev, *next, *child;

    Node(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

Node *flatten(Node *head)
{
    if (!head || (!head->child && !head->next))
    {
        return head;
    }
    
    Node *temp = head;
    while (temp)
    {
        if (temp->child)
        {
            Node *nxt = temp->next;
            Node *child = temp->child;

            temp->child = nullptr;
            temp->next = child;
            child->prev = temp;

            while (child->next)
                child = child->next;
            if (nxt)
            {
                child->next = nxt;
                nxt->prev = child;
            }
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *headA = new Node(2);
    headA->next = new Node(4);
    headA->next->prev = headA;
    headA->next->child = new Node(8);
    headA->next->next = new Node(6);
    headA->next->next->prev = headA->next;
    headA->next->next->next = new Node(9);
    headA->next->next->next->prev = headA->next->next;

    Node *res = flatten(headA);

    cout << endl;
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}