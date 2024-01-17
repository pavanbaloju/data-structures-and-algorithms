#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class compare
{
public:
    bool operator()(vector<int> &v1, vector<int> &v2)
    {
        return (v1[0] + v1[1]) > (v2[0] + v2[1]);
    }
};
vector<vector<int>> kSmallestPairsBrute(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> pairs;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            pq.push({nums1[i], nums2[j]});
        }
    }
    while (!pq.empty() && k--)
    {
        pairs.push_back(pq.top());
        pq.pop();
    }
    return pairs;
}

class compare2
{
public:
    bool operator()(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] > v2[0];
    }
};

vector<vector<int>> kSmallestPairsOpt(vector<int> &nums1, vector<int> &nums2, int k)
{
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> pairs;
    priority_queue<vector<int>, vector<vector<int>>, compare2> pq;
    set<vector<int>> visited;
    pq.push({nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});

    while (k-- && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int i = top[1];
        int j = top[2];

        pairs.push_back({nums1[i], nums2[j]});

        if (i + 1 < m && visited.find({i + 1, j}) == visited.end())
        {
            pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            visited.insert({i + 1, j});
        }

        if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
        {
            pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }
    return pairs;
}

int main()
{
    vector<int> nums1({1, 1, 2}), nums2({1, 2, 3});
    vector<vector<int>> pairs = kSmallestPairsOpt(nums1, nums2, 3);

    for (auto pair : pairs)
        cout << pair[0] << "," << pair[1] << endl;
    return 0;
}