#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto n : row)
            cout << n << " ";
        cout << endl;
    }
}

void solve(int s, int n, int k, vector<int> &choose, vector<vector<int>> &ans)
{
    if (k == choose.size())
    {
        ans.push_back(vector<int>(choose));
        return;
    }

    for (int i = s; i <= n; i++)
    {
        choose.push_back(i);
        solve(i+1, n, k, choose, ans);
        choose.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> choose;
    solve(1, n, k, choose, ans);
    return ans;
}

int main()
{
    vector<vector<int>> ans = combine(4, 2);
    print(ans);
    return 0;
}