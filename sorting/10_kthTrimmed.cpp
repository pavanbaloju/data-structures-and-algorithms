#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//tle
void countingSort(vector<pair<string, int>> &nums, int place)
{
    int k = 10;
    vector<int> counts = vector<int>(k);
    for (auto num : nums)
    {
        counts[(num.first[place] - '0') % k] += 1;
    }

    int startIndex = 0;
    for (int i = 0; i < k; i++)
    {
        int c = counts[i];
        counts[i] = startIndex;
        startIndex += c;
    }

    vector<pair<string, int>> sorted = vector<pair<string, int>>(nums.size());
    for (auto num : nums)
    {
        sorted[counts[(num.first[place] - '0') % k]] = num;
        counts[(num.first[place] - '0') % k]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = sorted[i];
    }
}
void radixSort(vector<pair<string, int>> &nums)
{
    pair<string, int> maxElem = *max_element(nums.begin(), nums.end());
    int place = maxElem.first.size()-1;
    while (place >= 0)
    {
        countingSort(nums, place);
        place--;
    }
}

vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
{
    vector<int> res;
    for (auto v : queries)
    {
        vector<pair<string, int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push_back({(nums[i].substr(nums[i].size() - v[1])), i});
        }
        radixSort(pq);
        res.push_back(pq[v[0] - 1].second);
    }
    return res;
}

int main()
{
    vector<string> nums = {"102", "473", "251", "814"};
    vector<vector<int>> queries = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    vector<int> res = smallestTrimmedNumbers(nums, queries);
    for (int x : res)
        cout << x << " ";
    return 0;
}