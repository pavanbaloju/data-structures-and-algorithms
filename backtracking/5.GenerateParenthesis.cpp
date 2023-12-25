#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> v)
{
    for (auto s : v)
        cout << " " << s << " ";
}

void solve(int left, int right, string s, vector<string> &res)
{
    if (left == 0 && right == 0)
    {
        res.push_back(s);
        return;
    }
    if (left > 0)
    {
        s.push_back('(');
        solve(left - 1, right, s, res);
        s.pop_back();
    }
    if (right > left)
    {
        s.push_back(')');
        solve(left, right - 1, s, res);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string s = "";
    solve(n, n, s, res);
    return res;
}

int main()
{
    vector<string> res = generateParenthesis(3);
    print(res);
    return 0;
}