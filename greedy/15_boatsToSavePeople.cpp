#include <iostream>
#include <vector>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int light = 0, heavy = people.size() - 1, boats = 0;

    while (light <= heavy)
    {
        if (people[light] + people[heavy] <= limit)
        {
            light++;
        }
        heavy--;
        boats++;
    }

    return boats;
}

int main()
{
    vector<int> people = {3, 5, 3, 4};
    cout << numRescueBoats(people, 5);
    return 0;
}