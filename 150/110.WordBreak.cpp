#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// bfs
bool wordBreak(string word, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = word.size();

    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (front == n)
            return true;

        for (int ind = front + 1; ind <= n; ind++)
        {
            string next = word.substr(front, ind - front);
            if (wordSet.find(next) != wordSet.end())
            {
                if (!visited[ind])
                {
                    q.push(ind);
                    visited[ind] = true;
                }
            }
        }
    }
    return false;
}

// dfs + memo
bool solve(int ind, string &s, vector<string> &words, vector<int> &dp)
{
    if (ind < 0)
        return true;

    if (dp[ind] != -1)
        return dp[ind];

    for (auto word : words)
    {
        int j = word.size();
        if (ind - j + 1 < 0)
            continue;

        if (s.substr(ind - j + 1, j) == word and solve(ind - j, s, words, dp))
        {
            return dp[ind] = true;
        }
    }
    return dp[ind] = false;
}

bool wordBreak2(string s, vector<string> &arr)
{
    vector<int> dp(s.size(), -1);
    return solve(s.size() - 1, s, arr, dp);
}

int main()
{
    vector<string> dict = {"apple", "pen"};
    string word = "applepenapple";
    cout << wordBreak(word, dict);
    cout << wordBreak2(word, dict);
}