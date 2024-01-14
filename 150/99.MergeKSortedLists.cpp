#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    if (l1->val < l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

ListNode *partition(vector<ListNode *> lists, int start, int end)
{
    if (start == end)
        return lists[start];

    if (start < end)
    {

        int mid = start + (end - start) / 2;

        ListNode *l1 = partition(lists, start, mid);
        ListNode *l2 = partition(lists, mid + 1, end);

        return merge(l1, l2);
    }
    else
        return nullptr;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return partition(lists, 0, lists.size() - 1);
}

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val;}
};
ListNode *mergeKListsOpt(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
        {
            pq.push(lists[i]);
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    while (!pq.empty())
    {
        ListNode *topNode = pq.top();
        pq.pop();

        if (topNode->next)
        {
            pq.push(topNode->next);
        }

        temp->next = topNode;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(5);

    ListNode *headB = new ListNode(7);
    headB->next = new ListNode(8);
    headB->next->next = new ListNode(9);

    ListNode *headC = new ListNode(10);
    headC->next = new ListNode(13);
    headC->next->next = new ListNode(24);

    vector<ListNode *> lists = vector<ListNode *>({headA, headB, headC});

    // ListNode *res = mergeKLists(lists);
    // while (res)
    // {
    //     cout << res->val << " ";
    //     res = res->next;
    // }
    // cout << endl;

    ListNode *res = mergeKListsOpt(lists);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}