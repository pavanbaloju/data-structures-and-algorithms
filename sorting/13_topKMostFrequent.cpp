#include <vector>
#include <iostream>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end()) - min;

    vector<int> freq = vector<int>(max + 1);
    for (int num : nums)
    {
        freq[num - min]++;
    }

    int maxcount = *max_element(freq.begin(), freq.end());
    vector<vector<int>> buckets = vector<vector<int>>(maxcount + 1, vector<int>());
    for (int i = 0; i < freq.size(); i++)
    {
        buckets[freq[i]].push_back(i + min);
    }

    freq.clear();
    for (int i = buckets.size() - 1; i >= 0; i--)
    {
        for (int num : buckets[i])
        {
            freq.push_back(num);
            if (freq.size() == k)
            {
                return freq;
            }
        }
    }

    return freq;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 2, 3};
    vector<int> res = topKFrequent(nums, 2);
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}