#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &jobs)
{
    for (auto job : jobs)
    {
        for (auto n : job)
            cout << n << " ";
        cout << endl;
    }
}

bool sorter(vector<int> &v1, vector<int> &v2)
{
    return v1[2] > v2[2];
}

// O(N^2), O(N)
int maxProfit(vector<vector<int>> &jobs)
{
    int maxProfit = 0;
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), sorter);
    vector<bool> slot = vector<bool>(n);

    for (int i = 0; i < jobs.size(); i++)
    {
        int j = min(jobs[i][1], n) - 1;
        while (j >= 0)
        {
            if (!slot[j])
            {
                slot[j] = true;
                maxProfit += jobs[i][2];
                cout << jobs[i][0] << endl;
                break;
            }
            j--;
        }
    }

    return maxProfit;
}

int main()
{
    // job, deadline, profit
    vector<vector<int>> jobs = {
        {0, 2, 100},
        {1, 1, 19},
        {2, 2, 27},
        {3, 1, 25},
        {4, 3, 15}};

    cout << maxProfit(jobs) << endl;
    return 0;
}