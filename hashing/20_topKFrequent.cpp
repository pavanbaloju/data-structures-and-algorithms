#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    vector<vector<int>> values(nums.size()+1);
    vector<int> res;
    for (int num : nums)
    {
        ++freq[num];
    }
    for (auto it : freq)
    {
        values[it.second].push_back(it.first);
    }
    for (int i = values.size() - 1 ; i >= 0; i--)
    {
        for (int num:values[i])
        {
            res.push_back(num);
            if (res.size() == k)
            {
                return res;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = topKFrequent(nums, 2);
    for (int n : res)
        cout << n <<" ";
    return 0;
}