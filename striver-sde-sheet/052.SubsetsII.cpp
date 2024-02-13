#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(int ind, int n, vector<int> &nums, vector<int> &curr, set<vector<int>> &unique)
{
    if (ind == n)
    {
        unique.insert(curr);
        return;
    }

    solve(ind + 1, n, nums, curr, unique);

    curr.push_back(nums[ind]);
    solve(ind + 1, n, nums, curr, unique);
    curr.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> unique;
    vector<int> curr;
    int n = nums.size();
    solve(0, n, nums, curr, unique);

    vector<vector<int>> res;
    for (auto v : unique)
    {
        res.push_back(v);
    }
    return res;
}

void print(vector<vector<int>> vectors)
{
    for (auto v : vectors)
    {
        cout << "[";
        for (int i = 0; i < v.size(); ++i)
        {
            cout << " " << v[i] << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    vector<int> nums{3, 1, 2, 2};
    vector<vector<int>> res = subsets(nums);
    print(res);
    return 0;
}
