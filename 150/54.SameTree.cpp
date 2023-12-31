#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;
    return true;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!check(p, q))
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSameTreeIter(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!check(p, q))
        return false;

    queue<TreeNode *> pq, qq;
    pq.push(p);
    qq.push(q);

    while (!pq.empty())
    {
        TreeNode *pc = pq.front();
        pq.pop();
        TreeNode *qc = qq.front();
        qq.pop();

        if (!check(pc, qc))
            return false;

        if (pc)
        {
            pq.push(pc->left);
            qq.push(qc->left);

            pq.push(pc->right);
            qq.push(qc->right);
        }
    }
    return true;
}

int main()
{
    TreeNode *p = new TreeNode(5);
    p->left = new TreeNode(4);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(2);
    p->left->right = new TreeNode(1);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(7);

    TreeNode *q = new TreeNode(5);
    q->left = new TreeNode(4);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(2);
    q->left->right = new TreeNode(1);
    q->right->left = new TreeNode(6);
    q->right->right = new TreeNode(7);

    cout << isSameTree(p, q) << endl;
    cout << isSameTreeIter(p, q) << endl;
    return 0;
}