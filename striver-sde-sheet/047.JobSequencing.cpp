#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a list of jobs where each job has a deadline and a profit, 
// we need to maximize the total profit if only one job can be scheduled at a time.

// Intuition:
// Sort the jobs based on their profits in descending order.
// Iterate through the sorted jobs, and for each job, find the maximum available slot
// starting from its deadline, going backward. If a slot is available, assign the job to it.

// DSA Strategy:
// Sorting, Greedy

// Approach:
// 1. Sort the jobs based on their profits in descending order.
// 2. Initialize a vector 'slot' of size 'n' to keep track of the availability of slots.
// 3. Iterate through the sorted jobs.
//    a. For each job, starting from its deadline, find the maximum available slot going backward.
//    b. If a slot is available, assign the job to it, mark the slot as occupied, and add its profit to 'maxProfit'.
// 4. Return 'maxProfit'.

// Time Complexity: O(N^2), where N is the number of jobs.
// Space Complexity: O(N), where N is the number of jobs.

bool sorter(vector<int> &v1, vector<int> &v2)
{
    return v1[2] > v2[2]; // Sort based on profit in descending order.
}

int maxProfit(vector<vector<int>> &jobs)
{
    int maxProfit = 0;
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), sorter); // Sort the jobs based on profit.
    vector<bool> slot = vector<bool>(n); // Initialize a vector to keep track of slot availability.

    for (int i = 0; i < jobs.size(); i++)
    {
        int j = min(jobs[i][1], n) - 1; // Start from the deadline of the current job.
        while (j >= 0)
        {
            if (!slot[j]) // If the slot is available.
            {
                slot[j] = true; // Mark the slot as occupied.
                maxProfit += jobs[i][2]; // Add the profit of the current job.
                break; // Exit the loop.
            }
            j--; // Move to the previous slot.
        }
    }

    return maxProfit; // Return the maximum profit.
}

void print(vector<vector<int>> &jobs)
{
    for (auto job : jobs)
    {
        for (auto n : job)
            cout << n << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> jobs = {
        {0, 2, 100},
        {1, 1, 19},
        {2, 2, 27},
        {3, 1, 25},
        {4, 3, 15}};

    cout << maxProfit(jobs) << endl;
    return 0;
}
