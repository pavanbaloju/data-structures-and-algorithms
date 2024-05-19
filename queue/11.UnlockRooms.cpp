#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to determine if all rooms can be visited
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    queue<int> q;                               // Queue to hold the rooms to be visited
    vector<bool> unlocked(rooms.size(), false); // Vector to keep track of unlocked rooms
    unlocked[0] = true;                         // Initially, room 0 is unlocked
    q.push(0);                                  // Start from room 0

    // BFS to visit all rooms that can be reached
    while (!q.empty())
    {
        int room = q.front();
        q.pop();

        // Visit all the keys in the current room
        for (int r : rooms[room])
        {
            if (!unlocked[r])
            {
                unlocked[r] = true; // Mark the room as unlocked
                q.push(r);          // Add the room to the queue
            }
        }
    }

    // Check if all rooms are unlocked
    for (int i = 0; i < unlocked.size(); i++)
    {
        if (!unlocked[i])
        {
            return false; // If any room is still locked, return false
        }
    }
    return true; // All rooms are unlocked
}

int main()
{
    // Example rooms setup
    vector<vector<int>> rooms = {
        {1, 3},    // Room 0 has keys to room 1 and room 3
        {3, 2, 1}, // Room 1 has keys to room 3, room 2, and room 1
        {2},       // Room 2 has a key to room 2 (itself)
        {0}        // Room 3 has a key to room 0
    };

    // Output if all rooms can be visited
    cout << (canVisitAllRooms(rooms) ? "All rooms can be visited." : "Not all rooms can be visited.") << endl;
    return 0;
}
