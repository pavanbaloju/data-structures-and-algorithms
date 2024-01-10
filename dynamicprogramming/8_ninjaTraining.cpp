#include <iostream>
#include <vector>
using namespace std;

// recursion
int solve(int day, int lastIdx, vector<vector<int>> points)
{
    int maxp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != lastIdx)
        {
            int todayPoints = points[day][i];
            if (day > 0)
                todayPoints += solve(day - 1, i, points);
            maxp = max(maxp, todayPoints);
        }
    }
    return maxp;
}

int ninjaTraining(vector<vector<int>> points)
{
    return solve(points.size() - 1, 3, points);
}

// recursion + memoization
int solveMemo(int day, int lastIdx, vector<vector<int>> points, vector<vector<int>> &dp)
{
    if (dp[day][lastIdx] != -1)
        return dp[day][lastIdx];

    int maxp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != lastIdx)
        {
            int todayPoints = points[day][i];
            if (day > 0)
                todayPoints += solveMemo(day - 1, i, points, dp);
            maxp = max(maxp, todayPoints);
        }
    }
    return dp[day][lastIdx] = maxp;
}

int ninjaTrainingMemo(vector<vector<int>> points)
{
    vector<vector<int>> dp = vector<vector<int>>(points.size(), vector<int>(4, -1));
    return solveMemo(points.size() - 1, 3, points, dp);
}

// tabulation
int solveTable(vector<vector<int>> points, vector<vector<int>> &dp)
{
    int n = points.size();
    for (int day = 0; day < n; day++)
    {
        for (int lastIdx = 0; lastIdx < 4; lastIdx++)
        {
            int maxp = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != lastIdx)
                {
                    int todayPoints = points[day][task];
                    if (day > 0)
                        todayPoints += dp[day - 1][task];
                    maxp = max(maxp, todayPoints);
                }
            }
            dp[day][lastIdx] = maxp;
        }
    }

    return dp[n - 1][3];
}

int ninjaTrainingTable(vector<vector<int>> points)
{
    vector<vector<int>> dp = vector<vector<int>>(points.size(), vector<int>(4, -1));
    return solveTable(points, dp);
}

// space opt
int ninjaTrainingOpt(vector<vector<int>> points)
{
    int n = points.size();
    vector<int> prevDay = vector<int>(4, 0);
    for (int day = 0; day < n; day++)
    {
        vector<int> curr = vector<int>(4, -1);
        for (int lastIdx = 0; lastIdx < 4; lastIdx++)
        {
            int maxp = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != lastIdx)
                {
                    int todayPoints = points[day][task] + prevDay[task];
                    maxp = max(maxp, todayPoints);
                }
            }
            curr[lastIdx] = maxp;
        }
        prevDay = curr;
    }

    return prevDay[3];
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    cout << ninjaTraining(points) << endl;
    cout << ninjaTrainingMemo(points) << endl;
    cout << ninjaTrainingTable(points) << endl;
    cout << ninjaTrainingOpt(points) << endl;
}