#include <iostream>
#include <vector>
using namespace std;

// brute force: try all
bool canComplete(vector<int> &gas, vector<int> &cost, int start)
{
    cout << endl;
    int currentGas = gas[start];
    int next;
    for (next = (start + 1) % gas.size(); next != start; next = (next + 1) % gas.size())
    {
        // cout << start << " -> " << next << " : " << currentGas << " - " << cost[(next - 1 + gas.size()) % gas.size()] << " + " << gas[next] << endl;
        currentGas -= cost[(next - 1 + gas.size()) % gas.size()];
        if (currentGas < 0)
            return false;
        currentGas += gas[next];
    }
    if (currentGas < cost[(next - 1 + gas.size()) % gas.size()])
        return false;

    return true;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    for (int start = 0; start < gas.size(); start++)
    {
        if (canComplete(gas, cost, start))
            return start;
    }
    return -1;
}

int canCompleteCircuitOpt(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0, totalCost = 0,total = 0, start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];

        total += gas[i] - cost[i];
        if (total < 0)
        {
            total = 0;
            start = i + 1;
        }
    }
    if (totalGas < totalCost)
        return -1;

    return start;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    // cout << canCompleteCircuit(gas, cost) << endl;
    cout << canCompleteCircuitOpt(gas, cost) << endl;
    return 0;
}