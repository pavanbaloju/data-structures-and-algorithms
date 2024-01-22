#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// using hashMap
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        hashMap[nums[i]]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (hashMap[nums[i]] == 1)
        {
            return nums[i];
        }
    }
    return -1;
}
int singleNumber2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 2)
    {
        if (nums[i] != nums[i - 1])
            return nums[i - 1];
    }
    return nums[nums.size() - 1];
}
int singleNumber3(vector<int> &nums)
{
    int ans = 0;
    for (auto x : nums)
        ans ^= x;
    return ans;
}
int main()
{
    vector<int> nums = {2, 1, 3, 1, 3};
    cout << singleNumber3(nums);
}