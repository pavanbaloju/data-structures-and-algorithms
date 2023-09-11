#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
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
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = twoSum(nums, 9);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}