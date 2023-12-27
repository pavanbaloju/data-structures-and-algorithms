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
void solve(vector<int> &nums, vector<int> &permn, vector<vector<int>> &permns)
{
    if (permn.size() == nums.size())
    {
        permns.push_back(permn);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (find(permn.begin(), permn.end(), nums[i]) == permn.end())
        {
            permn.push_back(nums[i]);
            solve(nums, permn, permns);
            permn.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> permn;
    vector<vector<int>> permns;
    solve(nums, permn, permns);
    return permns;
}

// swapping instead of extra space
void solve(int ind, int n, vector<int> &nums, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        swap(nums[i], nums[ind]);
        solve(ind + 1, n, nums, ans);
        swap(nums[i], nums[ind]);
    }
}
vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    solve(0, n, nums, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    print(ans);
    cout << endl;
    vector<vector<int>> ans2 = permute(nums);
    print(ans2);
    return 0;
}