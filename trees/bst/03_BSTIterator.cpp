#include <iostream>
#include <vector>
#include <stack>
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

class BSTIterator
{
private:
    stack<TreeNode *> st;

    void pushValues(TreeNode *root)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushValues(root);
    }

    int next()
    {
        TreeNode *out = st.top();
        st.pop();
        pushValues(out->right);
        return out->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    BSTIterator bSTIterator = BSTIterator(root);
    cout << bSTIterator.next() << endl;    // return 3
    cout << bSTIterator.next() << endl;    // return 7
    cout << bSTIterator.hasNext() << endl; // return True
    cout << bSTIterator.next() << endl;    // return 9
    cout << bSTIterator.hasNext() << endl; // return True
    cout << bSTIterator.next() << endl;    // return 15
    cout << bSTIterator.hasNext() << endl; // return True
    cout << bSTIterator.next() << endl;    // return 20
    cout << bSTIterator.hasNext() << endl; // return False
    return 0;
}