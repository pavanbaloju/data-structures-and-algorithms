#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> projectsQ;
    for (int i = 0; i < profits.size(); i++)
        projectsQ.push({capital[i], profits[i]});

    priority_queue<int> profitsQ;
    while (k--)
    {
        while (!projectsQ.empty() && projectsQ.top().first <= w)
        {
            profitsQ.push(projectsQ.top().second);
            projectsQ.pop();
        }
        if (profitsQ.empty())
        {
            break;
        }
        w += profitsQ.top();
        profitsQ.pop();
    }

    return w;
}

int findMaximizedCapitalOpt(int k, int w, vector<int> &profits, vector<int> &capital)
{
    vector<pair<int, int>> projects;
    int n = profits.size();
    for (int i = 0; i < n; i++)
        projects.push_back({capital[i], profits[i]});

    sort(projects.begin(), projects.end());

    int ind = 0;
    priority_queue<int> profitsQ;
    while (k--)
    {
        while (ind < n && projects[ind].first <= w)
        {
            profitsQ.push(projects[ind++].second);
        }
        if (profitsQ.empty())
        {
            break;
        }
        w += profitsQ.top();
        profitsQ.pop();
    }

    return w;
}

int main()
{

    vector<int> profits{1, 2, 3}, capital{0, 1, 1};
    int k = 2, w = 0;
    // vector<int> profits{1, 2, 3}, capital{1, 1, 2};
    // int k = 1, w = 0;
    cout << findMaximizedCapital(k, w, profits, capital) << endl;
    cout << findMaximizedCapitalOpt(k, w, profits, capital) << endl;
    return 0;
}