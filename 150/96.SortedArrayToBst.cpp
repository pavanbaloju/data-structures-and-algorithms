#include <iostream>
#include <vector>
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

void inOrder(TreeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout<< root->val <<" ";
    inOrder(root->right);
}

TreeNode *solve(int left, int right, vector<int> &nums, vector<int> &ans)
{
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = solve(left, mid - 1, nums, ans);
    root->right = solve(mid + 1, right, nums, ans);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    vector<int> ans;
    return solve(0, nums.size() - 1, nums, ans);
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    inOrder(sortedArrayToBST(nums));
    return 0;
}