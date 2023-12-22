#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> nums)
{
    for (vector<int> v : nums)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}
// brute force approach with 3 loops is not great

// -4, -1, -1, 0, 1, 2

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;
        int target = -nums[i];

        while (left < right)
        {
            if (nums[left] + nums[right] == target)
            {
                res.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (nums[left] + nums[right] < target)
                left++;

            else
                right--;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = vector<int>({-1, 0, 1, 2, -1, -4});
    vector<vector<int>> res = threeSum(nums);
    print(res);
}