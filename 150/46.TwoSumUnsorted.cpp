#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumHashing(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = map.find(target - nums[i]);
        if (it != map.end())
            return {it->second, i};
        map[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    vector<int> v = twoSumHashing(arr, 9);
    cout << v[0] << " " << v[1] << endl;
}