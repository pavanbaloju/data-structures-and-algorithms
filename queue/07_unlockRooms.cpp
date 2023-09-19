#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    queue<int> q;
    vector<bool> unlocked(rooms.size(), false);
    unlocked[0] = true;
    q.push(0);

    while (!q.empty())
    {
        int room = q.front();
        q.pop();

        for (int r:rooms[room])
        {
            if (!unlocked[r])
            {
                unlocked[r] = true;
                q.push(r);
            }
        }
    }
    for (int i = 0; i < unlocked.size(); i++)
    {
        if (!unlocked[i])
        {
            return false;
        }
        
    }
    return true;
}

int main()
{
    vector<vector<int>> rooms = {
        {1, 3},
        {3, 2, 1},
        {2},
        {0}};

    cout << canVisitAllRooms(rooms);
    return 0;
}