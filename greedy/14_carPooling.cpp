#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    vector<int> passChange = vector<int>(1001, 0);
    for (auto trip : trips)
    {
        passChange[trip[1]] += trip[0];
        passChange[trip[2]] -= trip[0];
    }

    int currPass = 0;
    for (int i = 0; i < 1001; i++)
    {
        currPass += passChange[i];
        if (currPass > capacity)
            return false;
    }
    return true;
}

bool sorter(vector<int> v1, vector<int> v2)
{
    if (v1[1] < v2[1] || (v1[1] == v2[1] && v1[2] < v2[2]))
        return true;
    return false;
}

bool carPooling2(vector<vector<int>> &trips, int capacity)
{
    int n = trips.size();
    sort(trips.begin(), trips.end(), sorter);

    int currPass = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top().first <= trips[i][1])
        {
            currPass -= pq.top().second;
            pq.pop();
        }

        // {end, passengers count)
        pq.push({trips[i][2], trips[i][0]});
        currPass += trips[i][0];

        if (currPass > capacity)
            return false;
    }

    return true;
}
int main()
{
    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    cout << carPooling(trips, 4);
    cout << carPooling2(trips, 4);
    return 0;
}