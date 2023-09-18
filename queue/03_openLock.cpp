#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> visited(deadends.begin(), deadends.end());
    if (visited.find("0000") != visited.end())
    {
        return -1;
    }
    if (target == "0000")
    {
        return 0;
    }
    queue<pair<string, int>> q;
    q.push({"0000", 0});
    visited.insert("0000");
    while (!q.empty())
    {
        pair<string, int> p = q.front();
        if (p.first == target)
        {
            return p.second;
        }
        q.pop();
        string state = p.first;
        for (int i = 0; i < 4; i++)
        {
            string nextState = state;
            nextState[i] = nextState[i] == '9' ? '0' : nextState[i] + 1;
            if (visited.find(nextState) == visited.end())
            {
                visited.insert(nextState);
                q.push({nextState, p.second + 1});
            }

            nextState = state;
            nextState[i] = nextState[i] == '0' ? '9' : nextState[i] - 1;
            if (visited.find(nextState) == visited.end())
            {
                visited.insert(nextState);
                q.push({nextState, p.second + 1});
            }
        }
    }
    return -1;
}

int main()
{
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    cout << openLock(deadends, "0202");
    return 0;
}