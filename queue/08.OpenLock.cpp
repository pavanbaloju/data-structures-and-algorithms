#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// Function to find the minimum number of moves to open the lock
int openLock(vector<string> &deadends, string target)
{
    // Create a set for deadends for quick lookup
    unordered_set<string> visited(deadends.begin(), deadends.end());

    // If the initial state "0000" is in deadends, return -1
    if (visited.find("0000") != visited.end())
    {
        return -1;
    }

    // If the target is the initial state, return 0 moves
    if (target == "0000")
    {
        return 0;
    }

    // Use a queue for BFS, storing pairs of (current state, number of moves)
    queue<pair<string, int>> q;
    q.push({"0000", 0});
    visited.insert("0000");

    while (!q.empty())
    {
        pair<string, int> p = q.front();
        q.pop();

        // If the current state matches the target, return the number of moves
        if (p.first == target)
        {
            return p.second;
        }

        string state = p.first;

        // Try all possible single wheel turns for each position
        for (int i = 0; i < 4; i++)
        {
            string nextState = state;

            // Turn the wheel forward by 1
            nextState[i] = nextState[i] == '9' ? '0' : nextState[i] + 1;
            if (visited.find(nextState) == visited.end())
            {
                visited.insert(nextState);
                q.push({nextState, p.second + 1});
            }

            // Turn the wheel backward by 1
            nextState = state;
            nextState[i] = nextState[i] == '0' ? '9' : nextState[i] - 1;
            if (visited.find(nextState) == visited.end())
            {
                visited.insert(nextState);
                q.push({nextState, p.second + 1});
            }
        }
    }

    // If no solution is found, return -1
    return -1;
}

int main()
{
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    int result = openLock(deadends, target);

    cout << "Minimum moves to open the lock: " << result << endl;

    return 0;
}
