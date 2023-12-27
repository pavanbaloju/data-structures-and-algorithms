#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &ans)
{
    for (auto row : ans)
    {
        for (auto n : row)
            cout << n << " ";
        cout << endl;
    }
}

void solve(int index, vector<int> &nums, vector<int> &comb, vector<vector<int>> &ans, int target)
{
    if (target < 0 || index == nums.size())
        return;

    if (target == 0)
    {
        ans.push_back(comb);
        return;
    }

    comb.push_back(nums[index]);
    solve(index, nums, comb, ans, target - nums[index]);
    comb.pop_back();
    solve(index + 1, nums, comb, ans, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> comb;
    solve(0, candidates, comb, ans, target);
    return ans;
}

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    vector<vector<int>> ans = combinationSum(nums, 7);
    print(ans);
    return 0;
}