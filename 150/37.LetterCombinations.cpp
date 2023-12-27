#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(vector<string> v)
{
    for (auto s : v)
        cout << s << " ";
}

void solve(int index, string &comb, vector<string> &ans, string digits, map<char, string> mapping)
{
    if (index == digits.size())
    {
        ans.push_back(comb);
        return;
    }

    for (char ch : mapping[digits[index]])
    {
        comb.push_back(ch);
        solve(index + 1, comb, ans, digits, mapping);
        comb.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        return {};
    }
    string comb;
    vector<string> ans;

    map<char, string> mapping = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    solve(0, comb, ans, digits, mapping);
    return ans;
}

int main()
{
    print(letterCombinations("236"));
    return 0;
}